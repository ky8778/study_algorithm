# https://www.acmicpc.net/problem/

from collections import deque

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def solution(N, K, S, Y, X, inputMap):
    virus = [deque() for _ in range(K+1)]

    # 1. 바이러스 리스트 만들기
    for y in range(N):
        for x in range(N):
            if inputMap[y][x] != 0:
                virus[inputMap[y][x]].append((y, x))

    # 2. S초 동안 바이러스가 퍼진다
    for s in range(S):
        for virusNo in range(K+1):
            for _ in range(len(virus[virusNo])):
                currentVirus = virus[virusNo].popleft()
                # 3. 네 방향을 돌며 바이러스가 퍼진다.
                for d in range(4):
                    nextY, nextX = currentVirus[0] + dy[d], currentVirus[1] + dx[d]
                    if 0 <= nextY < N and 0 <= nextX < N:
                        if inputMap[nextY][nextX] == 0:
                            inputMap[nextY][nextX] = inputMap[currentVirus[0]][currentVirus[1]]
                            virus[virusNo].append((nextY, nextX))

    return inputMap[Y-1][X-1]

N, K = map(int, input().split())
inputMap = []
for n in range(N):
    inputMap.append(list(map(int, input().split())))
S, Y, X = map(int, input().split())
print(solution(N, K, S, Y, X, inputMap))