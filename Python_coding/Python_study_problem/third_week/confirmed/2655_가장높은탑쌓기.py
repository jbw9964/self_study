

# 거의 베낌

Num = int(input())

Tower_list = [[0, 0, 0, 0]]
for i in range(Num) : 
    temp = list(map(int, input().split()))
    temp.insert(0, i + 1)
    Tower_list.append(temp)

# Tower_list : [ 벽돌번호, 넓이, 높이, 무게 ]
    
Tower_list = sorted(Tower_list, key=lambda x : x[3])

D = [0 for i in range(Num + 1)]

# D : [ 최장 높이, 벽돌 개수, [그 경우 넣어진 벽돌 순서]]

for i in range(1, Num + 1) : 
    for j in range(0, i) : 
        if Tower_list[i][1] > Tower_list[j][1] : 
            D[i] = max(D[i], D[j] + Tower_list[i][2])

temp = max(D)

index = Num
Result = []
while index : 
    if D[index] == temp : 
        Result.append(Tower_list[index][0])
        temp -= Tower_list[index][2]
    
    index -= 1

print(len(Result))
for i in range(len(Result) - 1, -1, -1) : 
    print(Result[i])

    


# N = Num
# mapp = []
# mapp.append((1,1,1,1))
# for i in range(1,N+1):
#     mapp.append(Tower_list[i])
 
# #dp
# dp = [0]*(N+1)
# #무게 순으로 일단 정렬
# mapp.sort(key = lambda x: x[3])
 
# #mapp를 훑으면서 dp를 갱신
# for i in range(1,N+1):
#     for j in range(0,i):
#         if mapp[i][1]>mapp[j][1]: #현재 넓이가 훑으며 거쳐온 이전 넓이보다 클 때
#             dp[i] = max(dp[i], dp[j]+mapp[i][2])
            
# #가장 높이 쌓을 수 있는 높이 찾기
# max_height = max(dp)
 
# #기억을 더듬으며 백 트래킹
# index = N
# history = []
 
# while index!=0:
#     if dp[index]==max_height:
#         history.append(mapp[index][0])
#         max_height-=mapp[index][2]
#     index-=1
    
# print(len(history))
# history.reverse()
# for i in history:
#     print(i)





