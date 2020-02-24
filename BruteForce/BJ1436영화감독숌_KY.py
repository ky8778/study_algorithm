N = int(input())

def isFinal(n):
    cnt = 0
    while n>0:
        if n%10==6:
            cnt+=1
        else:
            cnt=0
        if cnt>=3:
            return 1
        n//=10
    return 0


def getResult():
    cnt = 0
    number = 665
    while cnt < N:
        number+=1
        cnt += isFinal(number)
        
    return number

print(getResult())