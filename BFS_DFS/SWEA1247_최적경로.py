#! 2020.03.05
# TODO SWEA 1247 최적경로
T = int(input())
INF = 987654321

def getPrice():
    price = 0
    prev = start
    for i in myOrder:
        next = myGraph[i]
        price += (abs(next[0]-prev[0])+abs(next[1]-prev[1]))
        prev = next
    price += (abs(end[0]-prev[0]) + abs(end[1]-prev[1]))
    return price

def getResult(now):
    if now>=N:
        return getPrice()
    ret = INF
    for i in range(N):
        if not checkGraph[i]:
            checkGraph[i] = True
            myOrder[now] = i
            ret = min(ret,getResult(now+1))
            myOrder[now] = -1
            checkGraph[i] = False
    return ret

for tc in range(1,T+1):
    N = int(input())
    inData = list(map(int,input().split()))
    start = [inData[0],inData[1]]
    end = [inData[2],inData[3]]
    myGraph = [[inData[2*i],inData[2*i+1]] for i in range(2,N+2)]
    checkGraph = [False for _ in range(N)]
    myOrder = [-1 for _ in range(N)]
    print("#{0} {1}".format(tc,getResult(0)))

'''
나는 백트래킹으로만 했지만 전처리로 거리를 미리 다 계산해서 그래프로 만들어 사용하면 시간이 훨씬 줄어든다. 거리계산에서
+ 백트래킹에 가지치기를 추가해줄 수 있다.
+ 로컬 최솟값들을 따라가서 그리디하게 첫번째 결과를 얻은 뒤 그걸 이용해서 가지치기를 하면 더 효율적일 가능성이 높다.
'''