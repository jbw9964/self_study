
import sys
input = sys.stdin.readline

D = [-1 for i in range(ord('z') - ord('a') + 1)]

# print(ord('z'))
# print(ord('a'))
# print(ord('z') - ord('a'))
# print(ord('a') - ord('a'))
# print(D[1])
# print(D[25])

N = int(input())

Result_list = []
for i in range(N) : 
    raw_string = str(input())

    D = [-1 for i in range(ord('z') - ord('a') + 1)]
    
    index_count = 0     
    while True : 
        text = raw_string[index_count]

        if text == '\0' or text == '\n' : 
            Result_list.append(True)
            break

        ascii = ord(raw_string[index_count]) - ord('a')         # a : 0 / z : 25
        
        if D[ascii] == -1 : 
            D[ascii] = index_count
            index_count += 1
            continue
        
        elif D[ascii] == index_count - 1 : 
            D[ascii] = index_count
            index_count += 1
        
        else : break

print(len(Result_list))