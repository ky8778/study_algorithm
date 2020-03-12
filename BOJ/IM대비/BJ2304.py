
#! 20200130
# TODO BJ2304
N = int(input())
inputData = []

def getResult(data):
    result = 0
    idx = 0
    maxVal = max(data,key=lambda x:x[1])
    while idx < len(data)-1:
        curH = data[idx][1]
        curIdx = data[idx][0]

        nextidx = 0
        nextH = 0

        if data[idx][0] == maxVal[0]:
            result += maxVal[1]

        for i in range(idx+1,len(data)):
            if data[i][1] > curH:
                result += (data[i][0]-data[idx][0])*curH
                idx = i
                break
            if nextH < data[i][1]:
                nextH = data[i][1]
                nextidx = i

        if curIdx == data[idx][0]:
            result += nextH*(data[nextidx][0]-data[idx][0])
            idx = nextidx
        
        #print(idx,result)
    if maxVal[0] == data[len(data)-1][0]:
        result += maxVal[1]

    return result

for n in range(N):
    data = list(map(int,input().split()))
    inputData.append(data)

inputData.sort(key=lambda a:a[0])
# print(inputData)
print(getResult(inputData))

