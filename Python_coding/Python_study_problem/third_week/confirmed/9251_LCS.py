
import sys
input = sys.stdin.readline

str_1 = list(str(input()))
str_2 = list(str(input()))
str_1.pop()
str_2.pop()

D_table = [[0 for i in range(len(str_1) + 1)] for i in range(len(str_2) + 1)]

# D_table[i][j] = l
# str_1 중 j 번째 문자 + str_2 중 i 번째 문자 합쳐서 생각했을 때, 최장길이 l
# i : str_2, j : str_1

for index_2 in range(1, len(str_2) + 1) : 
    for index_1 in range(1, len(str_1) + 1) : 
        if str_1[index_1 - 1] == str_2[index_2 - 1] : 
            D_table[index_2][index_1] = D_table[index_2 - 1][index_1 - 1] + 1

            # D_table[i][j] : ACA / CA
            # D_table[i - 1][j - 1] : AC / C    --> ACA / CA 경우 최장길이는 AC / C 에서 하나 더 커진 값이므로
            # D_table[i][j] = D_table[i - 1][j - 1] + 1 이라 해야됨

        else : 
            D_table[index_2][index_1] = max(D_table[index_2][index_1 - 1], D_table[index_2 - 1][index_1])

print(D_table[len(str_2)][len(str_1)])


# 충분히 이해 안됨
# 답이 나오는 이유는 알겠는데 혼자서 생각해내지는 못 하겠음.


D = [0 for i in range(len(str_1))]

for i in range(len(str_2)) : 
    temp_max = 0
    for j in range(len(str_1)) : 
        
        if temp_max < D[j] : temp_max = D[j]

        elif str_2[i] == str_1[j] : 
            D[j] = temp_max + 1
            
print(max(D))





