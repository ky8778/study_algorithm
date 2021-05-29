import sys
sys.stdin = open('input.txt', 'r')


''' 첫번째 풀이
=> dist 만드는 데에서 시간초과 (2중 for loop)
def CanBuild(N, C, home, min_dist):
    cnt = 1
    tmp_dist = 0
    for i in range(1, N):
        tmp_dist += (home[i]-home[i-1])
        if tmp_dist >= min_dist:
            tmp_dist = 0
            cnt += 1
    if cnt >= C:
        return True
    else:
        return False

def solution(N, C, home):
    ret = None
    home.sort()
    dist = []
    for i in range(N):
        for j in range(i+1, N):
            if home[j]-home[i] not in dist:
                dist.append(home[j]-home[i])
    dist.sort()
    # Binary Search
    start = 0
    end = len(dist) - 1
    
    if CanBuild(N, C, home, dist[end]):           # OOOOOOO....OOOOO 인 경우
        return dist[end]

    while start + 1 < end:
        mid = (start + end) // 2
        if CanBuild(N, C, home, dist[mid]):
            start = mid
        else:
            end = mid

    return dist[start]

N, C = map(int, input().split())
home = [int(input()) for _ in range(N)]

print(solution(N, C, home))
'''

''' 두번째풀이
=> dist 배열 만드는 데 메모리초과
def CanBuild(N, C, home, min_dist):
    cnt = 1
    tmp_dist = 0
    for i in range(1, N):
        tmp_dist += (home[i]-home[i-1])
        if tmp_dist >= min_dist:
            tmp_dist = 0
            cnt += 1
    if cnt >= C:
        return True
    else:
        return False

def solution(N, C, home):
    ret = None
    home.sort()
    dist = [n for n in range(1, home[-1]-home[0])]

    # Binary Search
    start = 0
    end = len(dist) - 1
    
    if CanBuild(N, C, home, dist[end]):           # OOOOOOO....OOOOO 인 경우
        return dist[end]

    while start + 1 < end:
        mid = (start + end) // 2
        if CanBuild(N, C, home, dist[mid]):
            start = mid
        else:
            end = mid

    return dist[start]

N, C = map(int, input().split())
home = [int(input()) for _ in range(N)]

print(solution(N, C, home))
'''

def CanBuild(N, C, home, min_dist):
    cnt = 1
    tmp_dist = 0
    for i in range(1, N):
        tmp_dist += (home[i]-home[i-1])
        if tmp_dist >= min_dist:
            tmp_dist = 0
            cnt += 1
    if cnt >= C:
        return True
    else:
        return False

def solution(N, C, home):
    # Binary Search
    start = 1

    end = home[-1] - home[0]
    if CanBuild(N, C, home, end):           # OOOOOOO....OOOOO 인 경우
        return end
    # end = home[-1] - home[0] + 1            # 이렇게 하면 무조건 end는 X
    
    while start + 1 < end:
        mid = (start + end) // 2
        if CanBuild(N, C, home, mid):
            start = mid
        else:
            end = mid

    return start

N, C = map(int, input().split())
home = [int(input()) for _ in range(N)]
home.sort()

print(solution(N, C, home))


# ...집......집...집..집
# 인접한 두 공유기 사이의 거리의 최솟값을 x라 했을때
# 1 <= x <= 가장 오른쪽집-가장왼쪽집
# 답 : 여기서 가능한 x의 최댓값
# 1 2 3 4 5                   6 7 8 9 10 
# O(C개 설치가능)OOOOOOOOOO   XXXXXXXX(C개 설치불가능)

# 이분탐색의 기준
# start 는 O
# end 는 X
# mid가 O면 mid를 start에 넣음

#         start end
# OOOOO   O     XXXXXXXX
# O: 설치가능
# X: 설치불가능