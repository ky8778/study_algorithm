#! 2020.03.06
# TODO SWEA1249_보급로
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
dx = [1,0,-1,0]
dy = [0,1,0,-1]
INF = float('inf')

def inRange(y,x):
    if y>=0 and y<N and x>=0 and x<N:
        return True
    else:
        return False

def isEnd(y,x):
    if y==N-1 and x==N-1:
        return True
    else:
        return False

def getResult():
    while True:
        minDist = INF
        for now in mynodes:    
            # print(now)
            for dir in range(4):
                nextY = now[0]+dy[dir]
                nextX = now[1]+dx[dir]
                if inRange(nextY,nextX) and not checkMap[nextY][nextX]:
                    dist[nextY][nextX] = min(dist[now[0]][now[1]]+inData[nextY][nextX],dist[nextY][nextX])
                    if minDist > dist[nextY][nextX]:
                        minDist = dist[nextY][nextX]
                        minNextY, minNextX = nextY, nextX

        # print(minNextY,minNextX)
        # print(mynodes)
        mynodes.append([minNextY,minNextX])
        checkMap[minNextY][minNextX] = True
        if isEnd(minNextY,minNextX):
            break

    return dist[N-1][N-1]

for tc in range(1,T+1):
    N = int(input())
    inData = [list(map(int,input())) for _ in range(N)]
    dist = [[INF for _ in range(N)] for _ in range(N)]
    checkMap = [[False for _ in range(N)] for _ in range(N)]
    dist[0][0] = 0
    checkMap[0][0] = True
    mynodes = []
    mynodes.append([0,0])
    print("#{0} {1}".format(tc,getResult()))

'''
import sys
sys.stdin = open('input.txt', 'r')
sys.setrecursionlimit(10**6)

T = int(input())
dx = [1,0,-1,0]
dy = [0,1,0,-1]
INF = float('inf')

def inRange(y,x):
    if y>=0 and y<N and x>=0 and x<N:
        return True
    else:
        return False

def isEnd(y,x):
    if y==N-1 and x==N-1:
        return True
    else:
        return False

def getResult(yy,xx,sumPrice):
    global result
    if isEnd(yy,xx):
        result = min(result,sumPrice)
        return
    
    for dir in range(4):
        nextY = yy+dy[dir]
        nextX = xx+dx[dir]
        if inRange(nextY,nextX) and not checkMap[nextY][nextX]:
            checkMap[nextY][nextX] = True
            sumPrice+=inData[nextY][nextX]
            if sumPrice < result:
                getResult(nextY,nextX,sumPrice)
            sumPrice-=inData[nextY][nextX]
            checkMap[nextY][nextX] = False

for tc in range(1,T+1):
    N = int(input())
    inData = [list(map(int,input())) for _ in range(N)]
    DP = [[INF for _ in range(N)] for _ in range(N)]
    checkDP = [[0 for _ in range(N)] for _ in range(N)]
    checkMap = [[False for _ in range(N)] for _ in range(N)]
    result = INF
    getResult(0,0,0)
    print("#{0} {1}".format(tc,result))
'''