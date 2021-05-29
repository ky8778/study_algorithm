# 2021.03.07 기둥과 보 설치
# 2020 카카오 신입 공채
# https://programmers.co.kr/learn/courses/30/lessons/60061

import sys
sys.stdin = open('input.txt', 'r')

KI = 0
BO = 1
DELETE = 0
BUILD = 1

def getMap(n, inMap, y, x, what):
    # 맵에서 벗어났으면
    if y<0 or x<0 or y>n or x>n:
        return 0
    # 있으면
    elif what in inMap[y][x]:
        return 1
    # 없으면
    else:
        return 0

def check(n, inMap, y, x, what):
    if getMap(n, inMap, y, x, what) == 0:
        return True

    ret = False
    if what == KI:
        # 바닥 위
        if y == 0:
            ret = True
        # 보의 한쪽 끝 부분 위에
        elif getMap(n, inMap, y, x-1, BO) == 1 or getMap(n, inMap, y, x, BO) == 1:
            ret = True
        # 다른 기둥위에
        elif getMap(n, inMap, y-1, x, KI) == 1:
            ret = True
    elif what == BO:
        # 양쪽 끝이 보로 연결
        if getMap(n, inMap, y, x-1, BO) == 1 and getMap(n, inMap, y, x+1, BO) == 1:
            ret = True
        # 보의 한쪽 끝이 기둥 위에
        elif getMap(n, inMap, y-1, x, KI) == 1 or getMap(n, inMap, y-1, x+1, KI) == 1:
            ret = True
    return ret

def solution(n, build_frame):
    answer = []
    myMap = [[[] for _ in range(101)] for _ in range(101)]

    for currentBuild in build_frame:
        x, y, what, how = map(int, currentBuild)
        # print('y : ' + str(y) + ' x : ' + str(x) + ' what : ' + str(what) + ' how : ' + str(how))

        if how == DELETE:
            # 일단 myMap에서 지움
            myMap[y][x].remove(what)
            CAN_DELETE = False
            if what == KI:
                if check(n, myMap, y+1, x, KI) and check(n, myMap, y+1, x, BO) and check(n, myMap, y+1, x-1, BO) and check(n, myMap, y, x, BO) and check(n, myMap, y-1, x, KI) and check(n, myMap, y, x-1, BO):
                    CAN_DELETE = True
            elif what == BO:
                if check(n, myMap, y, x, KI) and check(n, myMap, y, x-1, BO) and check(n, myMap, y-1, x, KI) and check(n, myMap, y, x+1, KI) and check(n, myMap, y, x+1, BO) and check(n, myMap, y-1, x+1, KI):
                    CAN_DELETE = True
            # 지울 수 있으면 answer에서도 지움
            if CAN_DELETE == True:
                answer.remove([x, y, what])
            # 없으면 myMap 원복
            else:
                myMap[y][x].append(what)
        elif how == BUILD:
            # 일단 설치
            myMap[y][x].append(what)
            CAN_BUILD = False
            if check(n, myMap, y, x, what):
                CAN_BUILD = True
            # 설치할 수 있으면 answer에 넣음
            if CAN_BUILD:
                answer.append([x, y, what])
            # 없으면 myMap 원복
            else:
                myMap[y][x].remove(what)
        # print('answer : ' + str(answer))
        print(myMap)
    answer.sort()
    return answer

N1 = int(input())
BuildFrame1 = [list(map(int, input().split())) for _ in range(8)]
print(BuildFrame1)
result1 = [[1,0,0],[1,1,1],[2,1,0],[2,2,1],[3,2,1],[4,2,1],[5,0,0],[5,1,0]]
print('myResult : ' + str(solution(N1, BuildFrame1)))
print('result1 : ' + str(result1))

N2 = int(input())
BuildFrame2 = [list(map(int, input().split())) for _ in range(10)]
# result2 = [[0,0,0],[0,1,1],[1,1,1],[2,1,1],[3,1,1],[4,0,0]]
# print('myResult : ' + str(solution(N2, BuildFrame2)))
# print('result2 : ' + str(result2))