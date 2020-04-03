# TODO SWEA5105_노드의거리 BFS
#! 2020.04.03
import sys
sys.stdin = open("sample_input.txt","r")
# from collections import deque
from queue import Queue

T = int(input())

def getResult(inS,inG):
    myQ = Queue()
    myQ.put(inS)
    visited[inS] = True
    ret = 0

    while not myQ.empty():
        size_Q = myQ.qsize()
        for _ in range(size_Q):
            now = myQ.get()
            if now == inG:
                return ret
            for go in myMap[now]:
                if not visited[go]:
                    visited[go] = True
                    myQ.put(go)
        ret += 1
    return 0

for tc in range(1,T+1):
    V,E = map(int,input().split())
    myMap = [[] for _ in range(V+1)]
    visited = [False for _ in range(V+1)]
    for _ in range(E):
        s, e = map(int,input().split())
        myMap[s].append(e)
        myMap[e].append(s)

    S,G = map(int,input().split())
    print("#{0} {1}".format(tc,getResult(S,G)))