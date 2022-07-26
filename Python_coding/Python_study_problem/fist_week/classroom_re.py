
# def lecture_print(Lecture_list) -> None : 

#     for i in range(len(Lecture_list)) : 

#         print(f"[{Lecture_list[i][0]} ~ {Lecture_list[i][1]}]", end=' ')
#     print()

import sys

input = sys.stdin.readline
Lecture_num = int(input())

Lecture_list = []
for i in range(Lecture_num) : 
    start, end = map(int, input().split())

    Lecture_list.append([start, end])

Lecture_list = sorted(Lecture_list, key=lambda x : x[0])
Lecture_list = sorted(Lecture_list, key=lambda x : x[1])

End_Table = [Lecture_list[0][1]]

for i in range(1, len(Lecture_list)) : 

    Current_start = Lecture_list[i][0]
    Current_end = Lecture_list[i][1]

    temp_valid = False
    for index in range(len(End_Table)) : 

        if End_Table[index] <= Current_start : 
            End_Table[index] = Current_end
            temp_valid = True
            break
        
    if not temp_valid : 
        End_Table.append(Current_start)
        End_Table.sort()


print(len(End_Table))

# 결과적으로 답은 맞게 출력하는 것 같은데 백준에서 채점하니까 시간초과가 뜸. 
# 검색해보니 Heap 으로 가능하다 하는데, 파이썬에서 어떻게 구현하는지 잘 모르겠고 그 방식이 잘 이해가 안되서 막힘.





'''
<input>
7
0 1
1 4
1 2
3 6
2 3
4 6
5 6

<output> : 3

<input>
5
0 1
1 4
2 4
3 4
4 5

<output> : 3
'''