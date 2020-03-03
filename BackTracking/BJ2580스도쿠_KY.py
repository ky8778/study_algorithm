inData = [list(map(int,input().split())) for _ in range(9)]
result = [[0 for _ in range(9)] for _ in range(9)]

def checkMap(y,x):
    checkNum = [False for _ in range(10)]
    for idx in range(9):
        val = inData[y][idx]
        checkNum[val] = True
        val = inData[idx][x]
        checkNum[val] = True
    
    startY = (y//3)*3
    startX = (x//3)*3
    for i in range(3):
        for j in range(3):
            val = inData[i+startY][j+startX]
            checkNum[val] = True
    # print(checkNum)
    return checkNum

def getResult(n):
    if n>=len(inList):
        for i in range(9):
            for j in range(9):
                result[i][j] = inData[i][j]
        return True
    yy = inList[n][0]
    xx = inList[n][1]
    checkNumber = checkMap(yy,xx)
    # print(checkNumber)
    for i in range(1,10):
        if not checkNumber[i]:
            inData[yy][xx] = i
            if getResult(n+1):
                return True
            else:    
                inData[yy][xx] = 0
    return False
            

inList = []
for i in range(9):
    for j in range(9):
        if inData[i][j] == 0:
            inList.append([i,j])
getResult(0)
# print(inData)
for i in result:
    print(*i)