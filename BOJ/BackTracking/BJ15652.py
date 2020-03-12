#! BJ1565# 20200120
 : https://www.acmicpc.net/problem/15652
N, M = tuple(map(lambda x: int(x),input().split(' ')))
result = [0 for i in range(M)]

def getResult(n,m,resultArr):
    if m>=M:
        for i in resultArr:
            print(i,end=' ')
        print('')
    else:
        for i in range(n,N+1):
            resultArr[m]=i
            getResult(i,m+1,resultArr)
            resultArr[m] = 0

getResult(1,0,result)
