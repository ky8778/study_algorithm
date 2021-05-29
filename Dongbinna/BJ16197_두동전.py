# 2021.04.24
import sys, copy
sys.stdin = open('input.txt', 'r')

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def DFS(myMap, coin, n, m, minAns, now):
    # print(coin, now)
    if now >= 11:
        return now
    elif minAns <= now:
        return minAns
    else:
        for d in range(4):
            nextCoin = []
            # move coin
            cnt = 0
            for c in coin:
                nextY, nextX = c[0]+dy[d], c[1]+dx[d]
                if nextY < 0 or nextY >= n or nextX < 0 or nextX >= m:  # 떨어짐
                    cnt += 1
                    continue

                if myMap[nextY][nextX] == '#':
                    nextCoin.append((c[0], c[1]))
                else:
                    nextCoin.append((nextY, nextX))

            # print('cnt : ' +str(cnt))
            if cnt == 1:
                minAns = min(minAns, now)
            else:
                minAns = min(minAns, DFS(myMap, nextCoin, n, m, minAns, now+1))
        
        return minAns

def solution(myMap, n, m):
    answer = 100
    coin = []
    for y in range(n):
        for x in range(m):
            if myMap[y][x] == 'o':
                coin.append([y, x])
    answer = DFS(myMap, coin, n, m, answer, 1)
    # print(coin)
    if answer > 10:
        return -1
    else:
        return answer

N, M = map(int, input().split())
myMap = []
for _ in range(N):
    myMap.append(list(input()))

print(solution(myMap, N, M))