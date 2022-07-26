
Num = int(input())

List = [0]
for i in range(Num) : 
    List.append(int(input()))

D = [0 for i in range(Num + 1)]

try : 
    D[1] = List[1]
    D[2] = List[1] + List[2]
    D[3] = max(List[2], List[1]) + List[3]
except : 
    sum = 0
    for value in List : sum += value
    D[Num] = sum

for i in range(4, Num + 1) : 
    D[i] = max(D[i - 2], D[i - 3] + List[i - 1]) + List[i]
print(D[Num])




# D = [[0, 0] for i in range(Num + 1)]
# D : [ [총 점수, 그 때 도착하는 부분에서 연속하는 개수] ]

# D[1] = [List[1], 1]

# for i in range(2, Num + 1) : 

#     if D[i - 1][1] < 2 and D[i][0] < D[i - 1][0] + List[i]: 
#         D[i][0] = D[i - 1][0] + List[i]
#         D[i][1] = D[i - 1][1] + 1

#     for j in range(i - 2, 0, -1) : 
        
#         if D[i][0] < D[j][0] + List[i] : 
#             D[i][0] = D[j][0] + List[i]
#             D[i][1] = 1

#     if D[i][0] < D[i - 3][0] + List[i - 1] + List[i] : 
#         D[i][0] = D[i - 3][0] + List[i - 1] + List[i]
#         D[i][1] = 2
        
# print(D[Num][0])



