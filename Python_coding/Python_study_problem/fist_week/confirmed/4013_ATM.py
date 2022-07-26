
import re

Num = int(input())

Waiting_List = []

Waiting_string = str(input())
numbers = re.findall(r'\d+', Waiting_string)

for i in numbers : 
    Waiting_List.append(int(i))

# for i in range(0, Num) :
#     temp = int(input())
#     Waiting_List.append(temp)
#     del temp

Waiting_List.sort()

Prev = Waiting_List[0]
Result = Waiting_List[0]
for index in range(1, len(Waiting_List)) : 
    
    Result += Prev + Waiting_List[index]
    Prev += Waiting_List[index]
    
print(Result)
# print("Result : {0}".format(Result))


# 1                 --> 1
# 1 + 2             --> 1 + (1 + 2) = 4
# 1 + 2 + 3         --> 4 + (1 + 2 + 3) = 10
# 1 + 2 + 3 + 3     --> 10 + (1 + 2 + 3 + 3) = 19
# 1 + 2 + 3 + 3 + 6 --> 19 + (1 + 2 + 3 + 3 + 6) = 34


'''
<input>
5
3
2
1
6
3

<output> : 34
'''


