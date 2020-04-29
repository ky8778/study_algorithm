# TODO Bit연산 > SWEA5185_이진수 (D2)
#! 2020.04.29

T = int(input())
hex_number = {'0': 0,'1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11, 'C': 12, 'D': 13, 'E': 14, 'F': 15}

def GetResult(n, str_num):
    ret = ''
    for i in range(n):
        number = hex_number[str_num[i]]
        tmp_ret = ''
        for j in range(3,-1,-1):
            bit = str((number >> j) & 1)
            tmp_ret += bit
        ret += tmp_ret
    return ret


for tc in range(1,T+1):
    N, input_number = map(str, input().split())
    N = int(N)
    print('#{0} {1}'.format(tc,GetResult(N,input_number)))