# class node:
#     def __init__(self,data):
#         self.data = data
#         self.left = None
#         self.right = None
#     def insert(self,data):
#         if data < self.data:
#             if self.left is None:
#                 self.left = node(data)
#             else:
#                 self.left.insert(data)
#         elif data > self.data:
#             if self.right is None:
#                 self.right = node(data)
#             else :
#                 self.right.insert(data)
#     def PrintTree(self):
#         if self.left:
#             self.left.PrintTree()
#         print(self.data)
#         if self.right:
#             self.right.PrintTree()
#     def InoderTraversal(self,root):
#         res = [] 
#         if root:
#             res = self.InoderTraversal(root.left)
#             res.append(root.data)
#             res = res + self.InoderTraversal(root.right)
#         return res
#     def PreoderTranversal(self,root):
#         res = [] 
#         if root:
#             res.append(root.data)
            
# root = node(27)
# root.insert(14)
# root.insert(35)
# root.insert(10)
# root.insert(19)
# root.insert(31)
# root.insert(42)
# root.PrintTree()

# print("Inoder Tranversal Display : ",root.InoderTraversal(root))
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, data):
        if data < self.data:
            if self.left is None:
                self.left = Node(data)
            else:
                self.left.insert(data)
        elif data > self.data:
            if self.right is None:
                self.right = Node(data)
            else:
                self.right.insert(data)

    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.data, end=' ')
        if self.right:
            self.right.print_tree()

    def inorder_traversal(self, root):
        res = []
        if root:
            res = self.inorder_traversal(root.left)
            res.append(root.data)
            res = res + self.inorder_traversal(root.right)
        return res

    def preorder_traversal(self, root):
        res = []
        if root:
            res.append(root.data)
            res = res + self.preorder_traversal(root.left)
            res = res + self.preorder_traversal(root.right)
        return res

    def postorder_traversal(self, root):
        res = []
        if root:
            res = self.postorder_traversal(root.left)
            res = res + self.postorder_traversal(root.right)
            res.append(root.data)
        return res

    def min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def delete_node(self, root, key):
        if root is None:
            return root

        if key < root.data:
            root.left = self.delete_node(root.left, key)
        elif key > root.data:
            root.right = self.delete_node(root.right, key)
        else:
            # Node with only one child or no child
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            
            # Node with two children: Get the inorder successor (smallest in the right subtree)
            temp = self.min_value_node(root.right)
            root.data = temp.data
            root.right = self.delete_node(root.right, temp.data)
        
        return root

# Example usage
root = Node(27)
root.insert(14)
root.insert(35)
root.insert(10)
root.insert(19)
root.insert(31)
root.insert(42)

print("Original tree (inorder):", root.inorder_traversal(root))
print("Original tree (preorder):", root.preorder_traversal(root))
print("Original tree (postorder):", root.postorder_traversal(root))

# Delete a node and print tree
key_to_delete = 19
root = root.delete_node(root, key_to_delete)

print(f"\nTree after deleting node with key {key_to_delete} (inorder):", root.inorder_traversal(root))
print("Tree after deleting node (preorder):", root.preorder_traversal(root))
print("Tree after deleting node (postorder):", root.postorder_traversal(root))

# Print the tree
print("\nTree structure:")
root.print_tree()
