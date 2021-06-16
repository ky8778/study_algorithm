# 2021.06.16 병사배치하기
# Solution : LIS (Longest Increasing Sequence)

def getResult(N, People, DP):
    # 1. 0 ~ N-1 을 돌며 DP[N]을 구한다. (n)
    for n in range(N):
        # 2. DP[N] = DP[N-i] + 1 (i = 0 ~ n-1)
        # N-i번보다 N번이 작으면 N-i번 오른쪽에 N번이 위치할 수 있고, 이렇게 했을 때 N-i번의 최대 길이에 +1 한 것이 N번의 최대길이 후보가 된다.
        for idx in range(n):
            # 2-1. 0 ~ n-1 을 돌며 왼쪽 부분수열 중 n번이 오른쪽에 놓일 수 있는 후보를 고른다.
            if People[n] < People[idx]:
                # 2-2. +1 한 값과 비교해 DP[n]을 업데이트한다.
                DP[n] = max(DP[idx] + 1, DP[n])
        
    # 3. DP[N] 중 최댓값을 N에서 뺀 값이 정답.
    return N - max(DP)

N = int(input())
People = list(map(int, input().split()))
DP = [1 for _ in range(N)]  # DP[N] : N번을 오쪽끝으로 하는 최대 내림차순 수열 길이
print(getResult(N, People, DP))
# print(DP)