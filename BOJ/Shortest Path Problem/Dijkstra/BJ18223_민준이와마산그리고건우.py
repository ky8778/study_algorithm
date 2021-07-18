import heapq
INF = int(1e9)

V, E, P = map(int, input().split())
MyMap = [[] for _ in range(V+1)]

def dijikstra(start, end):
    q = list()
    heapq.heappush(q, (0, start))
    dist = [INF] * (V+1)
    dist[start] = 0

    while q:
        cost, cur = heapq.heappop(q)
        if dist[cur] < cost:
            continue
        for i in MyMap[cur]:
            next = cost + i[1]
            if dist[i[0]] > next:
                dist[i[0]] = next
                heapq.heappush(q, (next, i[0]))
    return dist[end]

for _ in range(E):
    A, B, W = map(int, input().split())
    MyMap[A].append([B, W])
    MyMap[B].append([A, W])

if dijikstra(1, V) == dijikstra(1, P) + dijikstra(P, V):
    print("SAVE HIM")
else:
    print("GOOD BYE")