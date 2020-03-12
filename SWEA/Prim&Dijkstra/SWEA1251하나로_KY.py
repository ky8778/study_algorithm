#! 2020.03.06
# TODO SWEA1251_하나로
import sys
sys.stdin = open('input.txt', 'r')
# Prim's Algorithm
T = int(input())

def getEdges():
    for i in range(N-1):
        for j in range(i+1,N):
            inEdges[i][j] = ((X[i]-X[j])**2 + (Y[i]-Y[j])**2)
            inEdges[j][i] = inEdges[i][j]

'''
def getResult():
    myNodes.append(0)
    price = 0
    while len(myNodes)<N:
        minIdx = -1
        minVal = -1
        for now in myNodes:
            for next in range(N):
                if next not in myNodes and (minVal==-1 or minVal>inEdges[now][next]):
                    minVal = inEdges[now][next]
                    minIdx = next
        price += minVal
        myNodes.append(minIdx)

    return price
'''

def getResult():
    myNodes.append(0)
    price = 0
    checkNodes = [False for _ in range(N)]
    checkNodes[0] = True
    while len(myNodes)<N:
        minIdx = -1
        minVal = -1
        for now in myNodes:
            for next in range(N):
                if not checkNodes[next] and (minVal==-1 or minVal>inEdges[now][next]):
                    minVal = inEdges[now][next]
                    minIdx = next
        price += minVal
        myNodes.append(minIdx)
        checkNodes[minIdx] = True

    return price

for tc in range(1,T+1):
    N = int(input())
    X = list(map(int,input().split()))
    Y = list(map(int,input().split()))
    E = float(input())
    inEdges = [[-1 for _ in range(N)] for _ in range(N)]
    getEdges()
    myNodes = []
    print("#{0} {1}".format(tc,round(getResult()*E)))

''' maybe Kruscal Algorithm
for num in range(int(input())):
    N = int(input())
    Xs = list(map(int, input().strip().split()))
    Ys = list(map(int, input().strip().split()))
    E = float(input())
    List = []
 
    for s in range(N):
        for e in range(s+1, N):
            diff = (Xs[s]-Xs[e])**2 + (Ys[s]-Ys[e])**2
            List.append([s, e, diff])
 
    List = sorted(List, key = lambda x : x[2])
 
    dist = 0
    select = [n for n in range(N)]
    for L in List:
        a, b = L[:2]
        a1, b1 = select[a], select[b]
        if a1 != b1:
            for idx in range(N):
                if select[idx] == b1:
                    select[idx] = a1
            dist += L[2]
 
    print("#{} {}".format(num+1, round(E*dist)))
'''