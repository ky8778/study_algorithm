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

    def find(self, data):
        if self.findNode(self.root, data):
            return True
        else:
            return False

    def findNode(self, current_node, data):
        if current_node == None:
            print("Tree doesn't have this data")
            return False
        elif current_node.data == data:
            return current_node
        elif current_node.data > data:
            return self.findNode(current_node.left, data)
        else:
            return self.findNode(current_node.right, data)

    def insert(self, data):
        if self.root:
            self.insertNode(self.root, data)
        else:
            self.makeRoot(data)

    def insertNode(self, current_node, data):
        if current_node.data > data:
            if current_node.left:
                self.insertNode(current_node.left, data)
            else:
                current_node.left = Node(data)
        else:
            if current_node.right:
                self.insertNode(current_node.right, data)
            else:
                current_node.right = Node(data)

    ''' need to update
    def delete(self, key):
        self.root, deleted = self.deleteValue(self.root, key)
        return deleted

    def deleteValue(self, node, key):
        if not self.root:
            return None, False

        deleted = False
        if key == node.data:
            deleted = True
            if node.left and node.right:
                parent, child = node, node.right
                while child.left is not None:
                    parent, child = child, child.left
                child.left = node.left
                if parent != node:
                    parent.left = child.right
                    child.right = node.right
                node = child
            elif node.left or node.right:
                node = node.left or node.right
            
        elif key < node.data:
            node.left, deleted = self._delete_value(node.left, key)
        else:
            node.right, deleted = self._delete_value(node.right, key)
        return node, deleted
    '''