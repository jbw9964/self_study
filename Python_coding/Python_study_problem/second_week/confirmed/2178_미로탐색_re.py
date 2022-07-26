
from collections import deque

import time
import sys
input = sys.stdin.readline

Row, Column = map(int, input().split())

start = time.time()

Maze_table = [[0 for i in range(Column)] for i in range(Row)]
Visit_table = [[False for i in range(Column)] for i in range(Row)]

for i in range(Row) : 
    raw_string = str(input())

    for j in range(len(raw_string)) : 
        if raw_string[j] == '\n' : break

        if raw_string[j] == '1' : 
            Maze_table[i][j] = 1


Queue = deque()
Queue.append([0, 0])

Visit_table[0][0] = True

while True : 
    row_index, column_index = Queue.popleft()

    if row_index == Row - 1 and column_index == Column - 1 : 
        print(Maze_table[row_index][column_index])
        break

    for Check_pos in ([row_index, column_index + 1], [row_index + 1, column_index], [row_index, column_index - 1], [row_index - 1, column_index]) : 
        # 오른쪽, 아래, 왼쪽, 위
        pos_x = Check_pos[0]
        pos_y = Check_pos[1]

        if 0 <= pos_x <= Row - 1 and 0 <= pos_y <= Column - 1 : 
            
            if Maze_table[pos_x][pos_y] != 0 and not Visit_table[pos_x][pos_y] : 
                Maze_table[pos_x][pos_y] = Maze_table[row_index][column_index] + 1
                Visit_table[pos_x][pos_y] = True
                Queue.append([pos_x, pos_y])

end = time.time()

print(end - start, 'sec')
