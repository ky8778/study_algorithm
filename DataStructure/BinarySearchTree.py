class Node(object):
  def __init__(self, data):
    self.data = data
    self.left = self.right = None

class BinarySearchTree(object):
  def __init__(self):
    self.root = None

  def traversal(self):
    return self.traversalNode(self.root)
    
  def traversalNode(self, node):
    ret = []
    if node.left:
      ret.extend(self.traversalNode(node.left))
    ret.extend([node.data])
    if node.right:
      ret.extend(self.traversalNode(node.right))
    return ret

  def find(self, key):
    return self.findNode(self.root, key)

  def findNode(self, node, key):
    if node == None:
      print("Tree doesn't have this key")
      return False, None
    elif node.data == key:
      return True, node.data
    elif node.data > key:
      return self.findNode(node.left, key)
    else:
      return self.findNode(node.right, key)

  def insert(self, data):
    if self.root:
      self.insertNode(self.root, data)
    else:
      self.root = Node(data)

  def insertNode(self, node, data):
    if node.data > data:
      if node.left:
        self.insertNode(node.left, data)
      else:
        node.left = Node(data)
    else:
      if node.right:
        self.insertNode(node.right, data)
      else:
        node.right = Node(data)
  
  def delete(self, key):
    parent, node = self.root, self.root
    while node is not None and node.data != key:
      parent = node
      if key < node.data:
        node = node.left
      # search right
      elif key > node.data:
        node = node.right

    if node is None:
      return False
    else:
      # case3. left child, right child exist
      if node.left and node.right:
        successor_parent, successor = node, node.right
        # 1. find successor node at right subtree
        while successor.left is not None:
          successor_parent, successor = successor, successor.left
        # 2. delete successor node
        if successor.right:       # case2.
          successor_parent.left = successor.right
        else:                     # case1.
          successor_parent.left = None
        # 3. move successor node to delete node
        if parent.right == node:
          parent.right = successor
        else:
          parent.left = successor
        successor.left, successor.right = node.left, node.right
        
      # case2. left or right only one child exist
      elif node.left or node.right:
        # connect parent - child
        if parent.right == node:
          parent.right = node.left or node.right
        else:
          parent.left = node.left or node.right
      # case1. child not exist
      else:
        if parent.right == node:
          parent.right = None
        else:
          parent.left = None
      return True


array = [7, 4, 2, 3, 5, 17, 13, 15, 40, 30, 25, 27, 35, 50, 55, 52]
bst = BinarySearchTree()

for x in array:
  bst.insert(x)
print(bst.traversal())

# Find
print(bst.find(15)) # True
print(bst.find(17)) # True

# Delete
print(bst.delete(3)) # True
print(bst.delete(3)) # True
print(bst.traversal())

print(bst.delete(50)) # True
print(bst.traversal())

print(bst.delete(17)) # True
print(bst.traversal())