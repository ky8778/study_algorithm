#! 2020.02.22
# TODO BJ7568덩치
def checkRank(inList,idx1,idx2):
    if inList[idx1][0] < inList[idx2][0] and inList[idx1][1] < inList[idx2][1]:
        return True
    else:
        return False

N = int(input())
inData = []
for i in range(N):
    tmp = []
    W,H = map(int,input().split())
    tmp.append(W)
    tmp.append(H)
    tmp.append(0)
    inData.append(tmp)

for i in range(N):
    rank = 1
    for j in range(N):
        if i!=j and checkRank(inData,i,j):
            rank+=1
    inData[i][2] = rank

for i in range(N):
    print(inData[i][2],end=' ')

''' 오답 : 만약 소팅을 해서 한방향으로 가면서 비교하게 되면 1위와 비기는 경우에 해당되는 사람은 덩치가 같음에도 직전 랭킹과 같은 덩치가 되는 오류가 생긴다.
N = int(input())
inData = []
for i in range(N):
    tmp = []
    W,H = map(int,input().split())
    tmp.append(W)
    tmp.append(H)
    tmp.append(i)
    tmp.append(0)
    inData.append(tmp)

inData.sort(reverse=True)
# print(inData)

rank = 1
idx = 0
while idx<len(inData):
    start = idx
    inData[idx][3] = rank
    cnt = 1
    while idx+1<len(inData) and not (inData[idx+1][0] < inData[start][0] and inData[idx+1][1] < inData[start][1]):
        idx+=1
        cnt+=1
        inData[idx][3] = rank
        # print(idx, rank)
    
    idx+=1
    rank+=cnt

# print(inData)
inData.sort(key=lambda val: val[2])
for i in range(len(inData)):
    print(inData[i][3],end=' ')
'''