
# TODO BJ2635 : https://www.acmicpc.net/problem/2635

inputData = int(input())

def getResult(inputNum):
    maxSecond = -1
    maxCnt = -1

    for i in range(0,inputNum+1):
        cnt = 0
        current = inputNum
        next = i

        while next >= 0:
            cnt += 1
            tmp = current
            current = next
            next = tmp - next

        if cnt > maxCnt:
            maxCnt = cnt
            maxSecond = i

    return maxSecond

result = []
result.append(inputData)
next = getResult(inputData)
while next >= 0:
    result.append(next)
    tmp = next
    next = inputData - tmp
    inputData = tmp

print(len(result))
for i in result:
    print(i,end=' ')


