
# 2020.02.03
# TODO BJ2039.py

inputData = []
sum = 0
for i in range(9):
    inputNum = int(input())
    inputData.append(inputNum)
    sum+=inputNum

inputData.sort()

def getResult(inputList):
    idx1, idx2 = 0,0
    for i in range(8):
        for j in range(i+1,9):
            if sum-inputList[i]-inputList[j] == 100:
                idx1 = i
                idx2 = j
                return idx1,idx2

i1,i2 = getResult(inputData)
for i in range(9):
    if i != i1 and i != i2:
        print(inputData[i])        
