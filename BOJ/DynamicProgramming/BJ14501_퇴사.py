# DP
# 2021.06.12

def DFS(table, memo, today, N):
    if today >= N:
        return 0

    if memo[today] >= 0:
        return memo[today]
    else:
        # can't work
        if today + table[today][0] > N:
            memo[today] = 0
        # can work
        else:
            ret = 0
            for i in range(today + table[today][0], N):
                ret = max(ret, DFS(table, memo, i, N))
            memo[today] = table[today][1] + ret
        return memo[today]

def getResult(table, memo, N):
    ret = 0
    for start in range(N):
        ret = max(ret, DFS(table, memo, start, N))
    return ret

N = int(input())
table = [tuple(map(int, input().split())) for _ in range(N)]
memo = [-1 for _ in range(N)]
# print(table)
print(getResult(table, memo, N))
# print(memo)

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