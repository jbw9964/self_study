
print('\n\n')
Raw_string = str(input())

Num_list = []
Oper_list = []

count = 0
while True : 

    if count == len(Raw_string) : break

    text = Raw_string[count]

    if text == '+' or text == '-' : 
        Oper_list.append(text)
        count += 1
        continue
    
    temp_num = 0
    while count != len(Raw_string) and Raw_string[count] != '+' and Raw_string[count] != '-': 
        temp_num *= 10
        temp_num += int(Raw_string[count])
        count += 1
    
    Num_list.append(temp_num)

valid_index = -1
for i in range(len(Oper_list)) : 
    temp = Oper_list[i]
    if temp == '-' : 
        valid_index = i
        break

sum = 0

if valid_index == -1 : 
    for temp in Num_list : 
        sum += temp
    print(sum)

else : 
    for index in range(valid_index + 1) : 
        sum += Num_list[index]

    for i in range(index + 1, len(Num_list)) : 
        sum -= Num_list[i]

    print(sum)








print('\n\n')










