
#! 2020.02.06
# TODO SWEA1267 작업순서

T = 10

def getResult(inList,numV,numE):
    myMap = [[0]*numV for i in range(numV)]
    inDegree = [0]*numV
    outDegree = [0]*numV
    for i in range(numE):
        start = inList[i*2]-1
        end = inList[i*2+1]-1
        myMap[start][end] = 1
        inDegree[end] += 1
        outDegree[start] += 1
    
    ret = []
    # inDegree가 모두 -1이 될 때 까지 0인걸 계속 찾고 거기서 다음 노드를 줄여준다.
    sumIndeg = sum(inDegree)
    while sumIndeg != -len(inDegree):
        # indegree가 0인 idx를 찾는다.
        idx = 0
        for i in range(numV):
            if inDegree[i] == 0:
                idx = i
                inDegree[idx] = -1
                ret.append(idx+1)
                break
        for i in range(numV):
            if myMap[idx][i] == 1:
                inDegree[i] -= 1
                
        sumIndeg = sum(inDegree)

        
    # print(inDegree)
    # print(outDegree)
    # print(ret)
    return ret

for tc in range(1,T+1):
    V, E = map(int,input().split())
    inData = list(map(int,input().split()))
    result = getResult(inData,V,E)
    print("#{0} {1}".format(tc,' '.join(map(str,result))))