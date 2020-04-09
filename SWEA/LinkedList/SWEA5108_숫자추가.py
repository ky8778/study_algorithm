# TODO LinkedList
# TODO SWEA5108_숫자추가
#! 2020.04.09
import sys
sys.stdin = open('sample_input.txt', 'r')

T = int(input())

class SingleLinkedList:
    class Node:
        def __init__(self, item, link):             # 노드 생성자
            self.item = item                        # 저장 항목
            self.next = link                        # 다음 노드 레퍼런스

    def __init__(self):                             # 단순연결리스트 생성자
        self.head = None                            # head
        self.size_list = 0                               # 항목 수

    def size(self): return self.size_list
    
    def is_empty(self): return self.size_list == 0
    
    def insert_front(self, item):
        if self.is_empty():                         # 첫 노드로 삽입
            self.head = self.Node(item, None)       # head가 새 노드 참조
        else:
            self.head = self.Node(item, self.head)
        self.size_list += 1

    def insert_after(self, item, p):                # p 다음에 삽입
        p.next = SingleLinkedList.Node(item, p.next)
        self.size_list += 1

    def delete_front(self):
        try:
            if self.is_empty():                         # 첫 노드 삭제
                raise EmptyError('Underflow')
            else:
                self.head = self.head.next
                self.size_list -= 1
        except:
            print("값을 잘못 입력하였습니다.")

    def delete_after(self, p):                      # p 다음 노드 삭제
        try:
            if self.is_empty():                         # 비어있는 경우
                raise EmptyError('Underflow')
            t = p.next
            p.next = t.next                             # p 다음 노드를 건너뛰어 연결
            self.size_list -= 1
        except:
            print("값을 잘못 입력하였습니다.")

    def search(self, target):                       # target 탐색
        p = self.head                               # head 로부터 순차 탐색
        for k in range(self.size_list):
            if target == p.item: return k           # 탐색 성공
            p = p.next
        return None                                 # 탐색 실패

    def print_list(self):                           # 연결리스트 출력
        p = self.head
        while p:
            if p.next != None:
                print(p.item, ' -> ', end='')
            else:
                print(p.item)
            p = p.next                              # 노드들을 순차 탐색

def getResult():
    myList = SingleLinkedList()
    for i in range(N-1,-1,-1):
        myList.insert_front(inList[i])
    # myList.print_list()
    for _ in range(M):
        idx, val = map(int, input().split())
        if idx == 0:
            myList.insert_front(val)
        else:
            new = myList.head
            for _ in range(idx - 1):
                new = new.next
            myList.insert_after(val,new)
    # myList.print_list()

    ret = myList.head
    for _ in range(L):
        ret = ret.next
    return ret.item

for tc in range(1,T+1):
    N, M, L = map(int, input().split())
    inList = list(map(int, input().split()))
    print("#{0} {1}".format(tc,getResult()))
