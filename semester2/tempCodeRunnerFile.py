class Node:
    def __init__(self, data, value):
        self.data = data
        self.value = value
        self.left = None
        self.right = None

    def insertNode(self, data, value):
        # Decide where to insert the new node based on data
        if data < self.data:
            if self.left is None:
                self.left = Node(data, value)
            else:
                self.left.insertNode(data, value)
        elif data > self.data:
            if self.right is None:
                self.right = Node(data, value)
            else:
                self.right.insertNode(data, value)

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(f"{self.data}: {self.value}", end=' ')
        if self.right:
            self.right.PrintTree()

# Example usage
aa = Node(12, "root")
aa.insertNode(1, "ehll")
aa.insertNode(4, 'b')
aa.insertNode(54, 'c')
aa.insertNode(6, 'd')
aa.insertNode(8, 'e')
aa.PrintTree()
