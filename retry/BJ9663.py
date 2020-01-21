# 20200121
# TODO: BJ9663 : https://www.acmicpc.net/problem/9663
''' 백트래킹 문제. 백트래킹 문제는 python 3로 풀지 않길 권장한다고 한다. python 3로 제출하면 시간초과 뜬다.
모든 언어에 대해 시간제한이 정확하지 않아서라고 한다. pypy3로 제출하면 정답처리된다.
하지만 기본적으로 알고리즘 구상을 처음에 2차원 맵으로 색칠하는 식으로 했는데 그건 비효율적이다.
그렇기 때문에 무작정 알고리즘을 아무렇게나 생각하는 습관을 고쳐야겠다는 생각이 들었다.'''

N = int(input())
queenMap = [0 for i in range(N)]
count = 0

def isPossible(rowIdx,colIdx):
    for i in range(rowIdx):
        if queenMap[i] == colIdx or abs(queenMap[i]-colIdx) == rowIdx-i:
            return False
    return True

def getResult(rowIdx):
    global count,queenMap

    if rowIdx >= N:
        count += 1
        return

    for j in range(N):
        if isPossible(rowIdx,j)==True:
            queenMap[rowIdx] = j
            getResult(rowIdx+1)
            

getResult(0)
print(count)