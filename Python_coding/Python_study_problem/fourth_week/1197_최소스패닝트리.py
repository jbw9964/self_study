
# 궁금한게 있는데, 이 문제를 Prim's algorithm 으로 제출해봄. 그런데 메모리 초과됨.
# 그럼 Prim's algorithm 은 도대체 어디에 적합한 거지?

import sys
input = sys.stdin.readline

def find_parent(Parent : list, V : int) : 
    if Parent[V] != V : 
        Parent[V] = find_parent(Parent, Parent[V])
    return Parent[V]

def union(Parent : list, V1 : int, V2 : int) : 
    
    P1 = find_parent(Parent, V1)
    P2 = find_parent(Parent, V2)

    if P1 < P2 : 
        Parent[V2] = P1
    else : 
        Parent[V1] = P2


N, M = map(int, input().split())

Parent = [i for i in range(N + 1)]

E_list = []
for i in range(M) : 
    E_list.append(list(map(int, input().split())))

E_list = sorted(E_list, key=lambda x : x[2])
print(E_list)

sum = 0
for V1, V2, weight in  E_list : 
    
    P1 = find_parent(Parent, V1)
    P2 = find_parent(Parent, V2)

    if P1 != P2 : 
        union(Parent, V1, V2)
        sum += weight

print(sum)


