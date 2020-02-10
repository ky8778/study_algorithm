
#! 20200130
# TODO BJ2477
N = int(input())

def getResult(inputList):
    dirList = [0]*4
    tmpList = [0]*4
    idx = 0
    rowMax = -1
    colMax = -1
    small = 0

    for l in inputList:
        if l[0] == 1 or l[0] == 2:
            if rowMax < l[1]:
                rowMax = l[1]
        else:
            if colMax < l[1]:
                colMax = l[1]
        # print(rowMax,colMax)
    big = rowMax * colMax
    # print(big,small)

    for i in range(len(inputList)):
        if inputList[i][0] == inputList[(i+2)%6][0] and inputList[(i+1)%6][0] == inputList[(i+3)%6][0]:
            small = inputList[(i+1)%6][1]*inputList[(i+2)%6][1]
    return big - small 

inputData = []
for n in range(6):
    tmp = list(map(int,input().split()))
    inputData.append(tmp)

print(getResult(inputData)*N)