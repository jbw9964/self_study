
# DFS / BFS 문제여서 생각하기 싫어서 그냥 DFS 로 먼저 풀었었음.
# 그런데 재귀형식으로 DFS 만드니 RecursionError 나서 BFS 로 풀어야 되는건가 싶었는데, Stack 구조를 이용해 DFS 를 구현할 수 있다 함.
# 그래서 이번에 Stack 으로 해서 만들어 봄. 만들고 나니까 형식이 그냥 BFS 랑 똑같았음. 그냥 Stack 을 이용했을 뿐 다른점은 없었음.

import sys
input = sys.stdin.readline

def DFS_stack(R_index : int, C_index : int, Visit_table : list, D : list) : 

    Visit_table[R_index][C_index] = True

    Stack_list = [[R_index, C_index]]
    global Column, Row

    while Stack_list : 
        Current_node = Stack_list.pop()
        R, C = Current_node

        for r, c in ([R+1,C],[R+1,C+1],[R,C+1],[R-1,C+1],[R-1,C],[R-1,C-1],[R,C-1],[R+1,C-1]) : 
            if not (0<=r<Row and 0<=c<Column) : continue
            if D[r][c] != 1 or Visit_table[r][c] : continue

            Visit_table[r][c] = True
            Stack_list.append([r, c])
    

def solution(Column : int, Row : int) : 
    
    D = []
    for i in range(Row) : 
        D.append(list(map(int, input().split())))
    
    Visit_table = [[False for _ in range(Column)] for _ in range(Row)]

    count = 0
    for i in range(Row) : 
        for j in range(Column) : 
            
            if not Visit_table[i][j] and D[i][j] == 1: 
                DFS_stack(i, j, Visit_table, D)
                count += 1
            
    del Visit_table
    del D
    return count

if __name__ == '__main__' : 
    
    Result_list = []
    while True : 
        Column, Row = map(int, input().split())

        if Column == 0 and Row == 0 : break

        Result_list.append(solution(Column, Row))

    for value in Result_list : 
        print(value)


# def Visit(R_index, C_index, Visit_table, D) : 
    
#     Visit_table[R_index][C_index] = True
#     global Column, Row

#     for r, c in ([R_index-1,C_index],[R_index+1,C_index],[R_index,C_index-1],[R_index,C_index+1],[R_index-1,C_index-1],[R_index+1,C_index+1],[R_index-1,C_index+1],[R_index+1,C_index-1]) : 
#         # 아래, 위, 왼, 오른, 위왼, 아래오른, 위오른, 아래왼

#         if not (0<=r<Row and 0<=c<Column) : continue

#         if Visit_table[r][c] or D[r][c] != 1 : continue
#         Visit(r, c, Visit_table, D)

