
# TODO BJ2628 : https://www.acmicpc.net/problem/2628

W, H = map(int, input().split())
N = int(input())

paperIdx = [[],[]]
paperIdx[1].append(W)
paperIdx[0].append(H)

for n in range(N):
    k, num = map(int,input().split())
    paperIdx[k].append(num)

result = 1
for i in range(2):
    paperIdx[i].append(0)
    paperIdx[i].sort()
    # print(paperIdx[i])
    tmpMax = -1
    for idx in range(len(paperIdx[i]) - 1):
        if tmpMax < paperIdx[i][idx + 1] - paperIdx[i][idx]:
            tmpMax = paperIdx[i][idx + 1] - paperIdx[i][idx]
    result *= tmpMax

print(result)
