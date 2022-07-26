
# kurskal's algorithm 을 구현하는데 생각보다 별게 필요하지 않았음.
# 그나마 union - find 방식을 구현해야 되는데, 처음에 이를 class 로 구현해야 된다 생각했었음.
# 그런더 생각해보면 '그 노드의 부모가 뭔지 저장만 해두면 되니까' 굳이 class 로 구현하지 않고
# dynamic 하게 저장해두기만 하면 됨.

import sys
input = sys.stdin.readline

def find_parent(V : int, Parent_list : list) : 
    if Parent_list[V] != V : 
        Parent_list[V] = find_parent(Parent_list[V], Parent_list)   # return find_parent(Parent_list[V], Parent_list)
    return Parent_list[V]                                           # 이러니까 recursion error 뜸. 재귀 호출되는 횟수는 똑같지 않나??

def union(V1 : int, V2 : int, Parent_list : list) : 
    
    P1 = find_parent(V1, Parent_list)
    P2 = find_parent(V2, Parent_list)

    if P1 < P2 :                            # if P1 != P2 : Parent_list[P2] = P1                        
        Parent_list[P2] = P1                # 이러면 recursion error 가 뜰 확률이 있음.
    else :                                  # 더 돌고 돌아 parent 로 갈 수 있기 때문
        Parent_list[P1] = P2

N, M = map(int, input().split())

E = []
for i in range(M) : 
    start, end, weight = map(int, input().split())
    E.append([weight, start - 1, end - 1])

# E : [무게, 간선을 잇는 두 정점]

E = sorted(E, key=lambda x : x[0])

Parent_list = [i for i in range(N)]

temp_max = 0
sum = 0
for Weight, V1, V2 in E : 

    if find_parent(V1, Parent_list) != find_parent(V2, Parent_list) : 
        union(V1, V2, Parent_list)
        sum += Weight
        temp_max = Weight

print(sum - temp_max)


'''
class 이용 풀이
'''
# class Union_find() : 
#     Parent_list = []

#     def __init__(self, N) -> None:
#         self.Parent_list = [i for i in range(N)]
        

#     def union(self, V1 : int, V2 : int) : 
#         self.Parent_list[V2] = V1

#     def find(self, V) -> bool : 
#         pass

#     def check_cycle(self, V1, V2) -> bool : 
#         if V1 == V2 : return True
#         elif self.Parent_list[V1] == V1 and self.Parent_list[V2] == V2 : return False

#         return self.check_cycle(self.Parent_list[V1], self.Parent_list[V2])

# def MST_kruskal(N : int, E : list) -> int : 
    
#     sum = 0
#     temp_max = 0
    
#     Check = Union_find(N)

#     for Current_edge in E : 
        
#         weight = Current_edge[0]
#         V1 = Current_edge[1]
#         V2 = Current_edge[2]

#         if Check.check_cycle(V1, V2) : continue
        
#         Check.union(V1, V2)
#         sum += weight
#         if temp_max < weight : temp_max = weight
        
#     return sum, temp_max
