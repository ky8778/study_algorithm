import sys
sys.stdin = open('input.txt', 'r')

N = int(input())
homes = list(map(int, input().split()))
homes.sort()

if N % 2 == 0:
    print(homes[N//2 - 1])
else:
    print(homes[N//2])