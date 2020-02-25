#! 2020.02.25
#TODO BJ1268임시반장정하기
'''
풀이
1. 각 학생마다 같은반이었던 학생이 총 몇명인지 찾는다. (getResult 함수)
2. 학년마다 해당 학생과 같은반이었던 학생이 있는지 체크한다. (checkClass 함수)
2-1. 같은반인 학생이라면 students라는 bool 배열을 True로 만들어 체크하고 cnt를 1 증가시킨다.
2-2. 이미 같은반이었다면 더이상 체크하지 않는다.
2-3. 모든 비교가 끝나면 cnt를 반환한다.
3. 가장 같은반이었던 학생이 많은 학생의 번호를 반환한다. (getResult 함수)
'''
N = int(input())
inData = []

def checkClass(idx,stus):
    cnt = 0
    for grade in range(5):
        for i in range(N):
            if not stus[i] and inData[i][grade]==inData[idx][grade]:
                stus[i] = True
                cnt+=1
    return cnt

def getResult():
    maxRet = -1
    result = -1

    for i in range(N):
        students = [False]*N
        students[i] = True
        tmp = checkClass(i,students)
        if tmp > maxRet:
            maxRet = tmp
            result = i

    return result+1

for i in range(N):
    tmpData = list(map(int,input().split()))
    inData.append(tmpData)

print(getResult())

''' 첫번째 풀이 : 딕셔너리를 만들어서 같은반 학생이 몇명인지 체크. 이 문제의 경우 1~5학년 동안 같은반이었던 적이 있었던 학생이 몇명인지 체크하는 것이므로 여러번 같은반 이었던 건 의미가 없음.
N = int(input())
inData = []
myDict = []

def makeTable():
    for grade in range(5):
        tmpDict = {}
        for i in range(N):
            classIdx = inData[i][grade]
            if classIdx in tmpDict:
                tmpDict[classIdx] += 1
            else:
                tmpDict[classIdx] = 1
        myDict.append(tmpDict)

def getResult():
    makeTable()
    result = -1
    maxNum = -1
    
    for i in range(N):
        cnt = 0
        for grade in range(5):
            classIdx = inData[i][grade]
            cnt += (myDict[grade][classIdx]-1)
        
        if cnt>maxNum:
            maxNum = cnt
            result = i        
    
    return result

for i in range(N):
    tmpData = list(map(int,input().split()))
    inData.append(tmpData)

print(getResult()+1)
print(myDict)
'''