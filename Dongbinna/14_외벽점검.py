# 2021.03.20 외벽 점검
# 2020 카카오 신입 공채 1차
# https://programmers.co.kr/learn/courses/30/lessons/60062

import sys
sys.stdin = open('input.txt', 'r')

''' 풀이
1. 사람을 보낼 순서를 정한다. 순열 최대 O(8!)
2. 순서 set에 따라 시작위치를 변경하며 점검을 시킨다. => 시작위치 경우의 수 최대 O(15) * 사람 움직이며 확인 최대 O(8)
    겹치지 않게 한명씩 순서대로 출발점에서부터 점검시킨다고 생각.
3. 전부 점검이 되었다면 최소 사람수와 비교하여 업데이트.
최대 O(8!) * O(15) * O(8) = O(5,000,000)
'''

from itertools import permutations

def check(n, weak, turn, startPoint):
    cnt = 0
    tmp = []
    nextStart = startPoint
    # print("======================================")
    # print("시작점 : " + str(weak[nextStart]))
    for howFar in list(turn):               # 순서대로 움직이는 loop
        cnt += 1
        # print(str(cnt) + "번째 사람 " + str(howFar) + "만큼 점검 시작")
        # 1. 이번 사람이 점검을 시작할 위치 (nextStart)는 점검했다고 치고, 다음 weak를 점검할 수 있는지 확인
        while howFar >= 0:
            # print("현재위치는 " + str(weak[nextStart]) + " 입니다.")
            currentStart = nextStart
            tmp.append(weak[currentStart])
            if len(tmp) >= len(weak):
                return cnt
            nextStart = (nextStart + 1) % len(weak)
            term = weak[nextStart] - weak[currentStart]
            if term < 0:
                term += n
            # print("다음까지의 거리는 " + str(term))
            howFar -= term
    return 9999

def solution(n, weak, dist):
    orderDistPermutation = list(permutations(dist, len(dist))) # 사람 보내는 순서
    # print(orderDist)
    answer = 9999
    for turn in orderDistPermutation:                          # 순서 순열 loop
        for startPoint in range(len(weak)):
            answer = min(answer, check(n, weak, turn, startPoint))
    if answer >= 9000:
        answer = -1
    return answer

N = int(input())
Weak = list(map(int, input().split()))
Dist = list(map(int, input().split()))
print("my result is " + str(solution(N, Weak, Dist)))
print(8*7*6*5*4*6*15*8)

''' 오답
def canComplete(_n, _person, _weak, _memRet):
    newMem = []
    # 경우의 수 모두 탐색
    for mem in _memRet:
        for w in range(len(_weak)):
            if _weak[w] not in mem:
                start = w
                end = (_weak[start] + _person) % _n
                while end not in _weak:
                    end -= 1
                    if end < 0:
                        end += _n
                tmp1 = []
                while _weak[start] != end:
                    if _weak[start] not in mem:
                        tmp1.append(_weak[start])
                    start = (start + 1) % len(_weak)
                if end not in mem:
                    tmp1.append(end)
                if len(tmp1) + len(mem) >= len(_weak):
                    return True, newMem

                # end = ((_weak[start] - _person) + _n) % _n
                # while end not in _weak:
                #     end = (end + 1) % _n
                # tmp2 = []
                # while _weak[start] != end:
                #     if _weak[start] not in mem:
                #         tmp2.append(_weak[start])
                #     start -= 1
                #     if start < 0:
                #         start += len(_weak)
                # if end not in mem:
                #     tmp2.append(end)

                # if len(tmp2) + len(mem) >= len(_weak):
                #     return True, newMem

                if len(tmp1) != 0:
                    tmp1 += mem
                    tmp1.sort()
                    if tmp1 not in newMem:
                        newMem.append(tmp1)
                    
                # if len(tmp2) != 0:
                #     tmp2 += mem
                #     tmp2.sort()
                #     if tmp2 not in newMem:
                #         newMem.append(tmp2)
                
    return False, newMem

def solution(n, weak, dist):
    answer = 0
    # 먼저 dist 정렬
    dist.sort(reverse=True)
    people = []

    memRet = [[]]
    for person in dist:
        answer += 1
        people.append(person)
        if person >= n:
            return answer
        result, memRet = canComplete(n, person, weak, memRet)
        # print(memRet)
        if result:
            return answer

    return -1
'''