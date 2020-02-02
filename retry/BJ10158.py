
#! 20200130
# TODO BJ10158
#! 오답!!!! 핵심 알고리즘을 생각해야한다.

changeDir = [[-1,-1,1,0],[1,-1,-1,2],[3,2,-1,-1],[-1,0,3,-1]]
changePosi = [[1,1],[-1,1],[-1,-1],[1,-1]]


sizeX,sizeY = map(int,input().split())
curPosi = list(map(int,input().split()))
T = int(input())

def inRange(curP,dir):
    distX = []
    distX.append(curP[0]-0)
    distX.append(sizeX - curP[0])
    distY = []
    distY.append(curP[1]-0)
    distY.append(sizeY-curP[1])
    dist = 0
    wall = 0
    if dir == 0:
        if distX[1]>distY[1]:
            dist = distY[1]
            wall = 2
        else:
            dist = distX[1]
            wall = 1
    elif dir == 1:
        if distX[0]>distY[1]:
            dist = distY[1]
            wall = 2
        else:
            dist = distX[0]
            wall = 3
    elif dir == 2:
        if distX[0]>distY[0]:
            dist = distY[0]
            wall = 0
        else:
            dist = distX[0]
            wall = 3
    else:
        if distX[1]>distY[0]:
            dist = distY[0]
            wall = 0
        else:
            dist = distX[1]
            wall = 1

    return wall,dist 

def getResult(R,C,inT,curP):    
    dir = 0
    t = 0
    startX = curP[0]
    startY = curP[1]
    cnt = 0
    flag = True
    while t < inT:
        wall, dist = inRange(curP,dir)
        if t+dist >= inT:
            dist = inT-t
        for i in range(2):
            curP[i] += changePosi[dir][i] * dist
        dir = changeDir[wall][dir]
        t += dist
        # print("wall : " + str(wall) + " dist : ",str(dist))
        if dir == 0 and flag and (startX - curP[0])==(startY-curP[1]):
            flag = False
            cnt = t
            while t < inT:
                t+=cnt
            t-=cnt
        

getResult(sizeY,sizeX,T,curPosi)
for i in range(2):
    print(curPosi[i],end=' ')

