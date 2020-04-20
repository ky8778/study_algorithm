# TODO Tree
#! 2020.04.20
import sys
sys.stdin = open('sample_input.txt', 'r')

T = int(input())

def getNumberOfSubtree(parent):
    if len(data_tree[parent]) <= 0:
        return 1
    else:
        cnt = 1
        for child in data_tree[parent]:
            cnt += getNumberOfSubtree(child)
        return cnt

for tc in range(1,T+1):
    E, N = map(int,input().split())
    data_tree = [[] for _ in range(E+2)]
    input_data = list(map(int,input().split()))
    
    for i in range(0,E*2,2):
        parent = input_data[i]
        child = input_data[i+1]
        data_tree[parent].append(child)
    
    print("#{0} {1}".format(tc,getNumberOfSubtree(N)))

