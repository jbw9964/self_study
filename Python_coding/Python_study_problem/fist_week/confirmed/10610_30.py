
print("\n\n")


String_input = str(input())

Num_list = []

for i in range(0, len(String_input)) : 
    temp = String_input[i]
    temp = int(temp)
    Num_list.append(temp)
    del temp

Result = True

if String_input.find('0') == -1 : Result = False
else : Num_list.remove(0)

temp = 0
for i in range(0, len(Num_list)) : 
    temp += Num_list[i]

if temp % 3 != 0 : Result = False
else : 
    Num_list.sort()
    Num_list.reverse()
    Num_string = []
    for i in Num_list : 
        temp = str(i)
        Num_string.append(temp)
    Num_string.append('0')


if not Result : print("Result : -1")
else : 
    print("Result : ", end='')
    for i in range(0, len(Num_string)) :
        print(Num_string[i], end='')
    print()


print("\n\n")



'''
<input>
9133805

<output> : -1

<input>
80875542

<output> : 88755420
'''