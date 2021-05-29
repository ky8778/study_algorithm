from collections import defaultdict
from bisect import bisect_left, bisect_right

def solution(words, queries):
    answer = []
    my_words = defaultdict(list)
    my_reverse_words = defaultdict(list)

    # 길이별로 딕셔너리에 담습니다
    for word in words:
        my_words[len(word)].append(word)
        my_reverse_words[len(word)].append(word[::-1])

    # 딕셔너리를 정렬합니다. (그래야 이진탐색이 가능하기 때문입니다.)
    # O(NlogN)
    for my_word in my_words.values():
        my_word.sort()
    for my_reverse_word in my_reverse_words.values():
        my_reverse_word.sort()

    # 이미 확인한 쿼리
    Checked = defaultdict()

    # 이진탐색을 합니다
    # O(N * logM)
    for query in queries:
        # 중복 쿼리 Memoization
        if query in Checked:
            answer.append(Checked[query])
            continue
        # Binary Search
        print("query : " + query)
        if query[0] == '?': # 와일드카드 접두사인 경우
            target = my_reverse_words[len(query)]
            start, end = query[::-1].replace('?','a'), query[::-1].replace('?','z')
        else: # 와일드카드 접미사인 경우
            target = my_words[len(query)]
            start, end = query.replace('?','a'), query.replace('?','z')
        print(target)
        print("left : " + str(bisect_left(target, start)))
        print("right : " + str(bisect_right(target, end)))
        Checked[query] = bisect_right(target, end) - bisect_left(target, start)
        answer.append(Checked[query])

    return answer

print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"]))