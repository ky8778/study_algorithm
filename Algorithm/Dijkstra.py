# imports
from queue import PriorityQueue

# constants
INF = float('inf')

# start : start node number, V : number of nodes
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