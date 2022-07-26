
raw_string = str(input())

D = [-1 for _ in range(ord('z') - ord('a') + 1)]        # 총 26개 / 알파벳 26개

for i in range(len(raw_string)) : 
    if D[ord(raw_string[i]) - ord('a')] == -1 : 
        D[ord(raw_string[i]) - ord('a')] = i

for value in D : 
    print(value, end=' ')
print()