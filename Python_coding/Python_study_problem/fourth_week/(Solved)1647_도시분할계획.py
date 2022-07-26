

# 지금까지 계속 Prim's algorithm 해결할려 했고, 파이썬의 Priorityqueue 를 import 해서 메모리 초과가 났다고 생각했음.
# 계속 바꾸고 heapq 를 이용해서도 해봤는데 메모리 초과가 나는 걸로 봐서, Prim's algorithm 이 적합하지 않은 것 같음
# 그런데 어느 부분에서 그렇게 메모리를 잡아먹는 건지 잘 모르겠음. Adjacent list 방식으로도 해봤는데 그 때는 시간초과가 났음.

'''
heapq 사용 방식
'''
from cmath import inf
import sys
input = sys.stdin.readline

import heapq

def MST_prim(N : int, E : list) -> list: 
    D = [+inf for i in range(N)]
    D[0] = 0

    Heap = []
    for i in range(1, N) : 
        if E[0][i] != +inf : 
            D[i] = E[0][i]
            heapq.heappush(Heap, [D[i], i])
        else : heapq.heappush(Heap, [+inf, i])

    Visit_table = [False for i in range(N)]
    Visit_table[0] = True
    while Heap : 
        Weight, index = heapq.heappop(Heap)

        for adjacent in range(N) : 
            if adjacent == index : continue
            if E[index][adjacent] == +inf : continue
            if Visit_table[adjacent] : continue

            if E[index][adjacent] < D[adjacent] : 
                D[adjacent] = E[index][adjacent]

                for i in range(len(Heap)) : 
                    if Heap[i][1] == adjacent : 
                        Heap[i] = [D[adjacent], i]
                        break
        
        heapq.heapify(Heap)
        Visit_table[index] = True

    return D


N, M = map(int, input().split())

E = [[+inf for i in range(N)] for i in range(N)]
for i in range(M) : 
    temp_1, temp_2, weight = map(int, input().split())
    E[temp_1 - 1][temp_2 - 1] = weight
    E[temp_2 - 1][temp_1 - 1] = weight

Table = MST_prim(N, E)

sum = 0
temp_max = 0
for value in Table : 
    sum += value
    if temp_max < value : temp_max = value

print(sum - temp_max)


# temp = []
# heapq.heappush(temp, [10, '10'])
# heapq.heappush(temp, [1, '1'])
# heapq.heappush(temp, [5, '5'])
# heapq.heappush(temp, [2, '2'])
# heapq.heappush(temp, [8, '8'])

# result = temp.index([ 2, '2'])
# print(result)

# print(temp)



'''
PriorityQueue 사용 방식
'''
# from cmath import inf
# from queue import PriorityQueue
# import sys
# input = sys.stdin.readline

# def MST_Prim(N : int, E : list) -> list : 

#     D = [+inf for i in range(N)]
#     D[0] = 0

#     Heap = PriorityQueue(100005)
#     for i in range(1, N) : 
#         if E[0][i] != +inf : 
#             D[i] = E[0][i]
#             Heap.put([D[i], i])

#     while not Heap.empty() : 
#         Weight, index = Heap.get()
        
#         for adjacent in range(N) : 
#             if E[index][adjacent] == +inf : continue
            
#             if E[index][adjacent] < D[adjacent] : 
#                 D[adjacent] = E[index][adjacent]
#                 Heap.put([D[adjacent], adjacent])
    
#     return D

# N, M = map(int, input().split())

# E = [[+inf for i in range(N)] for i in range(N)]
# for i in range(M) : 
#     temp_1, temp_2, value = map(int, input().split())
#     E[temp_1 - 1][temp_2 - 2] = value
#     E[temp_2 - 1][temp_1 - 1] = value


# Table = MST_Prim(N, E)

# sum = 0
# temp_max = 0
# for value in Table : 
#     sum += value
#     if temp_max < value : temp_max = value

# print(sum - temp_max)

# # temp = PriorityQueue(+inf)
# # temp.put([0, 'hi'])
# # temp.put([5, '5'])
# # temp.put([1, 'hello'])

# # a, b = temp.get()
# # print(temp, a, b)


'''
Adjacent list 방식
'''
# from cmath import inf
# import heapq
# import sys
# input = sys.stdin.readline

# N, M = map(int, input().split())

# E_list = [[0] for i in range(N + 1)]

# # E_list : [ [ [2, 1], [3, 2], [4, 5] ], ... ] --> 1번 vertex 의 이웃과 그 무게 : 2(1), 3(2), 4(5)

# for i in range(M) : 
#     start, end, weight = map(int, input().split())

#     E_list[start].append([end, weight])
#     E_list[end].append([start, weight])



# def MST_prim(N : int, E_list : list) -> list : 
    
#     D = [+inf for i in range(N + 1)]
#     D[0] = 0
#     D[1] = 0

#     Heap = [[+inf, i] for i in range(N + 1)]
        
#     for value in E_list[1] : 
#         if value == 0 : continue
#         Heap[value[0]] = [value[1], value[0]]
#         D[value[0]] = value[1]

#     Heap.pop(0)
#     Heap.pop(0)
#     heapq.heapify(Heap)
    
#     Visit_table = [False for i in range(N + 1)]
#     Visit_table[0] = True
#     Visit_table[1] = True

#     while Heap : 
#         weight, Current_index = heapq.heappop(Heap)

#         for neighbor in E_list[Current_index] : 
#             if neighbor == 0 : continue
#             if neighbor[0] == Current_index : continue
#             if Visit_table[neighbor[0]] : continue
            
#             if weight < D[neighbor[0]] : 
#                 D[neighbor[0]] = neighbor[1]
            
#                 for i in range(len(Heap)) : 
#                     if Heap[i][1] == neighbor[0] : 
#                         Heap[i] = [D[neighbor[0]], neighbor[0]]
#                         break
            
#         Visit_table[Current_index] = True
#         heapq.heapify(Heap)

#     return D

# # temp = [[0, i] for i in range(10)]
# # temp.pop(0)
# # print(temp)

# Table = MST_prim(N, E_list)

# sum = 0
# temp_max = 0
# for value in Table : 
#     sum += value
#     if temp_max < value : temp_max = value

# print(sum - temp_max)

