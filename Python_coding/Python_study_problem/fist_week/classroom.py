
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

    Lecture_list.append({'start':start, 'end':end})

# lecture_print(Lecture_list)
Lecture_list = sorted(Lecture_list, key=lambda x : x['start'])
Lecture_list = sorted(Lecture_list, key=lambda x : x['end'])

# lecture_print(Lecture_list)

Prev_end = Lecture_list[0]['end']
End_Table = [Prev_end]

for i in range(1, len(Lecture_list)) : 

    Current_start = Lecture_list[i]['start']
    Current_end = Lecture_list[i]['end']

    valid = False
    for temp in range(len(End_Table)) : 

        if End_Table[temp] <= Current_start : 
            End_Table[temp] = Current_end
            valid = True
            break
        
    if not valid : 
        End_Table.append(Current_start)


print(len(End_Table))
    







'''

7
0 1
1 4
1 2
3 6
2 3
4 6
5 6

3

'''


