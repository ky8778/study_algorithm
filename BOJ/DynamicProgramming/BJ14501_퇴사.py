# DP
# 2021.06.12

def DFS(table, memo, today, N):
    if today > N:
        return 0

    if memo[today] >= 0:
        return memo[today]
    else:
        # can work
        if today + table[today][0] - 1 <= N:
            ret = 0
            for i in range(today + table[today][0], N+1):
                ret = max(ret, DFS(table, memo, i, N))
            memo[today] = table[today][1] + ret
        # can't work
        else:
            memo[today] = 0
            
        return memo[today]

N = int(input())
table = []
table.append((1, 0))
memo = [-1] * (N+1)
for _ in range(N):
    table.append(tuple(map(int, input().split())))
# print(table)
print(DFS(table, memo, 0, N))

'''
input / output
7
3 10
5 20
1 10
1 20
2 15
4 40
2 200

45

10
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10

55

10
5 10
5 9
5 8
5 7
5 6
5 10
5 9
5 8
5 7
5 6

20

10
5 50
4 40
3 30
2 20
1 10
1 10
2 20
3 30
4 40
5 50

90
'''