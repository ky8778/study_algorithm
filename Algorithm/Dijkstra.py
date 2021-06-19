''' Dijkstra with PriorityQueue '''
# imports
from queue import PriorityQueue

# constants
INF = float('inf')

# input_map : node, edge info
# start : start node number
# V : number of nodes
def dijkstra(input_map, start, V):
    dist = [INF] * V
    dist[start] = 0
    pq = PriorityQueue()
    pq.put((0, start))
    
    while pq:
        now = pq.get()
        cost = -now[0]
        current_node = now[1]
        
        if dist[current_node] < cost:
            continue
        else:
            for i in range(len(input_map[current_node])):
                next = input_map[current_node][i][0]
                next_dist = cost + input_map[current_node][i][1]
                if dist[next] > next_dist:
                    dist[next] = next_dist
                    pq.put((-next_dist, next))

    return dist

''' Dijkstra with array '''
def dijkstra(input_map, start, V):
    dist = [INF] * V
    visited = [False] * V

    while True:
        min_dist = INF
        here = start        
        for i in range(V):
            if dist[i] < min_dist and not visited[i]:
                start = i
                min_dist = dist[i]
        if min_dist == INF:
            break
        visited[here] = True
        for i in range(len(input_map[i])):
            next = input_map[i][0]
            if visited[next]:
                continue
            next_dist = dist[here] + input_map[here][i][1]
            dist[next] = min(dist[next], next_dist)

    return dist