N = int(input())

def getResult():
    for i in range(1,N):
        subSum = i
        inN = i
        while inN > 0:
            subSum += (inN%10)
            inN //= 10
        if subSum == N:
            return i
    return 0
    
print(getResult())