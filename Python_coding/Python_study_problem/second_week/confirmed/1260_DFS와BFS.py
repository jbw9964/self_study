

def Bread_first_search(Vertex_num, Adjacent_table, start_vertex) -> list: 

    Result_list = []
    Visit_table = [0 for i in range(Vertex_num)]

    Queue_list = []
    Queue_list.append(start_vertex)

    while len(Queue_list) : 

        Current_visit = Queue_list.pop()

        if Visit_table[Current_visit] : continue
        Visit_table[Current_visit] += 1
        Result_list.append(Current_visit)

        for i in range(Vertex_num) : 
            if Adjacent_table[Current_visit][i] and not Visit_table[i] : 
                Queue_list.insert(0, i)

    return Result_list

def Depth_visit(Visit_table, Adjacent_table, Result_list, visit_vertex) : 

    Visit_table[visit_vertex] += 1

    for i in range(len(Visit_table)) : 

        if Adjacent_table[visit_vertex][i] and not Visit_table[i] : 
            Result_list.append(i)
            Depth_visit(Visit_table, Adjacent_table, Result_list, i)

def Depth_first_search(Vertex_num, Adjacent_table, start_vertex) -> list : 

    Result_list = []
    Visit_table = [0 for i in range(Vertex_num)]

    Result_list.append(start_vertex)
    Depth_visit(Visit_table, Adjacent_table, Result_list, start_vertex)

    return Result_list

# ======================================================================== #

import sys

input = sys.stdin.readline

Vertex_num, Edge_num, First_visit = map(int, input().split())
First_visit -= 1

Adjacent_table = [[False for i in range(Vertex_num)] for i in range(Vertex_num)]

for i in range(Edge_num) : 
    temp_1, temp_2 = map(int, input().split())
    Adjacent_table[temp_1 - 1][temp_2 - 1] = True
    Adjacent_table[temp_2 - 1][temp_1 - 1] = True

Depth_result = Depth_first_search(Vertex_num, Adjacent_table, First_visit)
Bread_result = Bread_first_search(Vertex_num, Adjacent_table, First_visit)

for temp in Depth_result : 
    print(temp + 1, end=' ')
print()
for temp in Bread_result : 
    print(temp + 1, end=' ')
print()


# temp_list = [1, 2, 3, 4]

# temp_list.insert(0, 0)
# print(temp_list)
