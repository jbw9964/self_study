
# 그냥 문제 보고 DFS 로 풀 수 있을것 같기도 해서 품.
# 근데 채점하니 역시 메모리 초과로 할 수 없음.

# 약간 당연하면서도 신기한게 DFS 로 만들면 공간복잡도는 2^n 이 됨.
# 그리고 같은 논리를 사용하고 그 계산 결과들을 DP 로 저장하면 이때는 n^2 밖에 안됨.
# 같은 논리를 사용해도 메모리 초과가 안 날 수 있다는게 되게 신기했음.

import sys
input = sys.stdin.readline

N, S, M = map(int, input().split())
V = list(map(int, input().split()))

D = [[0 for i in range(M + 1)] for i in range(N + 1)]
D[0][S] = 1

result = 0
for i in range(N) : 
    value = V[i]
    temp_count = False
    for j in range(M + 1) : 
        
        if D[i][j] == 1: 
            if 0 <= j - value <= M : 
                D[i + 1][j - value] = 1
                temp_count = True
            if 0 <= j + value <= M : 
                D[i + 1][j + value] = 1
                temp_count = True
            
    if not temp_count : 
        result = -1
        break
        
if result != -1 : 
    for count in range(M, 0, -1) : 
        if D[N][count] == 1 : 
            result = count
            break
    
print(result)


# import time
# from collections import deque

# N, S, M = map(int, input().split())

# V = deque(map(int, input().split()))

# start = time.time()

# Queue = deque()
# Queue.append(S)

# for value in V : 
#     temp_queue = deque()

#     while Queue : 
#         Current = Queue.popleft()

#         if 0 <= Current - value <= M : 
#             temp_queue.append(Current - value)
#         if 0 <= Current + value <= M : 
#             temp_queue.append(Current + value)
    
#     if len(temp_queue) == 0 : 
#         Queue.append(-1)
#         break    

#     Queue = temp_queue.copy()
#     del temp_queue

# print(max(Queue))

# end = time.time()

# print(end - start, 'sec')
