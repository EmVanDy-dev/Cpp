# # from collections import deque

# # class Node:
# #     def __init__(self, value):
# #         self.value = value
# #         self.left = None
# #         self.right = None

# # class BinaryTree:
# #     def __init__(self):
# #         self.root = None

# #     def insert(self, value):
# #         if not self.root:
# #             self.root = Node(value)
# #         else:
# #             self._insert_recursive(self.root, value)

# #     def _insert_recursive(self, node, value):
# #         if value < node.value:
# #             if node.left is None:
# #                 node.left = Node(value)
# #             else:
# #                 self._insert_recursive(node.left, value)
# #         else:
# #             if node.right is None:
# #                 node.right = Node(value)
# #             else:
# #                 self._insert_recursive(node.right, value)

# #     def search(self, value):
# #         return self._search_recursive(self.root, value)

# #     def _search_recursive(self, node, value):
# #         if node is None:
# #             return False
# #         if node.value == value:
# #             return True
# #         elif value < node.value:
# #             return self._search_recursive(node.left, value)
# #         else:
# #             return self._search_recursive(node.right, value)

# #     def delete(self, value):
# #         self.root = self._delete_recursive(self.root, value)

# #     def _delete_recursive(self, node, value):
# #         if node is None:
# #             return node

# #         if value < node.value:
# #             node.left = self._delete_recursive(node.left, value)
# #         elif value > node.value:
# #             node.right = self._delete_recursive(node.right, value)
# #         else:
# #             # Node with the value to be deleted found
# #             if node.left is None:
# #                 return node.right
# #             elif node.right is None:
# #                 return node.left

# #             # Node with two children, get the inorder successor
# #             min_larger_node = self._get_min_value_node(node.right)
# #             node.value = min_larger_node.value
# #             node.right = self._delete_recursive(node.right, min_larger_node.value)

# #         return node

# #     def _get_min_value_node(self, node):
# #         current = node
# #         while current.left is not None:
# #             current = current.left
# #         return current

# #     def inorder_traversal(self):
# #         return self._inorder_recursive(self.root, [])

# #     def _inorder_recursive(self, node, values):
# #         if node:
# #             self._inorder_recursive(node.left, values)
# #             values.append(node.value)
# #             self._inorder_recursive(node.right, values)
# #         return values

# #     def bfs(self):
# #         if not self.root:
# #             return []

# #         result = []
# #         queue = deque([self.root])

# #         while queue:
# #             node = queue.popleft()
# #             result.append(node.value)
# #             if node.left:
# #                 queue.append(node.left)
# #             if node.right:
# #                 queue.append(node.right)

# #         return result

# #     def dfs(self):
# #         return self._dfs_recursive(self.root, [])

# #     def _dfs_recursive(self, node, values):
# #         if node:
# #             values.append(node.value)
# #             self._dfs_recursive(node.left, values)
# #             self._dfs_recursive(node.right, values)
# #         return values

# # # Example usage
# # tree = BinaryTree()
# # tree.insert("banana")
# # tree.insert("apple")
# # tree.insert("cherry")
# # tree.insert("date")

# # print("Inorder traversal:", tree.inorder_traversal())
# # print("BFS traversal:", tree.bfs())
# # print("DFS traversal:", tree.dfs())

# # print("Search for 'apple':", tree.search("apple"))
# # print("Search for 'kiwi':", tree.search("kiwi"))

# # tree.delete("banana")
# # print("BFS traversal after deleting 'banana':", tree.bfs())
# # print("DFS traversal after deleting 'banana':", tree.dfs())

# from collections import deque

# class Node:
#     def __init__(self, key, name):
#         self.key = key
#         self.name = name
#         self.left = None
#         self.right = None

# class BinaryTree:
#     def __init__(self):
#         self.root = None

#     def insert(self, key, name):
#         if not self.root:
#             self.root = Node(key, name)
#         else:
#             self._insert_recursive(self.root, key, name)

#     def _insert_recursive(self, node, key, name):
#         if key < node.key:
#             if node.left is None:
#                 node.left = Node(key, name)
#             else:
#                 self._insert_recursive(node.left, key, name)
#         else:
#             if node.right is None:
#                 node.right = Node(key, name)
#             else:
#                 self._insert_recursive(node.right, key, name)

#     def search(self, key):
#         return self._search_recursive(self.root, key)

#     def _search_recursive(self, node, key):
#         if node is None:
#             return None
#         if node.key == key:
#             return node.name
#         elif key < node.key:
#             return self._search_recursive(node.left, key)
#         else:
#             return self._search_recursive(node.right, key)

#     def delete(self, key):
#         self.root = self._delete_recursive(self.root, key)

#     def _delete_recursive(self, node, key):
#         if node is None:
#             return node

#         if key < node.key:
#             node.left = self._delete_recursive(node.left, key)
#         elif key > node.key:
#             node.right = self._delete_recursive(node.right, key)
#         else:
#             # Node with the key to be deleted found
#             if node.left is None:
#                 return node.right
#             elif node.right is None:
#                 return node.left

#             # Node with two children, get the inorder successor
#             min_larger_node = self._get_min_value_node(node.right)
#             node.key = min_larger_node.key
#             node.name = min_larger_node.name
#             node.right = self._delete_recursive(node.right, min_larger_node.key)

#         return node

#     def _get_min_value_node(self, node):
#         current = node
#         while current.left is not None:
#             current = current.left
#         return current

#     def inorder_traversal(self):
#         return self._inorder_recursive(self.root, [])

#     def _inorder_recursive(self, node, values):
#         if node:
#             self._inorder_recursive(node.left, values)
#             values.append((node.key, node.name))
#             self._inorder_recursive(node.right, values)
#         return values

#     def bfs(self):
#         if not self.root:
#             return []

#         result = []
#         queue = deque([self.root])

#         while queue:
#             node = queue.popleft()
#             result.append((node.key, node.name))
#             if node.left:
#                 queue.append(node.left)
#             if node.right:
#                 queue.append(node.right)

#         return result

#     def dfs(self):
#         return self._dfs_recursive(self.root, [])

#     def _dfs_recursive(self, node, values):
#         if node:
#             values.append((node.key, node.name))
#             self._dfs_recursive(node.left, values)
#             self._dfs_recursive(node.right, values)
#         return values

# # Example usage
# tree = BinaryTree()
# tree.insert(20, "Svay Rieng")
# tree.insert(2001, "Chantrea")
# tree.insert(2002, "Kampong Rou")
# tree.insert(2003, "Rumduol")
# tree.insert(2004, "Romeas Haek")
# tree.insert(200101, "Chantrae")
# tree.insert(200102, "Chres")
# tree.insert(200201, "Banteay Krang")
# tree.insert(200301, "Bos Mon")
# tree.insert(200401, "Ampil")
# tree.insert(200402, "Andoung Pou")

# # Traversals
# print("Inorder traversal:", tree.inorder_traversal())
# print("BFS traversal:", tree.bfs())
# print("DFS traversal:", tree.dfs())

# # Searching
# print("Search for '2001':", tree.search(2001))
# print("Search for '2010':", tree.search(2010))

# # Deleting a node
# tree.delete(2001)
# print("BFS traversal after deleting '2001':", tree.bfs())
# print("DFS traversal after deleting '2001':", tree.dfs())

from collections import deque

class Node:
    def __init__(self, key, name, is_district=False):
        self.key = key
        self.name = name
        self.is_district = is_district
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, key, name, is_district=False):
        if not self.root:
            self.root = Node(key, name, is_district)
        else:
            self._insert_recursive(self.root, key, name, is_district)

    def _insert_recursive(self, node, key, name, is_district):
        if key < node.key:
            if node.left is None:
                node.left = Node(key, name, is_district)
            else:
                self._insert_recursive(node.left, key, name, is_district)
        else:
            if node.right is None:
                node.right = Node(key, name, is_district)
            else:
                self._insert_recursive(node.right, key, name, is_district)

    def search(self, key):
        return self._search_recursive(self.root, key)

    def _search_recursive(self, node, key):
        if node is None:
            return None
        if node.key == key:
            return node.name
        elif key < node.key:
            return self._search_recursive(node.left, key)
        else:
            return self._search_recursive(node.right, key)

    def delete(self, key):
        self.root = self._delete_recursive(self.root, key)

    def _delete_recursive(self, node, key):
        if node is None:
            return node

        if key < node.key:
            node.left = self._delete_recursive(node.left, key)
        elif key > node.key:
            node.right = self._delete_recursive(node.right, key)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left

            min_larger_node = self._get_min_value_node(node.right)
            node.key = min_larger_node.key
            node.name = min_larger_node.name
            node.right = self._delete_recursive(node.right, min_larger_node.key)

        return node

    def _get_min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def inorder_traversal(self):
        return self._inorder_recursive(self.root, [])

    def _inorder_recursive(self, node, values):
        if node:
            self._inorder_recursive(node.left, values)
            values.append((node.key, node.name, node.is_district))
            self._inorder_recursive(node.right, values)
        return values

    def bfs(self):
        if not self.root:
            return []

        result = []
        queue = deque([self.root])

        while queue:
            node = queue.popleft()
            result.append((node.key, node.name, node.is_district))
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        return result

    def dfs(self):
        return self._dfs_recursive(self.root, [])

    def _dfs_recursive(self, node, values):
        if node:
            values.append((node.key, node.name, node.is_district))
            self._dfs_recursive(node.left, values)
            self._dfs_recursive(node.right, values)
        return values

    def print_tree(self):
        def print_recursive(node, indent=0):
            if node:
                print(' ' * indent + f"{node.key} {node.name}")
                if node.left:
                    print_recursive(node.left, indent + 4)
                if node.right:
                    print_recursive(node.right, indent + 4)

        print_recursive(self.root)

    def search_tree(self, key):
        result = self.search(key)
        if result:
            print(f"Found: {key} -> {result}")
        else:
            print(f"Key {key} not found.")

    def remove_node(self, key):
        self.delete(key)
        print(f"Removed node with key: {key}")


    def print_dfs(self):
        print("DFS Traversal:")
        for key, name, is_district in self.dfs():
            district_info = " (District)" if is_district else ""
            print(f"{key} {name}{district_info}")

    def print_bfs(self):
        print("BFS Traversal:")
        for key, name, is_district in self.bfs():
            district_info = " (District)" if is_district else ""
            print(f"{key} {name}{district_info}")

def print_district_tree(root):
    if not root:
        return
    
    def print_recursive(node, indent=0):
        if node:
            print(' ' * indent + f"{node.key} {node.name}")
            if node.is_district:
                print(f"{' ' * (indent + 2)}District:")
            if node.left:
                print_recursive(node.left, indent + 4)
            if node.right:
                print_recursive(node.right, indent + 4)

    print_recursive(root)

# Example usage
tree = BinaryTree()

# Insert districts and their locations
districts = {
    "Chantrea": [
        ("200103", "Chantrea"),
        ("200104", "Chres"),
        ("200105", "Me Sar Thngak"),
        ("200108", "Prey Kokir"),
        ("200109", "Samraong"),
        ("200110", "Tuol Sdei")
    ],
    "Kampong Rou": [
        ("200201", "Banteay Krang"),
        ("200202", "Nhor"),
        ("200203", "Khsaetr"),
        ("200204", "Preah Ponlea"),
        ("200205", "Prey Thum"),
        ("200206", "Reach Montir"),
        ("200207", "Samlei"),
        ("200208", "Samyaong"),
        ("200209", "Svay Ta Yean"),
        ("200211", "Thmei"),
        ("200212", "Tnaot")
    ],
    "Rumduol": [
        ("200301", "Bos Mon"),
        ("200302", "Thmea"),
        ("200303", "Kampong Chak"),
        ("200304", "Chrung Popel"),
        ("200305", "Kampong Ampil"),
        ("200306", "Meun Chey"),
        ("200307", "Pong Tuek"),
        ("200308", "Sangkae"),
        ("200309", "Svay Chek"),
        ("200310", "Thna Thnong")
    ],
    "Romeas Haek": [
        ("200401", "Ampil"),
        ("200402", "Andoung Pou"),
        ("200403", "Andoung Trabaek"),
        ("200404", "Angk Prasrae"),
        ("200405", "Chantrei"),
        ("200406", "Chrey Thum"),
        ("200407", "Doung"),
        ("200408", "Kampong Trach"),
        ("200409", "Kokir"),
        ("200410", "Krasang"),
        ("200411", "Mukh Da"),
        ("200412", "Mream"),
        ("200413", "Sambuor"),
        ("200414", "Sambatt Mean Chey"),
        ("200415", "Trapeang Sdau"),
        ("200416", "Tras")
    ],
    "Svay Chrum": [
        ("200501", "Angk Ta Sou"),
        ("200502", "Basak"),
        ("200503", "Chambak"),
        ("200504", "Kampong Chamlang"),
        ("200505", "Ta Suos"),
        ("200507", "Chheu Teal"),
        ("200508", "Doun Sa"),
        ("200509", "Kouk Pring"),
        ("200510", "Kraol Kou"),
        ("200511", "Kruos"),
        ("200512", "Pouthi Reach"),
        ("200513", "Svay Angk"),
        ("200514", "Svay Chrum"),
        ("200515", "Svay Thum"),
        ("200516", "Svay Yea"),
        ("200517", "Thlok")
    ],
    "Krong Svay Rieng": [
        ("200601", "Sangkat Svay Rieng"),
        ("200602", "Sangkat Prey Chhlak"),
        ("200603", "Sangkat Koy Trabaek"),
        ("200604", "Sangkat Pou Ta Hao"),
        ("200605", "Sangkat Chek"),
        ("200606", "Sangkat Svay Toea"),
        ("200607", "Sangkat Sangkhoar")
    ],
    "Svay Teab": [
        ("200702", "Kokir Saom"),
        ("200703", "Kandieng Reay"),
        ("200704", "Monourom"),
        ("200705", "Popeaet"),
        ("200706", "Prey Ta Ei"),
        ("200707", "Prasoutr"),
        ("200708", "Romeang Thkaol"),
        ("200709", "Sambuor"),
        ("200711", "Svay Rumpear")
    ],
    "Krong Bavet": [
        ("200801", "Sangkat Bati"),
        ("200802", "Sangkat Bavet"),
        ("200803", "Sangkat Chrak Mtes"),
        ("200804", "Sangkat Prasat"),
        ("200805", "Sangkat Prey Angkunh")
    ]
}

# Insert districts first
for district in districts:
    tree.insert(district[:3], district, is_district=True)


# Insert locations within each district
for district, locations in districts.items():
    for key, name in locations:
        tree.insert(key, name)

# Print the hierarchical tree
print("Tree structure:")
print_district_tree(tree.root)

# Search for a node
print("\nSearch for a node:")
tree.search_tree("200105")

# Remove a node
print("\nRemoving a node:")
tree.remove_node("200105")

# Print the tree after removal
print("\nTree structure after removal:")
print_district_tree(tree.root)

# Print DFS and BFS traversals
tree.print_dfs()
tree.print_bfs()
