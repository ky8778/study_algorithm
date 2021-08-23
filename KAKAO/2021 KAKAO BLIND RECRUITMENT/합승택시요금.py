# 2021.08.23
'''
    Solution
1. Floyd Algorithm 을 활용해서 모든점에서 모든점까지의 최단거리를 구한다.
2. 완전탐색 1 ~ N 까지 합승하는 모든 경우를 계산하여 비교한다.
    - 시작점과 동일한 경우는 시작점 -> 시작점의 비용이 0원이므로 동승하지 않았음을 의미)
    - i 까지 동승한 후 각자 이동하는 경우를 계산하여 최솟값 업데이트
'''
import sys

INF = sys.maxsize

def Floyd(dist, N):
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    
    return dist

def solution(n, s, a, b, fares):
    answer = INF
    my_map = [[INF]*n for _ in range(n)]
    for aa, bb, d in fares:
        my_map[aa-1][bb-1] = d
        my_map[bb-1][aa-1] = d

    for i in range(n):
        my_map[i][i] = 0
    # print(my_map)

    my_dist = Floyd(my_map, n)
    # for m in my_dist:
    #     print(*m)

    for i in range(n):
        this_case = my_dist[s-1][i] + my_dist[i][a-1] + my_dist[i][b-1]
        # print(str(i) + " : " + str(this_case))
        answer = min(answer, my_dist[s-1][i] + my_dist[i][a-1] + my_dist[i][b-1])

    return answer

print(solution(6,4,6,2, [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))