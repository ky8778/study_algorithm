# 2021.04.24
import math

def IsPrime(num):
    if num == 1:
        return False

    for i in range(2, int(math.sqrt(num))+1):
        if num % i == 0:
            return False

    return True

def DFS(ans, number, now, n):
    # print(number)
    if len(number) == 0 or IsPrime(int(number)):
        if now >= n:
            ans.append(int(number))
            return
        else:
            if now > 0:
                number += '0'
                DFS(ans, number, now+1, n)
                number = number[0:-1]
            for i in range(1, 10):
                number += str(i)
                DFS(ans, number, now+1, n)
                number = number[0:-1]

def solution(n):
    answer = []
    DFS(answer, '', 0, n)
    for n in answer:
        print(n)

N = int(input())
solution(N)