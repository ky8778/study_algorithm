# TODO SWEA5105_미로의거리 BFS
#! 2020.04.03
import sys
sys.stdin = open("sample_input.txt","r")
from queue import Queue

T = int(input())
dy = [0,1,0,-1]
dx = [1,0,-1,0]
N = None

def inRange(y,x):
    if y>=0 and x>=0 and y<N and x<N:
        return True
    else:
        return False

def BFS(s,e):
    ret = 0
    myQ = Queue()
    myQ.put(s)
    visited[s[0]][s[1]] = True
    
    while not myQ.empty():
        size_Q = myQ.qsize()
        for _ in range(size_Q):
            now = myQ.get()
            if now == e:
                return ret-1
            for d in range(4):
                nextY = now[0]+dy[d]
                nextX = now[1]+dx[d]
                if inRange(nextY,nextX) and not visited[nextY][nextX]:
                    myQ.put([nextY,nextX])
                    visited[nextY][nextX] = True
        ret += 1
    return 0

def getResult():
    for i in range(N):
        for j in range(N):
            if myMap[i][j]==1:
                visited[i][j] = True
            elif myMap[i][j]==2:
                start = [i,j]
            elif myMap[i][j]==3:
                end = [i,j]
    return BFS(start,end)


for tc in range(1,T+1):
    N = int(input())
    myMap = [list(map(int,list(input()))) for _ in range(N)]
    visited = [[False for _ in range(N)] for _ in range(N)]
    print("#{0} {1}".format(tc,getResult()))