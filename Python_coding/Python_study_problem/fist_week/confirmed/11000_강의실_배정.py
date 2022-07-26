
# import heapq
# from sys import stdin

# n=int(stdin.readline())
# heap=[]

# for i in range(n):
#     start, end=map(int, stdin.readline().split())
#     heap.append([start, end])
# heap.sort()

# room = []
# heapq.heappush(room, heap[0][1]) # 첫 강의 종료시간

# for i in range(1, n):
#     if heap[i][0]<room[0]: # 지금 강의 종료시간보다 다음 강의시작이 빠를때
#         heapq.heappush(room, heap[i][1])
#     else: # 지금 강의 끝나고 이어서 강의하면 됨
#         heapq.heappop(room)
#         heapq.heappush(room, heap[i][1])

# print(len(room))


import heapq
import sys

input = sys.stdin.readline

Conf_num = int(input())
Conf_list = []

for i in range(Conf_num) : 
    start, end = map(int, input().split())
    Conf_list.append([start, end])

Conf_list.sort()

Heap_list = []
heapq.heappush(Heap_list, Conf_list[0][1])

for i in range(1, Conf_num) : 

    if Heap_list[0] <= Conf_list[i][0] : 
        heapq.heappushpop(Heap_list, Conf_list[i][1])
        continue
        
    heapq.heappush(Heap_list, Conf_list[i][1])

print(len(Heap_list))


