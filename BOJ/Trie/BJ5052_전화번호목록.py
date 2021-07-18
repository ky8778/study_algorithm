class Node(object):
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = {}

class Trie(object):
    def __init__(self):
        self.head = Node(None)
    
    def insert_search(self, string):
        curr_node = self.head
        for char in string:
            if char not in curr_node.children:
                curr_node.children[char] = Node(char)
            curr_node = curr_node.children[char]
            if curr_node.data:
                return False
        curr_node.data = string
        return True

def solution(phone_book):
    phone_book.sort()
    trie = Trie()
    for phone in phone_book:
        if not trie.insert_search(phone):
            return False
    return True

T = int(input())
for t in range(T):
    N = int(input())
    numbers = []
    for _ in range(N):
        numbers.append(input())
    if solution(numbers):
        print("YES")
    else:
        print("NO")