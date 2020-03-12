
#! 20200203
# TODO BJ14696

N = int(input())

A = [0,0,0,0]
B = [0,0,0,0]

def game(listA,listB):
    # print("A :",listA)
    # print("B :",listB)
    for i in range(3,-1,-1):
        if A[i]>B[i]:
            print('A')
            return
        elif A[i]<B[i]:
            print('B')
            return
    print('D')
    return


for n in range(N):
    for i in range(4):
        A[i] = 0
        B[i] = 0
    inA = list(map(int,input().split()))
    inB = list(map(int,input().split()))
    for aIdx,a in enumerate(inA):
        if aIdx != 0:
            A[a-1] += 1
    for bIdx,b in enumerate(inB):
        if bIdx != 0:
            B[b-1] += 1
    game(A,B)

'''
5
1 4
4 3 3 2 1
5 2 4 3 2 1
4 4 3 3 1
4 3 2 1 1
4 2 3 2 1
4 4 3 2 1
3 4 3 2
5 4 4 2 3 1
5 4 2 4 1 3
'''