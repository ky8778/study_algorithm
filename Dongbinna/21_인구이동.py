import sys
sys.stdin = open('input.txt', 'r')

from collections import deque

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def BFS(myMap, visited, N, y, x, L, R):
    myQ = deque()
    retList = []
    myQ.append((y, x))
    retList.append((y,x))
    visited[y][x] = True
    retVal = myMap[y][x]

    # BFS
    while myQ:
        here = myQ.popleft()
        for d in range(4):
            nextY = here[0] + dy[d]
            nextX = here[1] + dx[d]
            if nextY >=0 and nextY < N and nextX >=0 and nextX < N:
                if not visited[nextY][nextX]:
                    dif = abs(myMap[here[0]][here[1]] - myMap[nextY][nextX])
                    if dif >= L and dif <= R:
                        visited[nextY][nextX] = True
                        myQ.append((nextY, nextX))
                        retList.append((nextY, nextX))
                        retVal += myMap[nextY][nextX]

    # 국경선을 공유한 나라가 없으면 인구이동 없음(False)을 리턴한다.
    if len(retList) == 1:
        return False

    # 국경선을 공유한 나라의 인구수 업데이트.
    for location in retList:
        myMap[location[0]][location[1]] = int(retVal / len(retList))

    return True

def solution(inputMap, N, L, R):
    cnt = -1

    # 인구이동이 없을 때까지 반복
    while True:
        cnt += 1
        visited = [[False for _ in range(N)] for _ in range(N)]
        CanMove = False

        # 모든 나라를 돌면서 국경선을 공유할 나라 탐색
        # 탐색한 후 바로 map에 업데이트 해준다
        # visited로 검증을 하기 때문에 업데이트한다고해서 탐색에 영향주지 않음.
        for i in range(N):
            for j in range(N):
                if not visited[i][j]:
                    if BFS(inputMap, visited, N, i, j, L, R):
                        CanMove = True

        if not CanMove:
            break

    return cnt

N, L, R = map(int, input().split())
inputMap = [list(map(int, input().split())) for _ in range(N)]
print(solution(inputMap, N, L, R))