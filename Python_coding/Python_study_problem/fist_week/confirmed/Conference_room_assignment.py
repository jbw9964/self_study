
print("\n\n")

def Check_CoConf_list(Co_conf_list, Target) -> bool :

    for i in Co_conf_list : 
        if Target == i : return True

    return False

def Max_CoConf_Index(Conf_list) -> int :
    
    Max = -1
    Index = -1
    Num = len(Conf_list)
    for i in range(0, Num) :
        if not Conf_list[i]['Valid'] : continue
        temp = (Conf_list[i]).get('Co_num')

        if Max < temp : 
            Max = temp
            Index = i

    if not Max : return -1

    return Index

Conf_num = int(input("Input : "))
Conf_list = []

for i in range(0, Conf_num) : 
    temp_1, temp_2 = input().split()
    Dict = {f'Start':int(temp_1), 'End':int(temp_2), 'Valid':True, 'Co_num':0}
    Dict['Co_conf_list'] = []
    Conf_list.append(Dict)
    del Dict
    del temp_1, temp_2


for i in range(0, Conf_num) :
    start = (Conf_list[i]).get('Start')
    end = (Conf_list[i]).get('End')

    for j in range(0, Conf_num) :
        if i == j : continue

        check_start = (Conf_list[j]).get('Start')
        check_end = (Conf_list[j]).get('End')

        if (start <= check_start < check_end) and (start < check_end <= end) : 
            (Conf_list[i])['Co_num'] += 1
            (Conf_list[i])['Co_conf_list'].append(j)
            continue

        if check_start <= start < check_end : 
            (Conf_list[i])['Co_num'] += 1
            (Conf_list[i])['Co_conf_list'].append(j)
        elif check_start < end <= check_end :
            (Conf_list[i])['Co_num'] += 1
            (Conf_list[i])['Co_conf_list'].append(j)

Max_index = Max_CoConf_Index(Conf_list)
while True : 

    for i in Conf_list : 
        if not i['Valid'] : continue
        if i == Conf_list[Max_index] : continue
        
        if Check_CoConf_list(i['Co_conf_list'], Max_index) :
            
            i['Co_num'] -= 1
            i['Co_conf_list'].remove(Max_index)

    
    Conf_list[Max_index]['Valid'] = False

    Max_index = Max_CoConf_Index(Conf_list)
    if not Conf_list[Max_index]['Co_num'] or Max_index == -1 : break

count = 0

print()
for i in Conf_list : 
    if not i['Valid'] : continue
    print(i)
    count += 1

print(count)




'''
<input>
7
0 1
0 2
1 3
4 6
2 5
3 4
4 5

<output> : 4
'''








print("\n\n")




# 2 번째 만든 코드

# # def Conf_print(Conf_list) -> None : 
# #     for i in Conf_list : 
# #         if not i[3] : continue
# #         print(str(i[0]).rjust(3), str(i[1]).rjust(3), str(i[2]).rjust(3), str(i[3]).rjust(4), i[4], sep=", ", end="\n")

# Conf_num = int(input("Input : "))
# Conf_list = []                      # Conf_list = [start, end, Co_num, valid, Co_list]

# for i in range(0, Conf_num) : 
#     temp_1, temp_2 = input().split()
#     temp_list = [int(temp_1), int(temp_2)]
#     temp_list.append(0)
#     temp_list.append(True)
#     temp_list.append([])
#     Conf_list.append(temp_list)
#     del temp_1, temp_2, temp_list

# for i in range(0, Conf_num) :
#     start = Conf_list[i][0]
#     end = Conf_list[i][1]

#     for j in range(0, Conf_num) :
#         if i == j : continue

#         check_start = Conf_list[j][0]
#         check_end = Conf_list[j][1]

#         if (start <= check_start < check_end) and (start < check_end <= end) : 
#             Conf_list[i][2] += 1
#             Conf_list[i][4].append(j)
#             continue

#         if check_start <= start < check_end : 
#             Conf_list[i][2] += 1
#             Conf_list[i][4].append(j)
#         elif check_start < end <= check_end :
#             Conf_list[i][2] += 1
#             Conf_list[i][4].append(j)

# # Conf_print(Conf_list)
# # print()

# while True : 
#     Valid_list = []
#     Max_index = -1
#     Max_Co_num = -1
#     for i in range(len(Conf_list)) : 
#         if not Conf_list[i][3] : continue
#         if Max_Co_num < Conf_list[i][2] : 
#             Max_Co_num = Conf_list[i][2]
#             Max_index = i
#         Valid_list.append(i)

#     if not Max_Co_num : break

#     for index in Valid_list : 
#         if index == Max_index : 
#             Conf_list[index][3] = False
#             continue

#         Valid_Conf = Conf_list[index]
#         Check = str(Valid_Conf[4])

#         if Check.find(str(Max_index)) != -1: 
#             Valid_Conf[2] -= 1
#             Valid_Conf[4].remove(Max_index)
            
#     # Conf_print(Conf_list)
#     # print()

#     del Valid_list, Max_index, Max_Co_num

# count = 0
# for temp in Conf_list : 
#     if not temp[3] : continue
#     count += 1

# print(count)



