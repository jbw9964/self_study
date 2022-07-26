


print("\n\n")

import re

Room_cap = int(input())

Apply_list = []

Apply_string = str(input())
numbers = re.findall(r'\d+', Apply_string)

for i in numbers : 
    Apply_list.append(int(i))


Senior_supervisor, Junior_supervisor = input().split()
Senior_supervisor = int(Senior_supervisor)
Junior_supervisor = int(Junior_supervisor)

# count = 0
# for i in range(0, len(Apply_list)) :

#     Applier = Apply_list[i]
#     Applier -= Senior_supervisor
#     count += 1

#     if Applier <= 0 : continue

#     while Applier > 0 : 
#         Applier -= Junior_supervisor
#         count += 1


count = 0
for i in range(len(Apply_list)) : 
    
    Apply_list[i] -= Senior_supervisor
    count += 1

    if Apply_list[i] <= 0 : continue

    if Apply_list[i] % Junior_supervisor == 0 : 
        count += Apply_list[i] // Junior_supervisor
        continue
    count += (Apply_list[i] // Junior_supervisor) + 1


print(count)


print("\n\n")





'''
<input>
3
1
4
6
2 4 

<output> : 5
'''