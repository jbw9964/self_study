
import sys
input = sys.stdin.readline

Num = int(input())

Num_list = [0]
temp = list(map(int, input().split()))

for num in temp : 
    Num_list.append(num)

Table = [0 for i in range(Num + 1)]

# 지금 확인하는 수 보다 작은 수의 개수를 Table 에 저장함
# Table 에서 가장 큰 수가 답

# 지금 확인하는 수 : Num_list[i]
# 작은지 확인하는 수 : Num_list[j]

# Table[i] = Table[j] : (작은지 확인하는 수 보다 작은 수의 개수는 이미 저장되어 있으니까) 그 수만큼으로 만든다.
# i > j 니까 j 에 대해선 모두 초기화 되어 있으니까

for i in range(1, Num + 1) : 
    for j in range(1, i) : 
        if Num_list[j] < Num_list[i] and Table[i] < Table[j]: 
            Table[i] = Table[j]
    Table[i] += 1
    
print(max(Table))


# 그냥 배낌
# 스스로 생각할 수 없었음.

