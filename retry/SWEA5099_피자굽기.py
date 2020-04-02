# TODO SWEA5099_피자굽기 Queue
#! 2020.04.02
import sys
sys.stdin=open("sample_input.txt",'r')
from queue import Queue

T = int(input())

def getResult(n,m):
    myQ = Queue()
    idx = -1
    for i in range(n):
        myQ.put([i+1,C[i]])
        idx = i+1

    while myQ.qsize() > 1:
        current = myQ.get()
        current[1] //= 2
        if current[1] != 0:
            myQ.put(current)
        else:
            if idx<m:
                myQ.put([idx+1,C[idx]])
                idx+=1
    
    ret = myQ.get()
    return ret[0]

for tc in range(1,T+1):
    N,M = map(int,input().split())
    C = list(map(int,input().split()))
    
    print("#{0} {1}".format(tc,getResult(N,M)))