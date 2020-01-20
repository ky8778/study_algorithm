#! BJ9663 : https://www.acmicpc.net/problem/9663
N = int(input())
chess = [[0 for i in range(N)] for i in range(N)]

count = 0
dir = [(1,1),(1,-1),(0,-1),(1,0),(0,1)]

def copy(list1,list2):
    for i in range(N):
        for j in range(N):
            list1[i][j] = list2[i][j]

def getResult(num):
    global count,chess
    if num>=N:
        count+=1
        return
    else:
        for i in range(N):
            # print(chess)
            tmp_chess = [[chess[i][j] for i in range(N)] for j in range(N)]
            if chess[num][i] == 0:
                # print(tmp_chess)
                chess[num][i] = 1
                for dir_i in dir:
                    row = num
                    col = i
                    while 1:
                        row += dir_i[0]
                        col += dir_i[1]
                        if not(row>=0 and row<N and col>=0 and col<N):
                            break
                        chess[row][col] = 1
                getResult(num+1)
                chess = [[tmp_chess[i][j] for i in range(N)] for j in range(N)]

            # print(chess)

getResult(0)
print(count)
