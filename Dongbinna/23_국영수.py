import sys
sys.stdin = open('input.txt', 'r')

N = int(input())
students = []
for n in range(N):
    tmp = list(map(str, input().split()))
    for i in range(3):
        tmp[i+1] = int(tmp[i+1])
    students.append(tmp)

students.sort(key=lambda x:(-x[1], x[2], -x[3], x[0]))

for n in range(N):
    print(students[n][0])