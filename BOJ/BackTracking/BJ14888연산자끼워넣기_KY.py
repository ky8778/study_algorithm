N = int(input())
A = list(map(int,input().split()))
numOfCalcs = list(map(int,input().split()))
myCalcs = []

minRet = 9876543210
maxRet = -9876543210

def calc(n1,n2,type_c):
    if type_c==0:
        return n1+n2
    elif type_c==1:
        return n1-n2
    elif type_c==2:
        return n1*n2
    else:
        if n1<0:
            return -(abs(n1)//n2)
        else:
            return n1//n2

def getResult(n):
    global minRet,maxRet
    if n>=N-1:
        ret = A[0]
        for i in range(N-1):
            ret = calc(ret,A[i+1],myCalcs[i])
        minRet = min(ret,minRet)
        maxRet = max(ret,maxRet)
    for i in range(4):
        if numOfCalcs[i]>0:
            numOfCalcs[i]-=1
            myCalcs.append(i)
            getResult(n+1)
            numOfCalcs[i]+=1
            myCalcs.pop()

getResult(0)
print(maxRet)
print(minRet)