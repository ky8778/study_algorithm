
#! 2020.02.03
# TODO BJ2605

N = int(input())
inputData = list(map(int,input().split()))

result = []
result.append(1)
for i in range(1,N):
    idx = i-inputData[i]
    result.append(i+1)
    for n in range(i,idx,-1):
        result[n], result[n-1] = result[n-1],result[n]
    # print(idx,i, result)

for i in result:
    print(i,end=' ')