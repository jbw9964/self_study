
import sys
input = sys.stdin.readline

raw_string = str(input())

Num_dict = {'A':2,'B':2,'C':2,'D':3,'E':3,'F':3,'G':4,'H':4,'I':4,'J':5,'K':5,'L':5,'M':6,'N':6,'O':6,'P':7,'Q':7,'R':7,'S':7,'T':8,'U':8,'V':8,'W':9,'X':9,'Y':9,'Z':9}

sum = 0
index_count = 0
while True : 
    text = raw_string[index_count]

    if text == '\0' or text == '\n' : break
    
    sum += Num_dict[text] + 1
    index_count += 1

print(sum)


'''
이렇게도 되네?
'''
# s = input()
# list1 = list(s)
# phone = {"ABC":2,"DEF":3,"GHI":4,"JKL":5,"MNO":6,"PQRS":7,"TUV":8,"WXYZ":9}
# answer = 0
# for i in list1:
#     for key,value in phone.items():
#         if i in key:
#             answer += value+1
# print(answer)