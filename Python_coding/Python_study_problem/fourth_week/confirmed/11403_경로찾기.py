
import sys
input = sys.stdin.readline
from collections import deque

def solution(S : int, E : list) -> list : 

    global N
    Visit_table = [False for i in range(N)]

    Queue = deque()
    Queue.append(S)

    while Queue : 
        Current = Queue.popleft()
        
        for adjacent in range(N) : 
            if E[Current][adjacent] != 1 or Visit_table[adjacent] : continue

            Queue.append(adjacent)
            Visit_table[adjacent] = True
    
    Result_list = []
    for value in Visit_table : 
        if value == True : 
            Result_list.append(1)
        else : Result_list.append(0)

    return Result_list

if __name__ == '__main__' : 
    
    N = int(input())

    E = []
    for i in range(N) : 
        E.append(list(map(int, input().split())))

    Result_list = []
    for i in range(N) : 
        Result_list.append(solution(i, E))
    
    for i in range(N) : 
        for j in range(N) : 
            print(Result_list[i][j], end=' ')
        print()
