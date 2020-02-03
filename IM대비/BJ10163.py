
#! 20200131
# TODO BJ10631

# inputMap = [[0]*100]*100
inputMap = [[0 for i in range(110)] for j in range(110)]
N = int(input())

def inRange(x,y):
    if x<=100 and x>=0 and y<=100 and y>=0:
        return True
    else:
        return False

for i in range(N):
    tmpList = list(map(int,input().split()))
    start1 = tmpList[0]
    start2 = tmpList[1]
    size1 = tmpList[0]+tmpList[2]
    size2 = tmpList[1]+tmpList[3]
    for r in range(start1,size1):
        for c in range(start2,size2):
            if inRange(c,r):
                inputMap[r][c] = (i+1)
            # print(r,c)

for i in range(N):
    cnt = 0
    for r in range(110):
        for c in range(110):
            if (inputMap[r][c]==(i+1)) and inRange(c,r):
                cnt += 1
                # print(r,c,inputMap[r][c],i+1,cnt)
    print(cnt)
# for r in range(100):
#     for c in range(100):
#         print(inputMap[r][c],end=' ')
#     print()