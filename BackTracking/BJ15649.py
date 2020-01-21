# 20200120
#! BJ15649 : https://www.acmicpc.net/problem/15649
N, M = tuple(map(lambda x: int(x),input().split(' ')))
result = [0 for i in range(M)]

def getResult(n,m,resultArr):
    if m>=M:
        for i in resultArr:
            print(i,end=' ')
        print('')
    elif n>N:
        #print(n,m,resultArr)
        return
    else:
        for i in range(1,N+1):
            if i not in resultArr:
                resultArr[m]=i
                getResult(n+1,m+1,resultArr)
                resultArr[m] = 0

getResult(1,0,result)
