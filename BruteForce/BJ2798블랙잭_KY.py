#! 2020.02.22
# TODO BJ2798_블랙잭
N, M = map(int,input().split())
cards = list(map(int,input().split()))

def blackJack(idx,prev,sum):
    if sum > M:
        return 0
    if idx >= 3:
        return sum
    else:
        maxRet = -1
        for i in range(prev+1,N):
            tmpRet = blackJack(idx+1,i,sum+cards[i])
            if tmpRet>maxRet:
                maxRet = tmpRet
        return maxRet

print(blackJack(0,-1,0))