# 2021.07.25

def solution(new_id):
    answer = ''
    # step1
    new_id = new_id.lower()

    # step 2
    tmp = ''
    for c in new_id:
        if c.isalpha() or c.isdigit() or c == '-' or c=='_' or c == '.':
            tmp += c
    
    # step 3
    prev = ''
    for c in tmp:
        if c == '.':
            if prev != '.':
                answer += c
        else:
            answer += c
        prev = c

    # step 4
    if len(answer) > 0 and answer[0] == '.':
        answer = answer[1:]
    if len(answer) > 0 and answer[-1] == '.':
        answer = answer[:-1]
    
    # step 5
    if len(answer) <= 0:
        answer = 'a'
    
    # step 6
    if len(answer) >= 16:
        answer = answer[:15]
        if answer[-1] == '.':
            answer = answer[:-1]

    # step 7
    while len(answer) <= 2:
        answer += answer[-1]

    return answer

input = ["...!@BaT#*..y.abcdefghijklm", "z-+.^.", "=.=", "123_.def", "abcdefghijklmn.p"]
result = ["bat.y.abcdefghi", "z--", "aaa", "123_.def", "abcdefghijklmn"]
for i in range(len(input)):
    print(solution(input[i]))
    if solution(input[i]) != result[i]:
        print('NO')