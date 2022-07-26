
def Visit(Comp_list, Edge_list, Vertex_index) -> None : 

    Comp_list[Vertex_index] += 1

    for i in range(1, len(Comp_list)) : 

        if Edge_list[Vertex_index][i] and not Comp_list[i] : Visit(Comp_list, Edge_list, i)

import sys

input = sys.stdin.readline

Comp_num = int(input())
Edge_num = int(input())

Edge_list = [[False for i in range(Comp_num)] for i in range(Comp_num)]
for i in range(Edge_num) : 
    Vertex_1, Vertex_2 = map(int, input().split())
    Edge_list[Vertex_1 - 1][Vertex_2 - 1] = True
    Edge_list[Vertex_2 - 1][Vertex_1 - 1] = True

#==== input ====#

Comp_list = [0 for i in range(Comp_num)]           # White : 0, Gray : 1, Balck : 2

Visit(Comp_list, Edge_list, 0)

count = -1
for Current in Comp_list : 
    if Current : count += 1

print(count)