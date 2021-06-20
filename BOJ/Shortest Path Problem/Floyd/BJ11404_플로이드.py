# 2021.06.20

inf = int(1e9)

def floyd(input_map, V):
    for i in range(V):
        input_map[i][i] = 0
    
    for k in range(V):
        for i in range(V):
            for j in range(V):
                input_map[i][j] = min(input_map[i][j], input_map[i][k] + input_map[k][j])
                
    for i in range(V):
        for j in range(V):
            if input_map[i][j] == inf:
                input_map[i][j] = 0

    return input_map

V = int(input())
M = int(input())
input_map = [[inf] * V for _ in range(V)]
for _ in range(M):
    start, end, cost = map(int, input().split())
    input_map[start-1][end-1] = min(cost, input_map[start-1][end-1])

result = floyd(input_map, V)
for i in range(V):
    print(*result[i])