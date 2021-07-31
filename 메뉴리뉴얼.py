from itertools import combinations

def can_make_course(_course, _order):
    for menu in _course:
        if menu not in _order:
            return False
    else:
        return True

def solution(orders, course):
    answer = []
    my_courses = {}
    # 1. orders 모두 탐색
    for i in range(len(orders)):
        # 2. orders[i]에서 가능한 course list 조합만들기
        for n in course:
            course_list = list(combinations(orders[i], n))
            # 3. course list 탐색
            for c in course_list:
                cnt = 0
                # 가능한 course list 중 course로 만들수 있는지 체크
                for order in range(i+1, len(orders)):
                    if can_make_course(c, orders[order]):
                        cnt += 1
                # 가장 많이 주문한 course로 update
                # print(str(c) + ' : ' + str(cnt))
                if cnt > 0:
                    if n in my_courses:
                        if cnt > my_courses[n][0][1]:
                            my_courses[n] = list()
                            my_courses[n].append((c, cnt))
                        elif cnt == my_courses[n][0][1]:
                            my_courses[n].append((c, cnt))
                    else:
                        my_courses[n] = list()
                        my_courses[n].append((c, cnt))

    for k in my_courses:
        for can_course, cnt in my_courses[k]:
            tmp_answer = ''
            can_course = sorted(can_course)
            for c in can_course:
                tmp_answer += c
            answer.append(tmp_answer)
    answer = sorted(answer)
    return answer

inputs = [[["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"],[2,3,4]]
, [["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"],[2,3,5]]
, [["XYZ", "XWY", "WXA"],[2,3,4]]]

outputs = [["AC", "ACDE", "BCFG", "CDE"], ["ACD", "AD", "ADE", "CD", "XYZ"], ["WX", "XY"]]

for i in range(3):
    print('=============================')
    print(solution(inputs[i][0], inputs[i][1]))
    print(outputs[i])