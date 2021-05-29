import sys
sys.stdin = open('input.txt', 'r')

from itertools import combinations
from copy import deepcopy

def check(myMap, y, x):
    # return go, See
    if myMap[y][x] == 'S':
        return False, True
    elif myMap[y][x] == 'O' or myMap[y][x] == 'T':
        return False, False
    else:
        return True, False

def solution(inputMap, N):
    myMap = deepcopy(inputMap)
    teachers = []
    blanks = []

    # 선생님, 빈칸 list 만들기
    for i in range(N):
        for j in range(N):
            if myMap[i][j] == 'T':
                teachers.append((i, j))
            elif myMap[i][j] == 'X':
                blanks.append((i, j))
    
    # 빈칸 3개 뽑는 조합 만들기
    combPick = list(combinations(blanks, 3))

    for pick in combPick:
        # 빈칸 3개에 장애물 만들기
        for location in list(pick):
            myMap[location[0]][location[1]] = 'O'

        # 선생님들이 감시할때 학생이 검출되는지 확인
        See = False
        for t in teachers:
            # 오른쪽
            if not See:
                y, x = t[0], t[1]
                while x < N-1:
                    x += 1
                    go, See = check(myMap, y, x)
                    if not go:
                        break
            # 왼쪽
            if not See:
                y, x = t[0], t[1]
                while x > 0:
                    x -= 1
                    go, See = check(myMap, y, x)
                    if not go:
                        break
            # 위쪽
            if not See:
                y, x = t[0], t[1]
                while y < N-1:
                    y += 1
                    go, See = check(myMap, y, x)
                    if not go:
                        break
            # 아래쪽
            if not See:
                y, x = t[0], t[1]
                while y > 0:
                    y -= 1
                    go, See = check(myMap, y, x)
                    if not go:
                        break
            # 만약 학생을 봤다면 더 확인할 필요 없음
            if See:
                break

        # 다 확인했는데 학생을 못봤으면 정답
        if not See:
            return 'YES'
        
        # 장애물 다시 치우기
        for location in list(pick):
            myMap[location[0]][location[1]] = 'X'

    return 'NO'

N = int(input())
inputMap = [list(input().split()) for _ in range(N)]
print(solution(inputMap, N))