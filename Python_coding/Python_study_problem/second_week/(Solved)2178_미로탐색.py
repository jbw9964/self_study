
# 개망함 다 꼬임

def Path_available(Row_index, Column_index, Maze_table, Prev_pos) -> list: 

    temp_list = []
    try : 
        if Maze_table[Row_index][Column_index + 1] == 1 : 
            temp_list.append("Right")
    except : pass

    try : 
        if Maze_table[Row_index + 1][Column_index] == 1 : 
            temp_list.append("Down")
    except : pass

    try : 
        if Maze_table[Row_index - 1][Column_index] == 1 and Row_index - 1 >= 0 : 
            temp_list.append("Up")
    except : pass
    
    try : 
        if Maze_table[Row_index][Column_index - 1] == 1 and Column_index - 1 >= 0 : 
            temp_list.append("Left")
    except : pass

    if not Prev_pos[0] == None : 
        temp_list.remove(Prev_pos[0])

    return temp_list

def Search(Row, Column, Maze_table, Row_index, Column_index, Prev_pos) :

    count = 0
    while True : 

        while len(Path_available(Row_index, Column_index, Maze_table, Prev_pos)) == 1 : 
            if Row - 1 == Row_index and Column - 1 == Column_index : return count
            count += 1
            Path = Path_available(Row_index, Column_index, Maze_table, Prev_pos)[0]
            # Path = Path[0]

            if Path == "Right" :                                # 오른쪽 이동
                Column_index += 1
                Prev_pos = ["Left"]
            elif Path == "Down" :                               # 아래 이동
                Row_index += 1
                Prev_pos = ["Up"]
            elif Path == "Up" :                                 # 위쪽 이동
                Row_index -= 1
                Prev_pos = ["Down"]
            else :                                              # 왼쪽 이동
                Column_index -= 1
                Prev_pos = ["Right"]

        if Row - 1 == Row_index and Column - 1 == Column_index : return count

        Path = Path_available(Row_index, Column_index, Maze_table, Prev_pos)
        temp_list = []
        for i in range(len(Path)) : 
            Way = Path.pop()

            if Way == "Right" : 
                temp_list.append(Search(Row, Column, Maze_table, Row_index, Column_index + 1, ["Left"]))
            if Way == "Down" : 
                temp_list.append(Search(Row, Column, Maze_table, Row_index + 1, Column_index, ["Up"]))
            if Way == "Up" : 
                temp_list.append(Search(Row, Column, Maze_table, Row_index - 1, Column_index, ["Down"]))
            if Way == "Left" : 
                temp_list.append(Search(Row, Column, Maze_table, Row_index, Column_index - 1, ["Right"]))
        break

    try : 
        count += min(temp_list)
    except : pass
    
    return count

import sys

input = sys.stdin.readline

Row, Column = map(int, input().split())

Maze_table = [[0 for i in range(Column)] for i in range(Row)]

for i in range(Row) : 
    Raw_string = str(input())

    for j in range(Column) : 
        text = Raw_string[j]

        if text == '\n' : break
        if text == '1' : Maze_table[i][j] = 1

Prev_pos = [None]

result = Search(Row, Column, Maze_table, 0, 0, Prev_pos)

print(result)
