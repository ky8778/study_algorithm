N = int(input())
S = [list(map(int,input().split())) for _ in range(N)]
total = 0
teamMember = []

def getDist():
    s1 = 0
    s2 = 0
    checkMember = [False for _ in range(N)]
    for i in range(int(N/2)-1):
        for j in range(i+1,int(N/2)):
            p1 = teamMember[i]
            p2 = teamMember[j]
            checkMember[p1] = True
            checkMember[p2] = True
            s1+=(S[p1][p2]+S[p2][p1])

    for i in range(N-1):
        if not checkMember[i]:
            for j in range(i+1,N):
                if not checkMember[j]:
                    s2+=(S[i][j]+S[j][i])
            
    return abs(s2-s1)

def getResult(prev,n):
    if n>=int(N/2):
        return getDist()
    minRet = 987654321
    for i in range(prev+1,N):
        teamMember.append(i)
        minRet = min(minRet,getResult(i,n+1))
        teamMember.pop()
    return minRet

print(getResult(-1,0))