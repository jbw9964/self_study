
# def print_score(Test_list) -> None : 

#     for i in range(len(Test_list)) : 
#         print(f"[{str(Test_list[i]['first']).zfill(2)}, {str(Test_list[i]['second']).zfill(2)}]", end=' ')
#     print()


import sys                      # 뭐 이런 개같은 경우가 있어???
input = sys.stdin.readline      # input 이 그냥 뭉탱이로 들어와서 import sys / input = sys.stdin.readline 해야만 정답으로 인정됨
Loop_num = int(input())         # 접근방식은 틀린거 없음

Result_list = []
for i in range(Loop_num) : 

    Apply_num = int(input())

    Rank_list = []
    for j in range(Apply_num) : 
        rank_1, rank_2 = map(int, input().split())
        
        Rank_list.append([rank_1, rank_2])

    Rank_list.sort()

    count = 1
    min_rank = Rank_list[0][1]

    for k in range(1, len(Rank_list)) : 
        Current_rank = Rank_list[k][1]

        if min_rank < Current_rank : 
            continue

        min_rank = Current_rank
        count += 1

    Result_list.append(count)

for i in Result_list : 
    print(i)




# Test_num = int(input())

# for i in range(Test_num) : 
#     Apply_num = int(input())

#     Test_list = []
#     for i in range(Apply_num) : 
#         temp = list(map(int, input().split()))

#         temp_dict = {'first':temp[0], 'second':temp[1], 'Valid':True}

#         Test_list.append(temp_dict)                      # Test_list = [ [score_1, score_2, Valid], ... ]

#     Test_list = sorted(Test_list, key=lambda x : x['first'])      # socre_1 기준 정렬
#     # print_score(Test_list)


#     count = 1
#     temp_min = Test_list[0]['second']
#     for i in range(1, len(Test_list)) : 

#         Current_second = Test_list[i]['second']

#         if Current_second > temp_min :
#             Test_list[i]['Valid'] = False
#             continue 

#         temp_min = Current_second
#         count += 1

#     print(count)









# Test_list = []
# for i in range(Apply_num) : 
#     temp = list(map(int, input().split()))

#     temp_dict = {'first':temp[0], 'second':temp[1], 'Valid':True}

#     Test_list.append(temp_dict)                      # Test_list = [ [score_1, score_2, Valid], ... ]

# Test_list = sorted(Test_list, key=lambda x : x['first'])      # socre_1 기준 정렬
# # print_score(Test_list)


# count = 1
# temp_min = Test_list[0]['second']
# for i in range(1, len(Test_list)) : 

#     Current_second = Test_list[i]['second']

#     if Current_second > temp_min :
#         Test_list[i]['Valid'] = False
#         continue 

#     temp_min = Current_second
#     count += 1

# print(count)



'''
<input>

2
5
3 2
1 4
4 1
2 3
5 5

1 4     o
2 3     o
3 2     o
4 1     o
5 5     x

<output> : 4

2
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1

1 4     o
2 5     x
3 6     x
4 2     o
5 7     x
6 1     o
7 3     x

<output> : 3

2
5
1 5
2 2
3 4
4 3
5 1

<output> : 5


2
5
3 2
1 4
4 1
2 3
5 5
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1


'''