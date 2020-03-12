N,M = map(int,input().split())
inMap = []

def checkMap(y,x):
    cnt1 = 0
    cnt2 = 0
    for i in range(8):
        for j in range(8):
            if (i+j)&1:
                if inMap[i+y][j+x] != 'B':  # 시작이 W일때
                    cnt1+=1
                else:
                    cnt2+=1
            else:
                if inMap[i+y][j+x] != 'W':
                    cnt1+=1
                else:
                    cnt2+=1
    if cnt1<cnt2:
        return cnt1
    else:
        return cnt2

def getResult():
    minRet = 987654321
    for i in range(N-7):
        for j in range(M-7):
            tmpRet = checkMap(i,j)
            if tmpRet<minRet:
                minRet = tmpRet
    return minRet


for i in range(N):
    tmp = list(input())
    inMap.append(tmp)
print(getResult())
