# 2021.08.30

def getNumberStr(s):
    ret = ''
    numbers = {'zero':'0','one':'1', 'two':'2', 'three':'3', 'four':'4', 'five':'5', 'six':'6', 'seven':'7', 'eight':'8', 'nine':'9'}
    
    idx = 0
    tmp = ''
    while idx < len(s):
        if s[idx].isdigit():
            ret += s[idx]
        else:
            tmp += s[idx]
        if tmp in numbers.keys():
            ret += numbers[tmp]
            tmp = ''
        idx += 1
        
    return ret

def solution(s):
    answer = 0
    tmp = getNumberStr(s)
    nth = 1
    
    for i in range(len(tmp)-1, -1, -1):
        answer += int(tmp[i]) * nth
        nth *= 10
    
    return answer