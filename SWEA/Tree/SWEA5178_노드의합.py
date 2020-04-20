# TODO Tree
#! 2020.04.20

import sys
sys.stdin = open('sample_input.txt', 'r')

T = int(input())

for tc in range(1, T + 1):
    N, M, L = map(int, input().split())

    data_tree = [0 for _ in range(N + 1)]

    for _ in range(M):
        idx, val = map(int, input().split())
        data_tree[idx] = val

    for i in range(len(data_tree) - 1, 1, -1):
        data_tree[i//2] += data_tree[i]

    print("#{0} {1}".format(tc, data_tree[L]))