#! 2020.03.09
# TODO BJ2206_벽부수고이동하기
# import sys
# sys.stdin = open("input.txt",'r')
import collections

INF = float("inf")
N,M = map(int,input().split())
inData = [list(map(int,list(input()))) for _ in range(N)]
DP = [[[INF for _ in range(2)] for _ in range(M)] for _ in range(N)]
dx = [1,0,-1,0]
dy = [0,1,0,-1]

def isEnd(y,x):
    if y==N-1 and x==M-1:
        return True
    else:
        return False

def inRange(y,x):
    if y>=0 and x>=0 and x<M and y<N:
        return True
    else:
        return False

def getResult():
    myQ = collections.deque()
    myQ.appendleft([0,0,0])
    cnt=1
    DP[0][0][0] = cnt
    while myQ:
        qSize = len(myQ)
        cnt+=1
        for _ in range(qSize):
            now = myQ.popleft()
            status = now[2]

            if isEnd(now[0],now[1]):
                return DP[now[0]][now[1]][now[2]]
            
            for dir in range(4):
                nextY = now[0]+dy[dir]
                nextX = now[1]+dx[dir]
                if inRange(nextY,nextX) and DP[nextY][nextX][status]>cnt:
                    if inData[nextY][nextX] == 0:
                        DP[nextY][nextX][status] = cnt
                        myQ.append([nextY,nextX,status])
                    else:
                        if status == 0:
                            nextStatus = 1
                            DP[nextY][nextX][nextStatus] = cnt
                            myQ.append([nextY,nextX,nextStatus])
    return INF

result = getResult()
if result>=INF:
    result = -1
print(result)