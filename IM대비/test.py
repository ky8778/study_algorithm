snum=int(input())
slist=list(map(int, input().split()))
pnum = int(input())
plist=[list(map(int, input().split())) for _ in range(pnum)]

for n in range(pnum):
    if plist[n][0]==1:
        k=plist[n][1]
        while k<=len(slist):
            if slist[k-1]==0:
                slist[k-1]=1
            else: 
                slist[k-1]=0
            k+=plist[n][1]

    else:
        k=plist[n][1]
        i=1
        while True:
            if k-1-i<0:
                break
            if k+i >= len(slist):
                break
            if slist[k-1-i]==slist[k-1+i]:
                i+=1
            else:
                break
            if k-1-i==0 or k-1+i==len(slist):
                break
        
        for t in range(k-1-i,k+i):
            if slist[t]==0: slist[t]=1
            else: slist[t]=0

for idx,val in enumerate(slist):
    print(val,end=' ')
    if (idx+1)%20 == 0:
        print()
