
def DFS_visit(Row_index, Column_index, Raw_table, Visit_table, valid) -> int:          # 인접한 vertex 들의 수를 반환

    if Row_index < 0 or Column_index < 0 : return -1
    if Raw_table[Row_index][Column_index] == valid and Visit_table[Row_index][Column_index] == 0 : 
        Visit_table[Row_index][Column_index] += 1
    else : return -1

    try :       # 오른쪽 이동
        right = DFS_visit(Row_index, Column_index + 1, Raw_table, Visit_table, valid) + 1
    except : right = 0

    try :       # 아랫쪽 이동
        down = DFS_visit(Row_index + 1, Column_index, Raw_table, Visit_table, valid) + 1
    except : down = 0

    try :       # 왼쪽 이동
        left = DFS_visit(Row_index, Column_index - 1, Raw_table, Visit_table, valid) + 1
    except : left = 0

    try :       # 윗쪽 이동
        up = DFS_visit(Row_index - 1, Column_index, Raw_table, Visit_table, valid) + 1
    except : up = 0

    return right + down + left + up

def DFS(Matrix_row, Matrix_column, Raw_table) -> int: 

    Visit_table = [[0 for i in range(Matrix_column)] for i in range(Matrix_row)]

    Result_white = 0
    Result_blue = 0

    for i in range(Matrix_row) : 

        for j in range(Matrix_column) : 
            if Visit_table[i][j] == 0 : 
                temp_valid = Raw_table[i][j]
                temp = DFS_visit(i, j, Raw_table, Visit_table, temp_valid) + 1
                if Raw_table[i][j] : 
                    Result_white += temp**2
                else : 
                    Result_blue += temp**2


    return Result_white, Result_blue



import sys

input = sys.stdin.readline

Matrix_column, Matrix_row = map(int, input().split())

Raw_table = [[True for i in range(Matrix_column)] for i in range(Matrix_row)]

for i in range(Matrix_row) : 
    Raw_string = str(input())
    Raw_string.upper()

    for j in range(len(Raw_string)) : 
        text = Raw_string[j]
        if text == '\n' : break
        if text == 'W' or text == 'w': continue

        Raw_table[i][j] = False
        

White, Blue = DFS(Matrix_row, Matrix_column, Raw_table)

print(White, Blue)









'''
<input>
5 5
WWWBW
WWWBB
BBWBW
BBBWW
BWWBW


W W W B W           W : 49 + 1 + 16 + 4 = 70
W W W B B           B : 16 + 36 + 1 = 53
B B W B W
B B B W W
B W W B W


<output> : 70 53

<input>
5 5
WBWWW
WWWWW
BBBBB
BBBWW
WWWWW

W B W W W
W W W W W
B B B B B
B B B W W
W W W W W

<output> : 130 65

3 3
www
bbb
wwb

2 4
WW
WW
BB
WB



'''


