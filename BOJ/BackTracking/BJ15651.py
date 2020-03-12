# 20200120
#! BJ15651 : https://www.acmicpc.net/problem/15651
N, M = tuple(map(lambda x: int(x),input().split(' ')))
result = [0 for i in range(M)]

def getResult(m,resultArr):
    if m>=M:
        for i in resultArr:
            print(i,end=' ')
        print('')
    else:
        for i in range(1,N+1):
            resultArr[m]=i
            getResult(m+1,resultArr)
            resultArr[m] = 0

getResult(0,result)
