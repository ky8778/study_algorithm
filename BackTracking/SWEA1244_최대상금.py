#! 2020.03.05
# TODO SWEA1244_최대상금
T = int(input())

def getSet():
    for n1 in range(numCards-1):
        for n2 in range(n1+1,numCards):
            mySet.append([n1,n2])

def getResult(prev,idx):
    if idx>=turns:
        tmp = int(''.join(cards))
        return tmp
    maxRet = -1
    for i in range(prev+1,numSet):
        idx1,idx2 = mySet[i][0],mySet[i][1]
        cards[idx1],cards[idx2] = cards[idx2],cards[idx1]
        maxRet = max(maxRet,getResult(i,idx+1))
        cards[idx1],cards[idx2] = cards[idx2],cards[idx1]
    return maxRet        

for tc in range(1,T+1):
    cards, turns = map(int,input().split())
    cards = list(str(cards))
    numCards = len(cards)
    mySet = []
    getSet()
    numSet = len(mySet)
    print("#{0} {1}".format(tc,getResult(-1,0)))