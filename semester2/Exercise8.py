from collections import deque
import heapq

# Exercise 1
def bfs(graph, start):
    visited = set()
    queue = deque([start])
    while queue:
        vertex = queue.popleft()
        if vertex not in visited:
            print(vertex, end=' ')
            visited.add(vertex)
            queue.extend(neighbor for neighbor in graph[vertex] if neighbor not in visited)


def dfs_stack(graph, start):
    visited = set()
    stack = [start]
    
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            print(vertex, end=' ')
            visited.add(vertex)
            stack.extend(neighbor for neighbor in graph[vertex] if neighbor not in visited)

# Example usage
graph = {
    0: [1, 2, 3],
    1: [0],
    2: [0, 3, 4],
    3: [0, 2],
    4: [2]
}
# Example usage
print('Breadth-First-Searching (BFS)')
bfs(graph, 0)  # Output: 0 1 2 3 4
print(f'\nDepth-First-Search (DFS)')
dfs_stack(graph, 0)  # Output: 0 3 2 4 1
print('\n')

# Exercise 2

# iPair ==> Integer Pair
iPair = tuple

# This class represents a directed graph using
# adjacency list representation
class Graph:
    def __init__(self, V: int): # Constructor
        self.V = V
        self.adj = [[] for _ in range(V)]

    def addEdge(self, u: int, v: int, w: int):
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))

    # Prints shortest paths from src to all other vertices
    def shortestPath(self, src: int):
        # Create a priority queue to store vertices that
        # are being preprocessed
        pq = []
        heapq.heappush(pq, (0, src))

        # Create a vector for distances and initialize all
        # distances as infinite (INF)
        dist = [float('inf')] * self.V
        dist[src] = 0

        while pq:
            # The first vertex in pair is the minimum distance
            # vertex, extract it from priority queue.
            # vertex label is stored in second of pair
            d, u = heapq.heappop(pq)

            # 'i' is used to get all adjacent vertices of a
            # vertex
            for v, weight in self.adj[u]:
                # If there is shorted path to v through u.
                if dist[v] > dist[u] + weight:
                    # Updating distance of v
                    dist[v] = dist[u] + weight
                    heapq.heappush(pq, (dist[v], v))

        # Print shortest distances stored in dist[]
        for i in range(self.V):
            print(f"{i} \t\t {dist[i]}")

# Driver's code
if __name__ == "__main__":
    # create the graph given in above figure
    V = 7
    g = Graph(V)

    # making above shown graph
    g.addEdge(0, 1,2)
    g.addEdge(0 ,2 , 6)
    g.addEdge(1,3,5)
    g.addEdge(2,3,8)
    g.addEdge(3,5,15)
    g.addEdge(3,4,10)
    g.addEdge(5,4,6)
    g.addEdge(5,6,6)
    g.addEdge(4,6,2)
    g.shortestPath(0)





class Graph:
    def __init__(self):
        self.graph = {}

    def addEdge(self, u, v, weight):
        # Ensure both nodes are in the graph
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []

        # Add edge from u to v with given weight
        self.graph[u].append((v, weight))
        
        # If the graph is undirected, also add the edge from v to u
        # self.graph[v].append((u, weight))

    def dijkstra(self, start):
        distances = {node: float('inf') for node in self.graph}
        distances[start] = 0
        priority_queue = [(0, start)]

        while priority_queue:
            current_distance, current_node = heapq.heappop(priority_queue)

            if current_distance > distances[current_node]:
                continue

            for neighbor, weight in self.graph[current_node]:
                distance = current_distance + weight

                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(priority_queue, (distance, neighbor))

        return distances

# Example usage
g = Graph()
g.addEdge('A', 'B', 2)
g.addEdge('A', 'C', 4)
g.addEdge('B', 'C', 1)
g.addEdge('B', 'D', 7)
g.addEdge('C', 'D', 3)

# Run Dijkstra's algorithm from start node 'A'
start_node = 'A'
distances = g.dijkstra(start_node)

# Print the shortest distances from the start node
print("Shortest distances from node", start_node)
for node, distance in distances.items():
    print(f"Distance to {node}: {distance}")
