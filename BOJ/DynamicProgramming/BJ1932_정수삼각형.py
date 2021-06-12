# DP
# 2021.06.12

def getResult(input_map, memo, y, x, N):
    # DP
    if memo[y][x] != -1:
        return memo[y][x]
    # bottom
    if y >= N-1:
        return input_map[y][x]

    # DFS
    memo[y][x] = input_map[y][x] + max(getResult(input_map, memo, y+1, x, N), getResult(input_map, memo, y+1, x+1, N))
    
    return memo[y][x]

N = int(input())
my_map = []
memo = [[-1 for _ in range(n)] for n in range(1, N+1)] # max route from this node to bottom

for n in range(N):
    my_map.append(list(map(int, input().split())))

print(getResult(my_map, memo, 0, 0, N))

''' input
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

output
30
'''