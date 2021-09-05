# 2021.08.30

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def inRange(y, x):
    if y<5 and y>=0 and x>=0 and x<5:
        return True
    else:
        return False

def check(place, isvisited, y, x, d):
    if d == 0:
        return True

    for dir in range(4):
        yy = y + dy[dir]
        xx = x + dx[dir]

        if inRange(yy, xx) and not isvisited[yy][xx]:
            if place[yy][xx] == 'O':
                isvisited[yy][xx] = True
                if not check(place, isvisited, yy, xx, d-1):
                    return False
                isvisited[yy][xx] = False
            elif place[yy][xx] == 'P':
                return False
    return True

def isOK(place):
    isvisited = [[False for _ in range(5)] for _ in range(5)]

    for i in range(5):
        for j in range(5):
            if place[i][j] == 'P':
                isvisited[i][j] = True
                if not check(place, isvisited, i, j, 2):
                    return 0
                    
    return 1

def solution(places):
    answer = []
    for p in places:
        answer.append(isOK(p))

    return answer

input = [["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]
result = [1, 0, 1, 1, 1]
if solution(input) == result:
    print("SUCCESS")
else:
    print("FAIL")