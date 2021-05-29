import sys
sys.stdin = open('input.txt', 'r')
import heapq

N = int(input())
myHeap = []
result = 0

for _ in range(N):
    heapq.heappush(myHeap, int(input()))

while len(myHeap) > 1:
    num1 = heapq.heappop(myHeap)
    num2 = heapq.heappop(myHeap)
    tmp_sum = (num1 + num2)
    result += tmp_sum
    heapq.heappush(myHeap, tmp_sum)

print(result)