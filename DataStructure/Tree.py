class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree(object):
    def __init__(self):
        self.root = None

    def makeRoot(self, data):
        self.root = Node(data)

    def traversal(self):
        if self.root:
            return self.traversalNode(self.root)
        else:
            print("Tree is empty")
            return []

    def traversalNode(self, current_node):
        ret = []
        if current_node.left:
            ret.extend(self.traversalNode(current_node.left))
            ret.extend([current_node.data])
        if current_node.right:
            ret.extend(self.traversalNode(current_node.right))
        return ret
