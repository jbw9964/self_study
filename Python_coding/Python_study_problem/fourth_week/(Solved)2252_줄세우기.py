
# 그냥 봤을 때 dynamic 하게 풀 수 있을 것 같아서 그냥 만들었는데, 그러면 반례경우가 생김
# 각 수가 M 에서 입력되는지 확인하고 Result_list 의 어디에 저장되는지 확인하는 dynamic list 를 만들었음.
# 만약 두 수 모두 저장된 적이 없으면 Result_list 에 append, 둘 다 저장되었으면 어디 저장되있는지 확인하고 순서에 맞춰 바꿈
# 그리고 둘 중 하나만 저장되었으면 그에 맞게 순서만 바꾸는 식으로 했었음.

# 이러면 1 3 / 2 4 / 4 1 인 경우가 반례임. 그냥 index 순서에 맞게 두 수만 바꾸면 이전에 순서를 맞춰준 것에 따라 모두 바꿔야 되는데,
# dynamic 으로 이 점 까지 만들기에는 내 능지가 딸림.

# 찾아보니까 Topological sort 라고 함. 이 방법 외에 다른 방법은 잘 모르겠음.

import sys
input = sys.stdin.readline

N, M = map(int, input().split())

if N == 1 : print(1)
elif N == 2 and M == 1 : 
    first, second = map(int, input().split())
    print(first, second)
else : 

    Result_list = [0]
    D_index = [-1 for i in range(N + 1)]
    D_index[0] = -2

    for i in range(M) : 
        first, second = map(int, input().split())

        if D_index[first] == -1 and D_index[second] == - 1: 
            Result_list.append(first)
            D_index[first] = len(Result_list) - 1
            Result_list.append(second)
            D_index[second] = len(Result_list) - 1


        elif D_index[first] != -1 and D_index[second] != -1: 
            temp_1  = D_index[first]
            temp_2 = D_index[second]
            
            if temp_2 < temp_1 : 
                Result_list[temp_2] = first
                Result_list[temp_1] = second
                D_index[first] = temp_2
                D_index[second] = temp_1
        

        else : 
            if D_index[first] != - 1 :               # first 가 Result_list 에 들어있을 때
                Result_list.append(second)
                D_index[second] = len(Result_list) - 1
            
            else :                                  # second 가 Result_list 에 들어있을 때
                Result_list.append(first)
                D_index[first] = D_index[second]
                D_index[second] = len(Result_list) - 1
                Result_list[D_index[first]] = first
                Result_list[D_index[second]] = second

    for value, index in enumerate(D_index) : 
        if index != -1 : continue
        Result_list.append(value)

    for value in Result_list : 
        if value == 0 : continue
        print(value, end=' ')
    print()



'''
3 3
1 2
1 3
2 3

1 2 3


4 3
1 3
2 4
4 1

1 3 2 4
2 4 1 3


'''