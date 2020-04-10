# TODO LinkedList
# TODO SWEA5120_암호
#! 2020.04.10
import sys
sys.stdin = open('sample_input.txt','r')

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

T = int(input())

def insertBetween(in_list):
    start = in_list.head
    for _ in range(K):
        new = start.next
        for _ in range(M):
            if new == in_list.tail:
                new = in_list.head.next
            new = new.next
            
        if new == in_list.head.next:
            val = new.item + in_list.tail.prev.item
        elif new == in_list.tail:
            val = in_list.head.next.item + in_list.tail.prev.item
            new = in_list.tail
        else:
            val = new.item + new.prev.item
        start = new.prev
        in_list.insert_before(new, val)
        # in_list.print_list()

def setList():
    ret = DoubleLinkedList()
    for i in range(N-1,-1,-1):
        ret.insert_after(ret.head, input_list[i])
    
    return ret

def printReverse(in_list):
    now = in_list.tail
    cnt = 0
    while now != in_list.head.next:
        cnt += 1
        now = now.prev
        print(now.item, end=' ')
        if cnt >= 10:
            break
    print()

for tc in range(1,T+1):
    N, M, K = map(int, input().split())
    input_list = list(map(int, input().split()))
    my_list = setList()
    insertBetween(my_list)

    print("#{0}".format(tc),end=' ')
    printReverse(my_list)

