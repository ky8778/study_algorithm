
#! 20200130
# TODO BJ10157

C,R = map(int,input().split())
K = int(input())

def getResult(sizeY,sizeX,inK):
    if sizeY*sizeX < inK:
        return 0, 0
    else:
        x = 1
        y = 0
        plus = True
        sizeX -= 1
        while True:
            for i in range(sizeY):
                if plus:
                    y += 1
                else:
                    y -= 1
                inK -= 1
                if inK == 0:
                    return x,y
            sizeY -= 1
            for i in range(sizeX):
                if plus:
                    x += 1
                else:
                    x -= 1
                inK -= 1
                if inK == 0:
                    return x,y
            sizeX -= 1
            if plus:
                plus = False
            else:
                plus = True

resultX, resultY = getResult(R,C,K)
if resultX == 0:  
    print(0)
else:
    print(resultX,resultY)