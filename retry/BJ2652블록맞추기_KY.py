#! 2020.02.25
# TODO BJ2652블록맞추기
N = int(input())
U, V, W, X, Y = map(int,input().split())
SIZE = U*V + X*Y
inMap = [list(map(int,input().split())) for _ in range(N)]
visited = [[False for _ in range(N)] for _ in range(N)]
result = []
dx = [1,0,-1,0]
dy = [0,1,0,-1]

def inRange(yy,xx):
    if yy>=0 and xx>=0 and yy<N and xx<N:
        return True
    else:
        return False

def DFS(yy,xx):
    maxX = xx
    maxY = yy
    for dir in range(4):
        nextY = yy+dy[dir]
        nextX = xx+dx[dir]
        if inRange(nextY,nextX) and not visited[nextY][nextX] and inMap[nextY][nextX]==1:
            visited[nextY][nextX] = True
            tmpY,tmpX = DFS(nextY,nextX)
            if tmpY>=maxY and tmpX>=maxX:
                maxX,maxY = tmpX,tmpY 
    return maxY,maxX

def cntBlock(startY,startX,endY,endX,val):
    cnt = 0
    for i in range(startY,endY+1):
        for j in range(startX,endX+1):
            if inRange(i,j) and inMap[i][j]==val:
                cnt += 1
    return cnt
    
def checkBlock(yy1,xx1,yy2,xx2):
    n0 = cntBlock(yy1,xx1,yy1,xx2,1) #up
    n1 = cntBlock(yy1,xx2,yy2,xx2,1) #right
    n2 = cntBlock(yy2,xx1,yy2,xx2,1) #down
    n3 = cntBlock(yy1,xx1,yy2,xx1,1) #left
    side = -1       # 0 : up, 1 : right, 2 : down, 3 : left
    blank = 0
    length = 0
    if n1==n3:
        if n0>n2:
            side = 2
            blank = n0-n2
            length = n0
        else:
            side = 0
            blank = n2-n0
            length = n2
    else:
        if n1>n3:
            side = 3
            blank = n1-n3
            length = n1
        else:
            side = 1
            blank = n3-n1
            length = n3
            
    if length == U and blank == Y and cntBlock(yy1,xx1,yy2,xx2,0) == X*Y:
        cntEmpty = 0
        if side == 0:
            cntEmpty += cntBlock(yy1,xx2-W-Y+1,yy1+X-1,xx2-W,0)
            cntEmpty += cntBlock(yy1-V,xx2-U+1,yy1-1,xx2,0)
        elif side == 1:
            cntEmpty += cntBlock(yy2-W-Y+1,xx2-X+1,yy2-W,xx2,0)
            cntEmpty += cntBlock(yy2-U+1,xx2+1,yy2,xx2+V,0)
        elif side == 2:
            cntEmpty += cntBlock(yy2-X+1,xx1+W,yy2,xx1+W+Y-1,0)
            cntEmpty += cntBlock(yy2+1,xx1,yy2+V,xx1+U-1,0)
        else:
            cntEmpty += cntBlock(yy1+W,xx1,yy1+W+Y-1,xx1+X-1,0)
            cntEmpty += cntBlock(yy1,xx1-V,yy1+U-1,xx1-1,0)
        if cntEmpty==SIZE:
            return True
    return False

def getResult():
    for y1 in range(N):
        for x1 in range(N):
            if not visited[y1][x1] and inMap[y1][x1]==1:
                visited[y1][x1] = True
                y2,x2 = DFS(y1,x1)
                if checkBlock(y1,x1,y2,x2):
                    tmpRet = [0]*2
                    tmpRet[0],tmpRet[1] = y1+1,x1+1
                    result.append(tmpRet)

getResult()
print(len(result))
for ret in result:
    print(*ret)