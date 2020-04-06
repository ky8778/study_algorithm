
#! 2020.02.06
# TODO SWEA1493_수의새로운연산
T = int(input())

A = []
A.append(0)
A.append(0)
A.append(1)
idx = 2
while idx<=300:
    A.append(A[idx]+idx-1)
    idx+=1
# print(A)

def getPoint(P):
    i = 1
    while A[i]<=P:
        i+=1
    i-=1

    dist = P-A[i]
    y = i-dist-1
    x = 1+dist
    return y,x

def getValue(y,x):
    # print(x+y)
    dist = A[x+y]
    dist += (x-1)
    return dist

def getResult(P,Q):
    y1, x1 = getPoint(P)
    y2, x2 = getPoint(Q)
    yy = y1+y2
    xx = x1+x2
    # print(yy,xx)
    return getValue(yy,xx)

for tc in range(1,T+1):
    p,q = map(int,input().split())

    print("#{0} {1}".format(tc,getResult(p,q)))