# digits = [ '1111110',    # 0
#      '0110000',  # 1
#      '1101101',  # 2
#      '1111001',  # 3
#      '0110011',  # 4
#      '1011011',  # 5
#      '1011111',  # 6
#      '1110000',  # 7
#      '1111111',  # 8
#      '1111011',  # 9
#      ]


# def print_number(num):
#   global digits
#   digs = str(num)
#   lines = [ '' for lin in range(5) ]
#   for d in digs:
#     segs = [ [' ',' ',' '] for lin in range(5) ]
#     ptrn = digits[ord(d) - ord('0')]
#     if ptrn[0] == '1':
#       segs[0][0] = segs[0][1] = segs[0][2] = '#'
#     if ptrn[1] == '1':
#       segs[0][2] = segs[1][2] = segs[2][2] = '#'
#     if ptrn[2] == '1':
#       segs[2][2] = segs[3][2] = segs[4][2] = '#'
#     if ptrn[3] == '1':
#       segs[4][0] = segs[4][1] = segs[4][2] = '#'
#     if ptrn[4] == '1':
#       segs[2][0] = segs[3][0] = segs[4][0] = '#'
#     if ptrn[5] == '1':
#       segs[0][0] = segs[1][0] = segs[2][0] = '#'
#     if ptrn[6] == '1':
#       segs[2][0] = segs[2][1] = segs[2][2] = '#'
#     for lin in range(5):
#       lines[lin] += ''.join(segs[lin]) + '\t '
#   for lin in lines:
#     print(lin)


# print_number(int(input("Enter the number you wish to display: ")))
# def dijkstra(graph, start):
#     # Initialize distances with infinity and set the start vertex distance to 0
#     distances = {vertex: float('inf') for vertex in graph}
#     distances[start] = 0
#     print(distances)
#     # Set of unvisited vertices
#     unvisited_vertices = set(graph.keys())

#     while unvisited_vertices:
#         # Select the vertex with the smallest distance
#         current_vertex = min(unvisited_vertices, key=lambda vertex: distances[vertex])
#         unvisited_vertices.remove(current_vertex)

#         # Update the distances to neighboring vertices
#         for neighbor, weight in graph[current_vertex].items():
#             new_distance = distances[current_vertex] + weight
#             if new_distance < distances[neighbor]:
#                 distances[neighbor] = new_distance

#     return distances

# # Example usage
# if __name__ == "__main__":
#     # Define a sample graph
#     graph = {
#         'A': {'B': 1, 'C': 4},
#         'B': {'A': 1, 'C': 2, 'D': 5},
#         'C': {'A': 4, 'B': 2, 'D': 1},
#         'D': {'B': 5, 'C': 1}
#     }

#     start_vertex = 'A'
#     shortest_paths = dijkstra(graph, start_vertex)

#     print("Shortest paths from vertex", start_vertex)
#     for vertex, distance in shortest_paths.items():
#         print(f"Distance to {vertex}: {distance}")

def dijkstra(graph, start):
    # Initialize distances to all vertices as infinity
    distances = {}
    for vertex in graph:
        distances[vertex] = float('inf')
        # print(distances[vertex])
    distances[start] = 0  # Distance to the start vertex is 0

    # Set of unvisited vertices
    unvisited = list(graph.keys())
    # print(unvisited)

    while unvisited:
        # Find the vertex with the smallest distance
        min_vertex = None
        for vertex in unvisited:
            if min_vertex is None or distances[vertex] < distances[min_vertex]:
                min_vertex = vertex
        
        if distances[min_vertex] == float('inf'):
            # All remaining vertices are inaccessible from start
            break
        
        # Update distances to the neighbors of the current vertex
        for neighbor, weight in graph[min_vertex].items():
            distance = distances[min_vertex] + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance

        # Mark the vertex as visited by removing it from the unvisited set
        unvisited.remove(min_vertex)

    return distances

# Example usage
if __name__ == "__main__":
    # Define a sample graph
    graph = {
        'A': {'B': 1, 'C': 4},
        'B': {'A': 1, 'C': 2, 'D': 5},
        'C': {'A': 4, 'B': 2, 'D': 1},
        'D': {'B': 5, 'C': 1}
    }

    start_vertex = 'A'
    shortest_paths = dijkstra(graph, start_vertex)

    print("Shortest paths from vertex", start_vertex)
    for vertex, distance in shortest_paths.items():
        print(f"Distance to {vertex}: {distance}")