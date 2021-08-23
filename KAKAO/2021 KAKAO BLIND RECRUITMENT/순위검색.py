# 2021.08.23
''' solution2
1. info 데이터를 4차원배열로 담는다. [언어][직군][경력][소울푸드]
2. 모든 배열을 sorting
3. query 의 조건을 idx로 삼아 부합하는 배열에서 score로 이진탐색해서 숫자 구하기'''
def binary_search(arr, n):
    if len(arr) == 0:
        return 0
    start = 0
    end = len(arr) - 1
    if arr[start] >= n:
        return len(arr)
    if arr[end] < n:
        return 0
    
    while start + 1 < end:
        mid = int((start + end)/2)
        if arr[mid] >= n:
            end = mid
        else:
            start = mid
        
    return len(arr) - start - 1

def solution(info, query):
    answer = []
    # [언어][직군][경력][소울푸드]
    info_list = [[[[[] for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(3)]
    my_dict = {'cpp': 0, 'java':1, 'python':2, 'backend':0,'frontend':1, 'junior':0, 'senior':1, 'pizza':0, 'chicken':1, '-': 4}
    for s in info:
        lan, end, nior, soul, score = map(str, s.split())
        info_list[my_dict[lan]][my_dict[end]][my_dict[nior]][my_dict[soul]].append(int(score))

    for i in range(3):
        for j in range(2):
            for n in range(2):
                for m in range(2):
                    info_list[i][j][n][m].sort()
    
    # print(info_list)
    for q in query:
        lan, end, nior, last = map(str, q.split(' and '))
        soul, score = map(str, last.split())
        cnt = 0
        for i in range(3):
            if lan != '-' and my_dict[lan] != i:
                continue
            for j in range(2):
                if end != '-' and my_dict[end] != j:
                    continue
                for n in range(2):
                    if nior != '-' and my_dict[nior] != n:
                        continue
                    for m in range(2):
                        if soul != '-' and my_dict[soul] != m:
                            continue
                        # print(lan + ' ' + end + ' ' + nior + ' ' + soul)
                        cnt += binary_search(info_list[i][j][n][m], int(score))
        answer.append(cnt)
    return answer

print(solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"], ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]))

'''solution1.
1. 문자열 리스트로 table 처럼 data를 받는다.
2. binary search 로 점수 > 직군 > 경력 > 소울푸드 > 언어 순으로 이진탐색한다.
- 여기서 후보 리스트를 줄여가며 정렬 > binary search 하는 형식으로 탐색)
> 실패. 효율성 시간초과
def binary_search1(arr, n):
    start = 0
    end = len(arr) - 1
    if arr[start][4] >= n:
        return arr
    if arr[end][4] < n:
        return []
    
    while start + 1 < end:
        mid = int((start + end)/2)
        if arr[mid][4] >= n:
            end = mid
        else:
            start = mid
        
    return arr[start+1:]

def binary_search2(arr, s, idx):
    if len(arr) == 0:
        return []
    
    start = 0
    end = len(arr) - 1
    if arr[start][idx] == s:
        return arr
    if arr[end][idx] != s:
        return []
    
    while start + 1 < end:
        mid = int((start + end)/2)
        if arr[mid][idx] == s:
            end = mid
        else:
            start = mid
            
    return arr[start+1:]

def solution(info, query):
    answer = []
    # 1. make info_list
    info_list = []
    for s in info:
        lan, end, nior, soul, score = map(str, s.split())
        info_list.append([lan, end, nior, soul, int(score)])
    # print(info_list)
    
    # 2. query
    for q in query:
        lan, end, nior, last = map(str, q.split(' and '))
        soul, score = map(str, last.split())
        check = []
        check.append(end)
        check.append(nior)
        check.append(soul)
        
        info_list.sort(key=lambda score: score[4])
        tmp = binary_search1(info_list, int(score))
        for i in range(3):
            if check[i] != '-':
                if check[i] == 'backend' or check[i] == 'junior' or check[i] == 'chicken':
                    tmp.sort(key=lambda score: score[i+1], reverse=True)
                else:
                    tmp.sort(key=lambda score: score[i+1])
                # print(tmp)
                tmp = binary_search2(tmp, check[i], i+1)
            # print(check[i])
            # print(tmp)
        cnt = 0
        for t in tmp:
            if t[0] == lan or lan == '-':
                cnt += 1
        answer.append(cnt)
    
    return answer

'''