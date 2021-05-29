# 2021.03.21 특정 거리의 도시 찾기
# https://acmicpc.ent/problem/18352

import sys
sys.stdin = open('input.txt', 'r')

from collections import deque

N, M, K, X = map(int, input().split())
graph = [[] for _ in range(N+1)]

for _ in range(M):
    start, end = map(int, input().split())
    graph[start].append(end)

def BFS(myGraph, x):
    distance = [-1 for _ in range(N+1)]
    distance[X] = 0

    q = deque([x])
    while q:
        now = q.popleft()
        for next_node in myGraph[now]:
            if distance[next_node] == -1:
                distance[next_node] = distance[now] + 1
                q.append(next_node)
    return distance
    
result = BFS(graph, X)
check = False
for i in range(1, N+1):
    if result[i] == K:
        print(i)
        check = True
if not check:
    print(-1)
    