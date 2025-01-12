print('Exercise 1 Part B')
# Exercise 1 Part B:
def adjecency_Martrix(V  , edges):
    matrix = [[0]*V for any1 in range(V)]
    for eachEdge in edges:
        v ,u = eachEdge
        matrix[u-1][v-1] = 1
        matrix[v-1][u-1] = 1
    return matrix
V = 5
edges = [(1,2),(2,5),(2,4),(2,3),(4,3),(5,4),(1,5)]
ValueMatrix = adjecency_Martrix(V,edges)
for row in ValueMatrix: 
    print(f'{row}')
print('Exercise 2 Part C:')
# Exercise 2
# Part C
def adjecency_Martrix(V  , edges):
    matrix = [[0]*V for any1 in range(V)]
    for eachEdge in edges:
        v ,u = eachEdge
        matrix[u][v] = 1
        matrix[v][u] = 1
    return matrix
V = 4
edges2 = [(0,2),(0,1),(0,3)]
ValueMatrix = adjecency_Martrix(V,edges2)
for row in ValueMatrix:
    print(f'{row}')
print('Exercise 3 part B:')
# Exercise 3 part B:
def adjecency_Martrix(V  , edges):
    matrix = [[None]*V for any1 in range(V)]
    for eachEdge in edges:
        v ,u = eachEdge
        matrix[v-1][u-1] = u
    return matrix
V = 4
edges2 = [(1,2),(1,3),(2,3),(3,4)]
ValueMatrix = adjecency_Martrix(V,edges2)
for column in range(len(ValueMatrix)):
    print(f'{column + 1} -> ' , end=' ')
    for row in range(len(ValueMatrix)):
        if (ValueMatrix[column][row] != None):
            print(f' {ValueMatrix[column][row]}' , end=' ')
    print('\n')
print('=======================')

def adjecency_Martrix(V  , edges):
    matrix = [[None]*V for any1 in range(V)]
    for eachEdge in edges:
        v ,u = eachEdge
        matrix[u-1][v-1] = v
        matrix[v-1][u-1] = u
    return matrix
V = 4
edges2 = [(1,2),(1,3),(2,3),(3,4)]
ValueMatrix = adjecency_Martrix(V,edges2)
for column in range(len(ValueMatrix)):
    print(f'{column + 1} -> ' , end=' ')
    for row in range(len(ValueMatrix)):
        if (ValueMatrix[column][row] != None):
            print(f'{ValueMatrix[column][row]}' , end=' ')
    print('\n')

print('Exercise 4 Part C:')

def adjecency_Martrix(V  , edges):
    matrix = [[None]*V for any1 in range(V)]
    for eachEdge in edges:
        v ,u = eachEdge
        matrix[u][v] = v
        matrix[v][u] = u
    return matrix
V = 5
edges2 = [(0,1),(0,3),(0,2),(1,3),(1,4),(4,3),(3,2)]
ValueMatrix = adjecency_Martrix(V,edges2)
for column in range(len(ValueMatrix)):
    print(f'{column} -> ' , end=' ')
    for row in range(len(ValueMatrix)):
        if (ValueMatrix[column][row] != None):
            print(f'{ValueMatrix[column][row]}' , end=' ')
    print('\n')

