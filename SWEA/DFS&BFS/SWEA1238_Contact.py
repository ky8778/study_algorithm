#! 2020.03.05
# TODO SWEA1238_Contact
import queue
T = 10

def getResult():
    myQ = queue.Queue()
    myQ.put(start)
    checkMap[start] = True

    while not myQ.empty():
        qSize = myQ.qsize()
        maxNode = 0
        for _ in range(qSize):
            current = myQ.get()
            maxNode = max(maxNode,current)
            for next in myGraph[current]:
                if not checkMap[next]:
                    checkMap[next] = True
                    myQ.put(next)

    return maxNode

for tc in range(1,T+1):
    N, start = map(int,input().split())
    inData = list(map(int,input().split()))
    myGraph = [[] for _ in range(101)]
    for i in range(N//2):
        myGraph[inData[i*2]].append(inData[i*2+1])
    checkMap = [False for _ in range(101)]
    print("#{0} {1}".format(tc,getResult()))