# TODO LinkedList
# TODO SWEA5110_수열합치기
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

def setList(in_list):
    ret = DoubleLinkedList()
    for i in range(N-1,-1,-1):
        ret.insert_after(ret.head, in_list[i])
    
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

def mergeList(in_list1, in_list2):
    num2 = in_list2.head.next.item
    now1 = in_list1.head
    while True:
        now1 = now1.next
        if now1 == in_list1.tail:
            break
        elif now1.item > num2:
            break
    tmp1 = in_list2.head.next
    tmp2 = in_list2.tail.prev
    in_list2.head.next.prev = now1.prev
    in_list2.tail.prev.next = now1
    now1.prev.next = tmp1    
    now1.prev = tmp2

for tc in range(1,T+1):
    N, M = map(int, input().split())
    my_list = []
    for _ in range(M):
        input_list = list(map(int, input().split()))
        input_linkedlist = setList(input_list)
        my_list.append(input_linkedlist)
    for i in range(1,M):
        # my_list[i].print_list()
        mergeList(my_list[0],my_list[i])

    print("#{0}".format(tc),end=' ')
    printReverse(my_list[0])

