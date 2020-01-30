
#! 20200130
# TODO BJ2527

T = 4

def getResult(inputList):
    x = []
    y = []
    for i in range(4):
        x.append(inputList[i*2])
        y.append(inputList[i*2+1])

    if x[0]>x[2]:
        x[0],x[2] = x[2],x[0]
        x[1],x[3] = x[3],x[1]
        y[0],y[2] = y[2],y[0]
        y[1],y[3] = y[3],y[1]
    
    if x[1]<x[2]:
        return 'd'
    elif x[1]==x[2]:
        if y[1]==y[2]:
            return 'c'
        elif y[1]<y[2]:
            return 'd'
        else:
            if y[3]==y[0]:
                return 'c'
            elif y[3]>y[0]:
                return 'b'
            else:
                return 'd'
    else:
        if y[1]==y[2]:
            return 'b'
        elif y[1]<y[2]:
            return 'd'
        else:
            if y[0]==y[3]:
                return 'b'
            elif y[0]>y[3]:
                return 'd'
            else:
                return 'a'


for t in range(T):
    inputData = list(map(int,input().split()))
    print(getResult(inputData))