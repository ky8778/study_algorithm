
# TODO BJ1244 : https://www.acmicpc.net/problem/1244

N = int(input())
status = list(map(int,input().split()))
M = int(input())

# print("current : {0}".format(status))

def changeSwitch(inputList,inGen,inNum):
    lenList = len(inputList)
    if inGen == 1:
        for idx in range(lenList):
            if (idx+1)%inNum == 0:
                inputList[idx] = (inputList[idx]+1) % 2

    elif inGen == 2:
        idx = inNum-1
        inputList[inNum-1] = (inputList[inNum-1]+1) % 2
        leftIdx = idx - 1
        rightIdx = idx + 1
        while leftIdx >= 0 and rightIdx < lenList:
            if inputList[leftIdx] == inputList[rightIdx]:
                inputList[leftIdx] = (inputList[leftIdx]+1) % 2
                inputList[rightIdx] = (inputList[rightIdx]+1) % 2
            else:
                break
            leftIdx -= 1
            rightIdx += 1

for m in range(M):
    gender, number = map(int, input().split())
    # print(gender,number)
    changeSwitch(status,gender,number)

for idx,val in enumerate(status):
    print(val,end=' ')
    if (idx+1)%20 == 0:
        print()