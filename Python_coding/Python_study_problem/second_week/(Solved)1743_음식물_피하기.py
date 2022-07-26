
def Search_visit(Table, Visit_table, Row_index, Column_index) -> int : 

    if Row_index < 0 or Column_index < 0 : return -1
    if Table[Row_index][Column_index] == True and Visit_table[Row_index][Column_index] == 0 : 
        Visit_table[Row_index][Column_index] += 1
    else : return -1

    try :       # 오른쪽 이동
        right = Search_visit(Table, Visit_table, Row_index, Column_index + 1) + 1
    except : right = 0

    try :       # 아랫쪽 이동
        down = Search_visit(Table, Visit_table, Row_index + 1, Column_index) + 1
    except : down = 0

    try :       # 왼쪽 이동
        left = Search_visit(Table, Visit_table, Row_index, Column_index - 1) + 1
    except : left = 0

    try :       # 윗쪽 이동
        up = Search_visit(Table, Visit_table, Row_index - 1, Column_index) + 1
    except : up = 0

    return right + down + left + up


def Search(Row, Column, Table) -> int : 

    Visit_table = [[0 for i in range(Column)] for i in range(Row)]

    Prev = 0
    for i in range(Row) : 
        for j in range(Column) : 

            if Visit_table[i][j] == 0 and Table[i][j]:
                temp = Search_visit(Table, Visit_table, i, j) + 1
                Prev = max(temp, Prev)

    return Prev

import sys

input = sys.stdin.readline

Row, Column, Trash_num = map(int, input().split())

Table = [[False for i in range(Column)] for i in range(Row)]

for i in range(Trash_num) : 
    pos_row, pos_column = map(int, input().split())
    Table[pos_row - 1][pos_column - 1] = True

result = Search(Row, Column, Table)

print(result)

'''

5 5 15
1 1 
1 2
1 3
1 4
1 5
3 1
3 3
3 5
4 1
4 2
4 3
4 4
4 5
2 2
2 4

o o o o o
x o x o x
o x o x o
o o o o o
x x x x x

3 4 7
3 2
2 2
3 1
2 3
1 1
3 4
2 4

1 3 2
1 1
1 3

4 5 8
1 2
2 3
2 4
2 5
3 3
3 4
4 1
4 4

'''