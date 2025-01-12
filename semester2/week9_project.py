
import heapq

# Define the graph with distances
graph = {
    'Phnom Penh': {'Siem Reap': 314, 'Battambang': 291, 'Sihanoukville': 230, 'Kampot': 150, 'Kampong Cham': 124,
                   'Kampong Chhnang': 91, 'Kampong Speu': 48, 'Kampong Thom': 168, 'Kandal': 37, 'Kep': 164,
                   'Kratie': 250, 'Mondulkiri': 382, 'Oddar Meanchey': 362, 'Pailin': 342, 'Preah Vihear': 325,
                   'Prey Veng': 94, 'Pursat': 186, 'Ratanakiri': 588, 'Stung Treng': 481, 'Svay Rieng': 122,
                   'Takeo': 78, 'Tboung Khmum': 203, 'Pursat City': 220},  # Added Pursat City
    'Siem Reap': {'Phnom Penh': 314, 'Battambang': 174, 'Oddar Meanchey': 133, 'Preah Vihear': 209, 'Pursat City': 300},
    'Battambang': {'Phnom Penh': 291, 'Siem Reap': 174, 'Pailin': 86, 'Pursat': 106, 'Pursat City': 130},
    'Sihanoukville': {'Phnom Penh': 230, 'Kampot': 105},
    'Kampot': {'Phnom Penh': 150, 'Sihanoukville': 105, 'Kep': 25, 'Takeo': 92},
    'Kampong Cham': {'Phnom Penh': 124, 'Tboung Khmum': 45, 'Kratie': 165, 'Prey Veng': 85, 'Pursat City': 110},
    'Kampong Chhnang': {'Phnom Penh': 91, 'Pursat': 95},
    'Kampong Speu': {'Phnom Penh': 48, 'Takeo': 96},
    'Kampong Thom': {'Phnom Penh': 168, 'Siem Reap': 147, 'Preah Vihear': 144},
    'Kandal': {'Phnom Penh': 37},
    'Kep': {'Phnom Penh': 164, 'Kampot': 25},
    'Kratie': {'Phnom Penh': 250, 'Kampong Cham': 165, 'Stung Treng': 141, 'Mondulkiri': 220},
    'Mondulkiri': {'Phnom Penh': 382, 'Kratie': 220, 'Ratanakiri': 185},
    'Oddar Meanchey': {'Phnom Penh': 362, 'Siem Reap': 133, 'Preah Vihear': 203},
    'Pailin': {'Phnom Penh': 342, 'Battambang': 86},
    'Preah Vihear': {'Phnom Penh': 325, 'Siem Reap': 209, 'Oddar Meanchey': 203, 'Kampong Thom': 144, 'Stung Treng': 191},
    'Prey Veng': {'Phnom Penh': 94, 'Kampong Cham': 85, 'Svay Rieng': 55},
    'Pursat': {'Phnom Penh': 186, 'Battambang': 106, 'Kampong Chhnang': 95, 'Pursat City': 130},
    'Ratanakiri': {'Phnom Penh': 588, 'Mondulkiri': 185, 'Stung Treng': 140},
    'Stung Treng': {'Phnom Penh': 481, 'Kratie': 141, 'Preah Vihear': 191, 'Ratanakiri': 140},
    'Svay Rieng': {'Phnom Penh': 122, 'Prey Veng': 55},
    'Takeo': {'Phnom Penh': 78, 'Kampot': 92, 'Kampong Speu': 96},
    'Tboung Khmum': {'Phnom Penh': 203, 'Kampong Cham': 45},
    'Pursat City': {'Phnom Penh': 220, 'Battambang': 130, 'Kampong Cham': 110}  # New province distances
}

def prim_mst(graph, start):
    min_heap = [(0, start)]
    visited = set()
    total_cost = 0
    mst_edges = []

    while min_heap:
        cost, u = heapq.heappop(min_heap)
        if u in visited:
            continue
        visited.add(u)
        total_cost += cost
        for v, weight in graph[u].items():
            if v not in visited:
                heapq.heappush(min_heap, (weight, v))
                mst_edges.append((u, v, weight))

    return total_cost, mst_edges

def dijkstra(graph, start, end):
    min_heap = [(0, start)]
    distances = {vertex: float('inf') for vertex in graph}
    distances[start] = 0
    previous_nodes = {vertex: None for vertex in graph}
    
    while min_heap:
        current_distance, u = heapq.heappop(min_heap)
        
        if current_distance > distances[u]:
            continue
        
        for v, weight in graph[u].items():
            distance = current_distance + weight
            if distance < distances[v]:
                distances[v] = distance
                previous_nodes[v] = u
                heapq.heappush(min_heap, (distance, v))
    
    # Reconstruct path
    path = []
    while end is not None:
        path.append(end)
        end = previous_nodes[end]
    path.reverse()
    
    return distances[path[-1]], path

# Example usage
start_province = 'Phnom Penh'
total_cost, mst_edges = prim_mst(graph, start_province)


print(f"Total cost to connect all provinces starting from {start_province}: {total_cost}")
print("Edges in the Minimum Spanning Tree:")
for u, v, weight in mst_edges:
    print(f"{u} - {v}: {weight}")
    
print("==========> Choice province <==========\n")
# User input for shortest path
start_location = input("Enter the start province: ")
end_location = input("Enter the end province: ")

print("=======================================\n")
if start_location in graph and end_location in graph:
    distance, path = dijkstra(graph, start_location, end_location)
    print(f"Shortest path from {start_location} to {end_location} is {distance} km:")
    print(" -> ".join(path))
else:
    print("Invalid province names.")
print("=======================================\n")
