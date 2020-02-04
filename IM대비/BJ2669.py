
# TODO BJ2669 : https://www.acmicpc.net/problem/2669
size = 100
inputMap = [[0 for i in range(size)] for j in range(size)]
# print(inputMap)

def getResult(inputList,map):
    rowStart = inputList[1]
    colStart = inputList[0]
    rowEnd = inputList[3]
    colEnd = inputList[2]
    for r in range(rowStart,rowEnd):
        for c in range(colStart,colEnd):
            map[r][c] += 1

for i in range(4):
    inputData = list(map(int,input().split()))
    getResult(inputData,inputMap)

result = 0
for i in range(size):
    for j in range(size):
        if inputMap[i][j] != 0:
            result += 1
    #     print(inputMap[i][j],end=' ')
    # print()
print(result)
