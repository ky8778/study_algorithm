
#! 2020.02.03
# TODO BJ2564

W, H = map(int,input().split())
N = int(input())
inputData = []
for i in range(N+1):
    inputD = list(map(int,input().split()))
    inputData.append(inputD)

def transform(inA):
    a = []
    a.append(inA[0])
    a.append(inA[1])
    if a[0] == 1:
        a[0] = 0
    elif a[0] == 2:
        a[0] = H
    elif a[0] == 3:
        a[0],a[1] = a[1],0
    else:
        a[0],a[1] = a[1],W
    return a

def getResult(in1,Dong):
    if in1[0] == Dong[0]:
        return abs(Dong[1]-in1[1])
    elif (in1[0]+Dong[0])==3:
        return  min(in1[1]+Dong[1],2*W-in1[1]-Dong[1]) + H
    elif (in1[0]+Dong[0])==7:
        return min(in1[1]+Dong[1],2*H-in1[1]-Dong[1]) + W
    else:
        inT = transform(in1)
        dongT = transform(Dong)
        return abs(inT[0]-dongT[0]) + abs(inT[1]-dongT[1])

result = 0
for i in range(N):
    result += getResult(inputData[i],inputData[N])
print(result)