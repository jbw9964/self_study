
# 생각보다 문제가 간단해서 그냥 재귀형태로 만들을 수도 있음
# 물론 메모리는 그냥 하는거에 2배정도 더 먹음
# 근데 개빠름 64ms 더라


Num = int(input())

D = [0 for i in range(Num + 1)]

#
# D[1] = 1

# for i in range(1, Num + 1) : 

#     for index in (i + 1, 2 * i, 3 * i) : 
        
#         if index > Num : continue

#         if D[index] != 0 : 
#             D[index] = min(D[index], D[i] + 1)
#             continue
        
#         D[index] = D[i] + 1
    
# print(D[Num] - 1)
#

D[Num] = 1

for i in range(Num, 1, -1) : 

    if i % 2 == 0 : 
        if D[int(i / 2)] == 0 : D[int(i / 2)] = D[i] + 1
        else : 
            D[int(i / 2)] = min(D[i] + 1, D[int(i / 2)])

    if i % 3 == 0 : 
        if D[int(i / 3)] == 0 : D[int(i / 3)] = D[i] + 1
        else : 
            D[int(i / 3)] = min(D[i] + 1, D[int(i / 3)])
        
    if D[i - 1] == 0 : D[i - 1] = D[i] + 1
    else : 
        D[i - 1] = min(D[i] + 1, D[i - 1])

    if i - 1 == 1 or i / 2 == 1 or i / 3 == 1 : break

print(D[1] - 1)

