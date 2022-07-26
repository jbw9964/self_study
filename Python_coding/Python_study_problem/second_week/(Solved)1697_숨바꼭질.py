

# tq 메모리 초과 나는데 어떻게 해야될지 모르겠다.

from collections import deque

def BFS(Current, Target) -> int : 

    if Current == Target : return 0

    Queue = deque()
    Visit_dict = {}

    if Current : Queue.append(Current - 1)
    Queue.append(Current + 1)
    Queue.append(2 * Current)

    # Visit_list = [False for i in range(100003)]

    # if Current : Visit_list[Current - 1] = str(Current)
    # Visit_list[Current + 1] = str(Current)
    # Visit_list[2 * Current] = str(Current)
    # Visit_list[Current] = str(Current)

    Visit_dict[Current - 1] = [Current]
    Visit_dict[Current + 1] = [Current]
    Visit_dict[2 * Current] = [Current]
    Visit_dict[Current] = [Current]

    temp_count = 1
    while True : 
        value = Queue.popleft()
        temp_count += 1

        if value == Target : break

        # if value - 1 >= 0 and not Visit_list[value - 1] : 
        #     Queue.append(value - 1)
        #     Visit_list[value - 1] = str(value)
        # if value + 1 >= 0 and not Visit_list[value + 1] : 
        #     Queue.append(value + 1)
        #     Visit_list[value + 1] = str(value)
        # if 2 * value >= 0 and not Visit_list[2 * value] : 
        #     Queue.append(2 * value)
        #     Visit_list[2 * value] = str(value)

        if not (value - 1 in Visit_dict.keys()) : 
            Queue.append(value - 1)
            Visit_dict[value - 1] = [value]
        if not (value + 1 in Visit_dict.keys()) : 
            Queue.append(value + 1)
            Visit_dict[value + 1] = [value]
        if not (2 * value in Visit_dict.keys()) : 
            Queue.append(2 * value)
            Visit_dict[2 * value] = [value]


    Result_list = [Target]
    temp = Visit_dict[Target][0]
    while True : 
        if temp == Current : break
        Result_list.append(temp)
        temp = Visit_dict[temp][0]

    count = len(Result_list)
    Result_list.append(Current)
    Result_list.reverse()

    # Result_list = [Target]
    # temp = int(Visit_list[Target])
    # while True : 
    #     if temp == Current : break
    #     Result_list.append(temp)
    #     temp = int(Visit_list[Target])
    
    # count = len(Result_list)

    return count


Current, Target = map(int, input().split())

result = BFS(Current, Target)

try : 
    for i in result : 
        print(i, end=' ')
    print()
except : print(result)


'''
17
8.5
4.25    --> 0.75

1.5
3
6       --> 1

2
4       --> 1


'''
