

# 이번건 거의 배끼다 시피 해서 잘 이해한 건지 모르겠음
# 게다가 뭐 때문인진 몰라도 Visit_table 을 [-1, 0] 으로 초기화 해야 잘 돌아감.
# 당연히 Visit_table[Pos][0] = 1 뭐 이런거 다 설정해도 그럼

from collections import deque
import time

Pos, Target = map(int, input().split())

start = time.time()

Visit_table = [[-1, 0] for i in range(10**5 + 1)]
# Visit_table = [ [몇번째에 방문 했는지, 그 수까지 갈 수 있는 최단의 경우의 수들], ... ]
# 방문 안했으면 -1, 아직 경우의 수가 채워지지 않았으니까 0

Visit_table[Pos][0] = 0     # 자기자신은 0번 이동하면 되니까
Visit_table[Pos][1] = 1     # 자기자신한테 갈 수 있는 최단경로의 경우의 수는 자기 자신밖에 없으니까

Queue = deque()
Queue.append(Pos)

while Queue : 
    value = Queue.popleft()         # value : Queue 에서 나와 왼쪽, 오른쪽, 2 * 에 대해 확인할 수

    for Check in (value + 1, value - 1, 2 * value) : 

        if 0 <= Check <= 10**5 : 

            # Visit_table[Check] : 왼쪽, 오른쪽, 2 * 인 수 중 하나
            # Visit_table[value] : Queue 에서 나온 수의 방문횟수 또는 Queue 에서 나온 수까지 갈 수 있는 경우의 수

            if Visit_table[Check][0] == -1 :                            # 아직 방문하지 않았다면
                Visit_table[Check][0] = Visit_table[value][0] + 1
                Visit_table[Check][1] = Visit_table[value][1]
                Queue.append(Check)
            
            elif Visit_table[Check][0] == Visit_table[value][0] + 1 :   # 방문 했었는데 지금 확인한 경우가 최단경로일 때
                Visit_table[Check][1] += Visit_table[value][1]          # Queue 에서 나온 수에서 바로 한칸만 이동할 수 있는 경우는 최단경로이므로
                
print(Visit_table[Target][0])
print(Visit_table[Target][1])

end = time.time()

print(end - start, 'sec')

# from collections import deque

# def bfs(n):
#     q = deque([n])
#     visited[n][0] = 0
#     visited[n][1] = 1 
    
#     while q:
#         x = q.popleft()
        
#         for i in [x - 1, x + 1, x * 2]:
#             if 0 <= i <= 100000:
#                 if visited[i][0] == -1: # 처음 도달한다면
#                     visited[i][0] = visited[x][0] + 1 # 걸린 시간 저장
#                     visited[i][1] = visited[x][1] # 경우의 수 저장
#                     q.append(i)
                    
#                 elif visited[i][0] == visited[x][0] + 1: # 처음이 아니라면 (하지만 최단 시간이라면)
#                     visited[i][1] += visited[x][1] # 경우의 수 갱신
                    
# n, k = map(int, input().split())
# visited = [[-1, 0] for _ in range(100001)] # [지점 i에 도달하는데 걸린 시간, 경우의 수]

# bfs(n)
# print(visited[k][0])
# print(visited[k][1])