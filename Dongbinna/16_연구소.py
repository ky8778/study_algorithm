# 2021.03.21 연구소
# 삼성전자 SW 역량테스트
# https://www.acmicpc.net/problem/14502

import sys
sys.stdin = open('input.txt', 'r')

from itertools import combinations
from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def check(N, M, inputMap, currentComb):
    ret = 0
    for location in currentComb:
        y, x = location[0], location[1]
        inputMap[y][x] = 1

    checkMap = [[False for _ in range(M)] for _ in range(N)]
    
    for n in range(N):
        for m in range(M):
            if inputMap[n][m] == 0 and not checkMap[n][m]:
                cnt = 1
                isSafe = True
                checkMap[n][m] = True
                q = deque()
                q.append([n, m])
                while q:
                    currentP = q.popleft()
                    for dir in range(4):
                        nextY = currentP[0] + dy[dir]
                        nextX = currentP[1] + dx[dir]
                        if 0 <= nextY < N and 0 <= nextX < M:
                            if inputMap[nextY][nextX] == 0 and not checkMap[nextY][nextX]:
                                checkMap[nextY][nextX] = True
                                q.append([nextY, nextX])
                                cnt += 1
                            elif inputMap[nextY][nextX] == 2:
                                isSafe = False
                if isSafe:
                    ret += cnt

    for location in currentComb:
        y, x = location[0], location[1]
        inputMap[y][x] = 0

    return ret

def solution(N, M, inputMap):
    ret = 0

    wall = []
    for n in range(N):
        for m in range(M):
            if inputMap[n][m] == 0:
                wall.append((n, m))
    wallComb = list(map(list, combinations(wall, 3)))
    
    for checkComb in wallComb:
        ret = max(ret, check(N, M, inputMap, checkComb))

    return ret

N, M = map(int, input().split())
inputMap = [list(map(int, input().split())) for _ in range(N)]

print(solution(N, M, inputMap))