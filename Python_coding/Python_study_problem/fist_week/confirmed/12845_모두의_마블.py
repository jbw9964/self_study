
import re

Card_num = int(input())

Raw_string = str(input())
number = re.findall('\d+', Raw_string)

Card_list = []
for i in range(Card_num) : 
    temp = int(number[i])
    Card_list.append(temp)

Max = max(Card_list)

sum = 0
temp = False
for List in Card_list : 
    sum += Max + List

sum -= 2 * Max

print(sum)





