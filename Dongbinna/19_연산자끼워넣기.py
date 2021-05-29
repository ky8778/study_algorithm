import sys
sys.stdin = open('input.txt', 'r')

from itertools import permutations
inf = 9999999999

def solution(N, A, calcPer):
    minRet = inf
    maxRet = -inf
    for calc in calcPer:
        tmp = A[0]
        for n in range(N-1):
            if calc[n] == 0:
                tmp += A[n+1]
            elif calc[n] == 1:
                tmp -= A[n+1]
            elif calc[n] == 2:
                tmp *= A[n+1]
            elif calc[n] == 3:
                if tmp < 0:
                    tmp = -int(abs(tmp) / A[n+1])
                else:
                    tmp = int(tmp/A[n+1])
        minRet = min(minRet, tmp)
        maxRet = max(maxRet, tmp)
    return minRet, maxRet

N = int(input())
A = list(map(int, input().split()))
plus, minus, multi, div = map(int, input().split())
calcSet = [0 for _ in range(plus)] + [1 for _ in range(minus)] + [2 for _ in range(multi)] + [3 for _ in range(div)]
calcPer = list(set(permutations(calcSet, len(calcSet))))
minResult, maxResult = solution(N, A, calcPer)
print(maxResult)
print(minResult)