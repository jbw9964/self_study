
def print_dict(Conf_list) : 

    for Current in Conf_list : 
        print(f"[{str(Current['start']).zfill(2):2s}]", f"[{str(Current['end']).zfill(2):2s}]", sep='~', end='  ')
    print()


# 문제 해결법 : 주어진 데이터를 끝나는 시간(우선) + 시작하는 시간 으로 정렬
# 정렬 후 처음부터 시작해서 겹치는거 제외하고 세면 됨.

Conf_num = int(input())

Conf_list = []

for i in range(Conf_num) : 
    temp = list(map(int, input().split()))
    temp_dict = {"start":temp[0], "end":temp[1]}
    Conf_list.append(temp_dict)


Conf_list = sorted(Conf_list, key=lambda x : x["start"])
Conf_list = sorted(Conf_list, key=lambda x : x["end"])
# print_dict(Conf_list)


Prev_end = Conf_list[0]['end']

count = 1
for i in range(1, len(Conf_list)) : 

    Current_start = Conf_list[i]['start']
    Current_end = Conf_list[i]['end']

    if Current_start < Prev_end : 
        continue

    Prev_end = Current_end
    count += 1

print(count)




'''
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14


13
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 10
9 10
10 10
8 12
2 13
12 14

'''