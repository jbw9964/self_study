
# Topological sort 이용해 풀음
# 되게 신기(?)한게 처음에는 Adjacent Matrix 형태로 간선정보를 저장했음. 이를 바탕으로 문제를 푸니 메모리 초과가 남.
# 그래서 Adjacent list 형태로 저장하고 푸니 잘 맞음.
# 약간 문제 기본 조건들 보고서 Matrix / List 형식으로 저장할지 판단할 수 있었으면 좋겠는데, 그걸 잘 모르겠음.

from collections import deque
import sys
input = sys.stdin.readline

def solution(N : int, M : int) : 
    
    E = [[-1] for i in range(N)]
    Indeg = [0 for i in range(N)]
    for i in range(M) : 
        temp_1, temp_2 = map(int, input().split())
        E[temp_1 - 1].append(temp_2 - 1)
        Indeg[temp_2 - 1] += 1

    Queue = deque()
    Result_list = []
    for index, in_num in enumerate(Indeg) : 
        if in_num == 0 : 
            Queue.append(index)
            Result_list.append(index)

    while Queue : 
        Current = Queue.popleft()

        index_count = 0

        while index_count < len(E[Current]) : 
            Adjacent = E[Current][index_count]
            if Adjacent == -1 : 
                index_count += 1
                continue
            
            Indeg[Adjacent] -= 1

            if Indeg[Adjacent] == 0 : 
                Queue.append(Adjacent)
                Result_list.append(Adjacent)
            
            index_count += 1


    for value in Result_list : 
        print(value + 1, end=' ')
    print()

if __name__ == '__main__' : 
    N, M = map(int, input().split())

    if N == 1 : print(1)
    elif N == 2 : 
        temp_1, temp_2 = map(int, input().split())
        print(temp_1, temp_2)
    else : 
        solution(N, M)


'''
Adjacent Matrix 이용 풀이
'''
# from collections import deque
# import sys
# input = sys.stdin.readline

# def solution(N : int, M : int) : 
    
#     E = [[False for i in range(N)] for i in range(N)]

#     indegree = [0 for i in range(N)]
#     for i in range(M) : 
#         temp_1, temp_2 = map(int, input().split())
#         E[temp_1 - 1][temp_2 - 1] = True
#         indegree[temp_2 - 1] += 1

#     Result_list = []
#     Queue = deque()
#     for index, in_num in enumerate(indegree) : 
#         if in_num == 0 : 
#             Queue.append(index)
#             Result_list.append(index)
#             indegree[index] = -1

#     while Queue : 
#         Current = Queue.popleft()
        
#         for i in range(N) : 
#             if E[Current][i] and indegree[i] != -1:
#                 E[Current][i] = False
#                 indegree[i] -= 1
#                 if E[Current][i] == 0 : 
#                     Queue.append(i)
#                     Result_list.append(i)
            
#     for value in Result_list : 
#         print(value + 1, end=' ')
#     print()

# if __name__ == '__main__' : 
#     N, M = map(int, input().split())

#     if N == 1 : print(1)
#     elif N == 2 : 
#         temp_1, temp_2 = map(int, input().split())
#         print(temp_1, temp_2)
#     else : 
#         solution(N, M)
