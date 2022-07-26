

# 깊이 우선 탐색으로 만드니까 Recursion Error 뜸. 아예 다른 방식으로 생각해야되는 듯
# 그래서 BFS 로 만듬. 뭔가 갯수 세는거니까 어려울 것 같았는데 그냥 세기만 하면 되서 그냥 그럼


# def DFS_visit(Table, Visit_table, Row_index, Column_index) -> int : 

#     if Visit_table[Row_index][Column_index] == 1 : return 0

#     global Row, Column
#     Visit_table[Row_index][Column_index] = 1

#     temp_list = [0]

#     for Check_pos in ([Row_index + 1, Column_index], [Row_index - 1, Column_index], [Row_index, Column_index + 1], [Row_index, Column_index - 1]) : 
#         # 아래, 위, 오른쪽, 왼쪽
#         pos_row = Check_pos[0]
#         pos_column = Check_pos[1]

#         if 0 <= pos_row <= Row - 1 and 0 <= pos_column <= Column - 1 : 
            
#             if Table[pos_row][pos_column] and Visit_table[pos_row][pos_column] == 0 : 
#                 temp_list.append(DFS_visit(Table, Visit_table, pos_row, pos_column))
                

#     sum = 1
#     for temp in temp_list : 
#         sum += temp

#     return sum

from collections import deque
import sys
input = sys.stdin.readline

Row, Column, Trash_num = map(int, input().split())

Table = [[False for i in range(Column)] for i in range(Row)]
Visit_table = [[0 for i in range(Column)] for i in range(Row)]

for i in range(Trash_num) : 
    row, column = map(int, input().split())
    Table[row - 1][column - 1] = True

# Max = 0
# for i in range(Row) : 
#     for j in range(Column) : 
#         if Table[i][j] and Visit_table[i][j] == 0 : 
#             # temp = DFS_visit(Table, Visit_table, i, j)
#             # Max = max(temp, Max)
#             pass

# # print(Max)

#===== input 받음 ====#

temp_max = 0
for row_index in range(Row) : 
    for column_index in range(Column) : 
        
        if Table[row_index][column_index] and Visit_table[row_index][column_index] == 0 : 

            Visit_table[row_index][column_index] = 1

            Queue = deque()
            Queue.append([row_index, column_index])
            
            count = 1
            while Queue : 
                Deque_row, Deque_column = Queue.popleft()

                for Check_pos in ([Deque_row, Deque_column + 1], [Deque_row + 1, Deque_column], [Deque_row, Deque_column - 1], [Deque_row - 1, Deque_column]) : 
                    # 오른, 아래, 왼, 위
                    pos_row = Check_pos[0]
                    pos_column = Check_pos[1]

                    if 0 <= pos_row <= Row - 1 and 0 <= pos_column <= Column - 1 : 

                        if Table[pos_row][pos_column] and Visit_table[pos_row][pos_column] == 0 : 
                            Visit_table[pos_row][pos_column] = 1
                            Queue.append([pos_row, pos_column])
                            count += 1

            temp_max = max(count, temp_max)
            
print(temp_max)

