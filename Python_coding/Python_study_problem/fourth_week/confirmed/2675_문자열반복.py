
# string class 여도 'a' + 'b' = 'ab' 가 되고, 'a' += 'b' : 'ab' 가 되는줄은 몰랐음.
# C++ 이나 다른언어에서 되는 줄 알았는데 파이썬에서도 되네.

import sys
input = sys.stdin.readline

N = int(input())

# temp = 'hello'
# temp += ' hi'
# print(temp)

Result_list = []
for _ in range(N) : 
    count, raw_string = input().split()
    count = int(count)
    raw_string = str(raw_string)
    
    temp_str = str()
    for i in range(len(raw_string)) : 
        temp_str += raw_string[i] * count
    
    Result_list.append(temp_str)

for string in Result_list : 
    print(string)