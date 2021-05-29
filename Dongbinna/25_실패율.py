def solution(N, stages):
    answer = []
    visited = [0 for _ in range(N)]
    notClear = [0 for _ in range(N)]
    for n in stages:
        if n == N+1:
            for i in range(n-1):
                visited[i] += 1
        else:
            notClear[n-1] += 1
            for i in range(n):
                visited[i] += 1
    
    for i in range(0, N):
        if visited[i] == 0:
            notClear[i] = (0, i+1)
            continue
        else:
            notClear[i] = (notClear[i]/visited[i], i+1)
    
    notClear.sort(key=lambda x:(-x[0],x[1]))
    answer = [notClear[i][1] for i in range(N)]
        
    return answer