from collections import defaultdict
# function for adding edge to graph
graph = defaultdict(list)
def addEdge(graph,u,v):
    graph[u].append(v)
def generate_edge(graph):
    edges = [] 
    # for each node in graph
    for node in graph: 
        # for each neighbour node of a single node
        for neighour in graph[node]:
            # if edge exists then append
            edges.append((node,neighour))
    return edges

# addEdge(graph,0,1)
# addEdge(graph,1,2)
# addEdge(graph,2,1)
# addEdge(graph,2,0)
# addEdge(graph,3,1)

# Exercise 1 : a.
# addEdge(graph,0,1)
# addEdge(graph,0,3)
# addEdge(graph,0,2)
# addEdge(graph,1,3)
# addEdge(graph,1,4)
# addEdge(graph,2,3)
# addEdge(graph,3,4)

# Exercise 2 : a.
# addEdge(graph,1,2)
# addEdge(graph,1,3)
# addEdge(graph,2,4)
# addEdge(graph,2,5)
# addEdge(graph,3,6)
# addEdge(graph,4,7)
# addEdge(graph,5,7)
# addEdge(graph,6,5)
# addEdge(graph,6,7)

# Exercise 3 : a.
# addEdge(graph,0,1)
# addEdge(graph,1,2)
# addEdge(graph,2,1)
# addEdge(graph,2,3)
# addEdge(graph,2,5)
# addEdge(graph,3,6)
# addEdge(graph,3,4)
# addEdge(graph,4,6)
# addEdge(graph,5,7)
# addEdge(graph,6,3)

# Exercise 4: a
addEdge(graph,'A','B')
addEdge(graph,'B','D')
addEdge(graph,'B','D')
addEdge(graph,'D','A')
addEdge(graph,'B','C')
addEdge(graph,'C','E')
addEdge(graph,'E','D')
print(generate_edge(graph))