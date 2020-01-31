
#! 20200130
# TODO BJ2559

def getResult(inN,inK,inputList):
    sum = 0
    for i in range(inK):
        sum += inputList[i]
    result = sum

    for i in range(inK,inN):
        sum = sum - inputList[i-inK] + inputList[i]
        if sum>result:
            result = sum

    return result

N, K = map(int,input().split())
inputData = list(map(int,input().split()))

print(getResult(N,K,inputData))