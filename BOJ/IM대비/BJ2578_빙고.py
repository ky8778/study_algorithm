
#! 20200130
# TODO BJ2578

def checkBingo(mapList,row,col):
    result = 0
    crossSum1,crossSum2 = 0, 0
    for i in range(5):
        rowSum = 0
        colSum = 0
        for j in range(5):
            rowSum+=mapList[i][j]
            colSum+=mapList[j][i]
        if rowSum==0:
            result+=1
        if colSum==0:
            result+=1
        
        crossSum1 += mapList[i][i]
        crossSum2 += mapList[i][4-i]
    
    if crossSum1 == 0:
        result+=1
    if crossSum2 == 0:
        result+=1
            
    return result

def removeBingo(mapList,number):
    rowIdx = 0
    colIdx = 0
    for r in range(5):
        for c in range(5):
            if mapList[r][c] == number:
                mapList[r][c] = 0
                rowIdx = r
                colIdx = c
                break
    if checkBingo(mapList,rowIdx,colIdx)>=3:
        return True
    else:
        return False

def getResult(mapList,numList):
    result = -1
    for idx,val in enumerate(numList):
        if removeBingo(mapList,val):
            result = idx+1
            break
    
    return result
        

inputMap = []
for i in range(5):
    tmp = list(map(int,input().split()))
    inputMap.append(tmp)

inputNum = []
for i in range(5):
    tmp = list(map(int,input().split()))
    inputNum += tmp

print(getResult(inputMap,inputNum))