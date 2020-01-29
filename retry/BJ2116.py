
# TODO BJ2116 : https://www.acmicpc.net/problem/2116

N = int(input())

inputData = []
for n in range(N):
    tmpList = list(map(int,input().split()))
    tmpList[5], tmpList[1] = tmpList[1],tmpList[5]
    tmpList[3], tmpList[4] = tmpList[4],tmpList[3]
    inputData.append(tmpList)

def getMax(num, curIdx):
    return max(list(x for idx,x in enumerate(inputData[num]) if idx != curIdx*2 and idx != curIdx*2+1))

def getResult():
    maxVal = -1
    for i in range(3):
        for k in range(2):
            tmpVal = getMax(0,i)
            nextVal = inputData[0][i*2+k]
            for j in range(1,N):
                index = inputData[j].index(nextVal)
                tmpVal += getMax(j,index//2)
                if index %2 == 0:
                    nextVal = inputData[j][index+1]
                else:
                    nextVal = inputData[j][index-1]
            if maxVal < tmpVal:
                maxVal = tmpVal
    return maxVal

print(getResult())