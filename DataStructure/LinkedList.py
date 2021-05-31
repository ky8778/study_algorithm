class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = Node(None)
        self.tail = Node(None)
        self.head.next = self.tail

    def Add(self, data):
        new_node = Node(data)
        node = self.head
        while node.next != self.tail:
            node = node.next
        node.next = new_node
        new_node.next = self.tail
    
    def Delete(self, data):
        prev = self.head
        node = self.head
        while node.data != data and node != self.tail:       # Find node
            prev = node
            node = node.next
        if node == self.tail:                                # node not exist
            print(f'{data} is not exist')
        else:                                           # node exist
            if node.next:                               # node != tail, prev -> tail
                prev.next = node.next
            else:                                       # node == tail
                prev.next = None

    def Find(self, data):
        node = self.head
        while node.data != data and node != self.tail:
            node = node.next
        if node == self.tail:
            print(f'{data} is not exist')
            return None
        else:
            return node
    
    def PrintAll(self):
        node = self.head
        while node.next != self.tail:
            node = node.next
            print(node.data)
        print('='*30)

my_list = LinkedList()
my_list.Add(1)
my_list.Add(2)
my_list.PrintAll()
my_list.Delete(2)
my_list.PrintAll()
my_list.Delete(3)
one = my_list.Find(1)
my_list.Delete(1)
one = my_list.Find(1)
print(one)
my_list.PrintAll()