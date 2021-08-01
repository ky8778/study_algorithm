class Node():
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


class AVLTree():
    def __init__(self, *args):
        self.node = None 
        self.height = -1
        self.balance = 0; 
        
        if len(args) == 1:
            for i in args[0]: 
                self.Insert(i)
    
    def IsLeaf(self):
        return (self.height == 0)
    
    def Insert(self, key):
        '''
        Insert Node
        '''
        new_node = Node(key)
        now = self.node
        if now == None:
            self.node = new_node
            self.node.left = AVLTree()
            self.node.right = AVLTree()
            print("Inserted key [" + str(key) + "]")
        elif key < now.key: 
            now.left.Insert(key)
        elif key > now.key: 
            now.right.Insert(key)
        else: 
            print("Key [" + str(key) + "] already in tree.")
        self.Rebalance() 
        
    def Delete(self, key):
        '''
        Delete Node
        '''
        now = self.node
        if now != None: 
            if now.key == key: 
                print("Deleting ... " + str(key))  
                if now.left.node == None and now.right.node == None:
                    now = None
                elif now.left.node == None: 
                    now = now.right.node
                elif now.right.node == None: 
                    now = now.left.node
                else:  
                    replacement = self.LogicalSuccessor(now)
                    if replacement != None:
                        print("Found replacement for " + str(key) + " -> " + str(replacement.key))  
                        now.key = replacement.key 
                        now.right.Delete(replacement.key)
            elif key < now.key: 
                now.left.Delete(key)  
            elif key > now.key: 
                now.right.Delete(key)
            self.Rebalance()
        else: 
            return 

    def LogicalPredecessor(self, node):
        ''' 
        Find the biggest valued node in LEFT child
        ''' 
        node = node.left.node 
        if node != None: 
            while node.right != None:
                if node.right.node == None: 
                    return node 
                else: 
                    node = node.right.node  
        return node 
    
    def LogicalSuccessor(self, node):
        ''' 
        Find the smallese valued node in RIGHT child
        ''' 
        node = node.right.node  
        if node != None: # just a sanity check  
            
            while node.left != None:
                print("LS: traversing: " + str(node.key))
                if node.left.node == None: 
                    return node 
                else: 
                    node = node.left.node  
        return node

    def Rebalance(self):
        ''' 
        Rebalance a particular (sub)tree
        ''' 
        # key inserted. Let's check if we're balanced
        self.UpdateHeights(False)
        self.UpdateBalances(False)
        # 현재 노드(루트, U)의 BF 절대값이 2 이상이면
        # 불균형트리이므로 rotation 수행
        while self.balance < -1 or self.balance > 1:
            # U의 Balance Factor가 2 이상이면
            # U의 왼쪽 서브트리 높이가 오른쪽보다 크므로
            # 시나리오1 혹은 시나리오2에 해당
            if self.balance > 1:
                # U의 왼쪽 자식노드의 왼쪽 서브트리보다
                # 오른쪽 서브트리의 높이가 클 경우 시나리오2에 해당
                # 우선 single left rotation
                if self.node.left.balance < 0:  
                    self.node.left.LRotate()
                    # rotation이 됐으므로 BF 업데이트
                    self.UpdateHeights()
                    self.UpdateBalances()
                # U의 왼쪽 자식노드의 왼쪽 서브트리가
                # 오른쪽 서브트리보다 높이가 클 경우 시나리오1에 해당
                # single right rotation (시나리오2도 이 작업 수행)
                self.RRotate()
                # rotation이 됐으므로 BF 업데이트
                self.UpdateHeights()
                self.UpdateBalances()
            
            # U의 Balance Factor가 -1 이하이면
            # U의 오른쪽 서브트리 높이가 왼쪽보다 크므로
            # 시나리오3 혹은 시나리오4에 해당
            if self.balance < -1:
                # U의 오른쪽 자식노드의 오른쪽 서브트리보다
                # 왼쪽 서브트리의 높이가 클 경우 시나리오3에 해당
                # 우선 single right rotation
                if self.node.right.balance > 0:  
                    self.node.right.RRotate()
                    # rotation이 됐으므로 BF 업데이트
                    self.UpdateHeights()
                    self.UpdateBalances()
                # U의 오른쪽 자식노드의 왼쪽 서브트리보다
                # 오른쪽 서브트리보다 높이가 클 경우 시나리오4에 해당
                # single left rotation (시나리오2도 이 작업 수행)
                self.LRotate()
                # rotation이 됐으므로 BF 업데이트
                self.UpdateHeights()
                self.UpdateBalances()

    def RRotate(self):
        # Rotate left pivoting on self
        print ('Rotating ' + str(self.node.key) + ' right') 
        A = self.node 
        B = self.node.left.node 
        T = B.right.node 
        self.node = B 
        B.right.node = A 
        A.left.node = T 

    def LRotate(self):
        # Rotate left pivoting on self
        print ('Rotating ' + str(self.node.key) + ' left') 
        A = self.node 
        B = self.node.right.node 
        T = B.left.node 
        
        self.node = B 
        B.left.node = A 
        A.right.node = T 
        
    def UpdateHeights(self, recurse=True):
        if self.node == None:
            self.height = -1
        else: 
            if recurse: 
                if self.node.left != None: 
                    self.node.left.UpdateHeights()
                if self.node.right != None:
                    self.node.right.UpdateHeights()
            self.height = max(self.node.left.height, self.node.right.height) + 1 
            
    def UpdateBalances(self, recurse=True):
        if self.node == None:
            self.balance = 0
        else: 
            if recurse: 
                if self.node.left != None: 
                    self.node.left.UpdateBalances()
                if self.node.right != None:
                    self.node.right.UpdateBalances()
            self.balance = self.node.left.height - self.node.right.height

    def CheckBalanced(self):
        if self == None or self.node == None: 
            return True
        
        # We always need to make sure we are balanced 
        self.UpdateHeights()
        self.UpdateBalances()
        return ((abs(self.balance) < 2) and self.node.left.CheckBalanced() and self.node.right.CheckBalanced())  
        
    def InorderTraverse(self):
        if self.node == None:
            return [] 
        
        inlist = [] 
        l = self.node.left.InorderTraverse()
        for i in l: 
            inlist.append(i) 

        inlist.append(self.node.key)

        l = self.node.right.InorderTraverse()
        for i in l: 
            inlist.append(i) 
    
        return inlist 

    def Display(self, level=0, pref=''):
        '''
        Display the whole tree. Uses recursive def.
        TODO: create a better display using breadth-first search
        '''        
        self.UpdateHeights()  # Must update heights before balances 
        self.UpdateBalances()
        if(self.node != None): 
            print('-' * level * 2, pref, self.node.key, "[" + str(self.height) + ":" + str(self.balance) + "]", 'L' if self.IsLeaf() else ' ')
            if self.node.left != None: 
                self.node.left.Display(level + 1, '<')
            if self.node.left != None:
                self.node.right.Display(level + 1, '>')
        

# Usage example
if __name__ == "__main__": 
    a = AVLTree()
    print("----- Inserting -------")
    # inlist = [5, 2, 12, -4, 3, 21, 19, 25]
    inlist = [7, 5, 2, 6, 3, 4, 1, 8, 9, 0]
    for i in inlist: 
        a.Insert(i)
        a.Display()

    a.Display()
    
    print("----- Deleting -------")
    a.Delete(3)
    a.Delete(4)
    # a.Delete(5) 
    a.Display()
    
    print("Input            :" + str(inlist))
    print("deleting ...       " + str(3))
    print("deleting ...       " + str(4))
    print("Inorder traversal:" + str(a.InorderTraverse()))