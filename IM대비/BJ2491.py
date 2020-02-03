
#! 2020.02.03
# TODO BJ2491

N = int(input())
inputData = list(map(int,input().split()))

result = -1
length = 0
number = -1
for i in range(N):
    if number<=inputData[i]:
        length += 1
    else:
        if result < length:
            result = length
        length = 1
    number = inputData[i]

if result < length:
    result = length

length = 0
number = 20
for i in range(N):
    if number>=inputData[i]:
        length += 1
    else:
        if result < length:
            result = length
        length = 1
    number = inputData[i]

if result < length:
    result = length
print(result)