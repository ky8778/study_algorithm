# TODO LinkedList
# TODO SWEA5122_수열편집
#! 2020.04.09
import sys
sys.stdin = open('sample_input.txt', 'r')


class DoubleLinkedList:
    class Node:
        def __init__(self, item, prev, link):       # 노드 생성자
            self.item = item
            self.prev = prev                        # 앞 노드 레퍼런스
            self.next = link                        # 뒤 노드 레퍼런스

    def __init__(self):                             # 이중 연결리스트 생성자
        self.head = self.Node(None, None, None)
        self.tail = self.Node(None, None, None)
        self.head.next = self.tail
        self.size_list = 0                          # 항목 수

    def insert_before(self, p, item):               # p 앞에 삽입
        t = p.prev
        n = self.Node(item, t, p)                   # 새 노드 생성하여 n 이 참조
        p.prev = n                                  # 새 노드와 앞 노드 연결
        t.next = n                                  # 새 노드와 뒤 노드 연결
        self.size_list += 1

    def insert_after(self, p, item):                # p 다음에 삽입
        t = p.next
        n = self.Node(item, p, t)
        t.prev = n
        p.next = n
        self.size_list += 1

    def delete(self, x):                            # x가 참조하는 노드 삭제
        f = x.prev
        r = x.next
        f.next = r                                  # x를 건너뛰고 x의 앞뒤 노드를 직접 연결
        r.prev = f
        self.size_list -= 1
        return x.item

    def change(self, x, item):
        t = x
        x.item = item

    def getItem(self, idx):
        p = self.head.next
        for _ in range(idx):
            if p == self.tail:
                return -1
            else:
                p = p.next
        return p.item

    def size(self): return self.size_list

    def is_empty(self): return self.size_list == 0

    def print_list(self):                           # 리스트 출력
        if self.is_empty():
            print('리스트 비어있음')
        else:
            p = self.head.next
            while p != self.tail:
                if p.next != self.tail:
                    print(p.item, ' <=> ', end='')
                else:
                    print(p.item)
                p = p.next                          # 노드들을 차레대로 방문


def getResult():
    my_list = DoubleLinkedList()
    for i in range(N-1,-1,-1):
        my_list.insert_after(my_list.head, in_list[i])
    # my_list.print_list()

    for _ in range(M):
        edit_list = list(input().split())
        # print(edit_list)
        new = my_list.head
        if edit_list[0] == 'I':
            for _ in range(int(edit_list[1])):
                new = new.next
            my_list.insert_after(new, int(edit_list[2]))
        elif edit_list[0] == 'D':
            for _ in range(int(edit_list[1]) + 1):
                new = new.next
            my_list.delete(new)
        elif edit_list[0] == 'C':
            new = my_list.head
            for _ in range(int(edit_list[1]) + 1):
                new = new.next
            my_list.change(new, int(edit_list[2]))
    # my_list.print_list()

    return my_list.getItem(L)


T = int(input())
for tc in range(1,T+1):
    N, M, L = map(int, input().split())
    in_list = list(map(int, input().split()))
    print("#{0} {1}".format(tc,getResult()))