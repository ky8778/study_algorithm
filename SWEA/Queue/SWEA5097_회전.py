# TODO SWEA5097_회전 Queue
#! 2020.04.02
import sys
sys.stdin = open('sample_input.txt', 'r')

from queue import Queue

T = int(input())

def getResult():
    myQ = Queue()
    
    for i in numbers:
        myQ.put(i)

    for i in range(M):
        tmp = myQ.get()
        myQ.put(tmp)

    return myQ.get()



for tc in range(1,T+1):
    N, M = map(int,input().split())
    numbers = list(map(int,input().split()))
    print("#{0} {1}".format(tc, getResult()))