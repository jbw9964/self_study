
def Valid_direction(h, r, c) -> list: 
    global Height, Row, Column
    global Tomato_table, Visit_table

    temp_list = []
    for H, R, C in  ([h + 1, r, c], [h - 1, r, c], [h, r + 1, c], [h, r - 1, c], [h, r, c + 1], [h, r, c - 1]) : 
        if not (0 <= H < Height and 0 <= R < Row and 0 <= C < Column) : continue
        temp_list.append([H, R, C])
    
    if len(temp_list) == 0 : return False

    Result_list = []
    for H, R, C in temp_list : 
        if Tomato_table[H][R][C] == 0 and Visit_table[H][R][C] == 0 : 
            Result_list.append([H, R, C])

    return Result_list


import sys
input = sys.stdin.readline

from collections import deque

Column, Row, Height = map(int, input().split())

Tomato_table = [[[0 for i in range(Column)] for i in range(Row)] for i in range(Height)]
Visit_table = [[[0 for i in range(Column)] for i in range(Row)] for i in range(Height)]

for i in range(Height) : 
    for j in range(Row) : 
        temp_list = list(map(int, input().split()))
        Tomato_table[i][j] = temp_list
        del temp_list
    
# Tomato_table[Height][Row][Column]
# 1 : 있음, 0 : 아무것도 없음, -1 : 막힌 길

Queue = deque()

for h in range(Height) : 
    for r in range(Row) : 
        for c in range(Column) : 
                
            if Tomato_table[h][r][c] == 1 : 
                Visit_table[h][r][c] = 1
                Queue.append([h, r, c])

temp_max = 0
while Queue : 
    Current_list = Queue.popleft()
    h_index = Current_list[0]
    r_index = Current_list[1]
    c_index = Current_list[2]

    temp_max = max(temp_max, Tomato_table[h_index][r_index][c_index])

    temp_list = Valid_direction(h_index, r_index, c_index)

    if not temp_list : continue

    for H, R, C in temp_list : 
        Visit_table[H][R][C] = 1
        Tomato_table[H][R][C] = Tomato_table[h_index][r_index][c_index] + 1
        Queue.append([H, R, C])

for i in range(Height) : 
    for j in range(Row) : 
        for k in range(Column) : 
            if Visit_table[i][j][k] == 0  and Tomato_table[i][j][k] != -1 : 
                temp_max = 0

print(temp_max - 1)






