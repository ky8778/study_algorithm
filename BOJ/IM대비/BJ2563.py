
#! 2020.02.03
# TODO BJ2563

N = int(input())
inputMap = [[0 for _ in range(110)] for _ in range(110)]

def getResult(x,y,inMap):
    for r in range(10):
        for c in range(10):
            inMap[y+r][x+c] = 1

for i in range(N):
    x,y = map(int,input().split())
    getResult(x,y,inputMap)

result = 0
for i in range(100):
    for j in range(100):
        result += inputMap[i][j]
print(result)
    
