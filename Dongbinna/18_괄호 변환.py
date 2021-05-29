# 18. 괄호 변환
# 2020 카카오 신입 공채 1차
# https://programmers.co.kr/learn/courses/30/lessons/60058

import sys
sys.stdin = open('input.txt', 'r')

def check(p):
    tmp = []
    for s in p:
        if s == '(':
            tmp.append(s)
        elif s == ')':
            if len(tmp) == 0:
                return False
            else:
                tmp.pop()
    if len(tmp) > 0:
        return False
    else:
        return True

def solution(p):
    lenP = len(p)
    answer = ''
    # 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환한다.
    if lenP == 0:
        return answer
    
    # 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u,v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있다.
    u = v = ''
    cnt_left = cnt_right = 0
    for idx in range(lenP):
        if p[idx] == '(':
            cnt_left += 1
        else:
            cnt_right += 1
        if cnt_left == cnt_right:
            u = p[0:idx+1]
            v = p[idx+1:]
            break

    # print('u : ' + u)
    # print('v : ' + v)

    # 3-1 문자열 u가 올바른 괄호 문자열이라면
    if check(u):
        answer = u + solution(v)
    # 4. 문자열 urk 올바른 괄호 문자열이 아니라면
    else:
        answer = '('
        answer += solution(v)
        answer += ')'
        u = u[1:-1]
        for s in u:
            if s == '(':
                answer += ')'
            else:
                answer += '('

    return answer

for _ in range(3):
    print(solution(input()))

'''
"(()())()"
"()"
"()(())()"
'''