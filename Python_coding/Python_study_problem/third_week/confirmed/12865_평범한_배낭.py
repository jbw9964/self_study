

# 생각 방법 :
# Calc_table[i][j] = V --> i 번째 짐까지 생각하고 가방의 최대 무게가 j 라 하였을 때, 최대의 가치값
# Calc_table 은 (편의를 위해) [Num + 1] by [Max_weight + 1] 만큼 할당하고 모두 0으로 초기화 한다.
# 하나의 짐 에서(?) 가방의 최대 무게를 점점 크게 만들면서 생각한다.
# 구체적인 설명

# 처음에는 첫번째 짐만 넣는다 생각한다. 그리고 이 때, 가방의 최대 허용 무게가 k (1 ~ Max_weight 까지 차례차례 확인할 에정) 라 하자.
# 짐의 무게를 W1, 가치를 V1 라 하였을 때, 만약 k < W1 라면 짐을 넣을 수 없다. 
# 때문에 이때의 Calc_table[1][k] = Calc_table[0][k] (= 0) 로 초기화 한다.
# 하지만 k >= W1 라면 넣을 수 있으므로 Calc_table[1][k] = V1 로 만든다.
# 이를 k : range(1, Max_weight + 1) 까지 모두 확인한다.

# 이제 두번째 짐을 위 상태 (Calc_table) 에 넣는다 생각하자.
# 이 또한 두번재 짐의 무게를 W2, 가치를 V2 라 하자. 
# 앞과 마찬가지로 k < W2 라면 두번째 짐을 넣을 수 없다. 때문에 Calc_table[2][k] = Calc_table[2 - 1][k] 값으로 만든다.
# 이 행위의 의미는 '지금 확인하는 짐은 어차피 가방에 넣을 수 없으니, 이전에 넣었던 짐의 경우가 최고 가치의 경우' 이므로 이 값으로 그대로 만든다는 의미이다.

# 하지만 k >= W2 라면 지금 두번째 짐을 넣는것이 이득인지, 아닌지 확인해야 한다.
# 위 두 경우를 자세히 생각해보자. 현재 가방의 최대 용량은 k 라 하였다.
# 두번째 짐을 넣지 않는 경우 == 첫번째 짐을 넣은 경우가 최고 가치  //  두번째 짐을 넣는 경우 == 이 경우가 최고 가치 (첫번째랑 같이 들어갈수도, 아닐수도 있음) 이다.

# <두번째 짐을 넣는 경우의 최고 가치>
# 그런데 우리는 Calc_table[n][k] 의 정의를 '가방의 최대 용량이 k이며 n 번째 짐까지 생각했을 때, 계산되는 최고 가치' 라 하였다.
# 그렇다면 Calc_table[2 - 1][k - W2] 는 무엇을 의미할까. '가방의 최대 용량이 k - W2 이며 1 번째 짐까지 생각했을 때, 계산되는 최고 가치' 일 것이다.
# 그럼 가방의 최대용량이 k 이고 2 번째 짐까지 생각하면, 즉 Calc_table[2][k] 는 ( Calc_table[2 - 1][k - W2] + V2 ) 라 생각할 수 있다.
# 이 경우에 첫번째 짐이 넣어진 상태에서 생각하든, 안 하든 상관이 없다. 어차피 Calc_table[1][k] 는 각 경우에 따라 정확히 초기화 되어있고 어찌 되었든 계산은 똑같기 때문이다.

# <첫번째 짐을 넣는 경우가 최고 가치>
# 이 경우는 다시말하면 두번째 짐을 넣지 않는 경우이다. 그런데 생각해보면 이 경우의 최고 가치는 Calc_table[1][k], 즉 두번째 짐을 포함해 생각하기
# 이전의 값과 동일한 것을 알 수 있다. 어차피 두번째 짐을 넣지 않기 때문이다.
# 때문에 결국 Calc_table[2][k] = Calc_table[1][k] 가 된다.

# 이제 위 두 경우중, 어느것이 더 이득인지 따지면 된다.
# 결국 아래처럼 표현하면 둘 중 이득인 경우에 따라 최고 가치값이 초기화 된다.
# Calc_table[2][k] = max( Calc_table[1][k], Calc_table[2 - 1][k - W2] + V2 )

# 이렇게 모든 짐들에 대해, 가방의 가능한 모든 허용용량에 대해 생각하면, 
# Calc_table[Num][Max_weight] 는 '가방의 최대 용량이 Max_weight' 이며 Num 번째 짐까지 생각했을 때 계산되는 최고 가치가 된다.

import sys
input = sys.stdin.readline

Num, Max_weight = map(int, input().split())

List = [[0, 0]]
for i in range(Num) : 
    temp_1, temp_2 = map(int, input().split())
    List.append([temp_1, temp_2])

Calc_table = [[0 for i in range(Max_weight + 1)] for i in range(len(List) + 1)]

for count in range(1, Num + 1) : 
    for K in range(1, Max_weight + 1) :  
        W = List[count][0]
        V = List[count][1]

        if K < W : 
            Calc_table[count][K] = Calc_table[count - 1][K]
        else : 
            Calc_table[count][K] = max(Calc_table[count - 1][K], Calc_table[count - 1][K - W] + V)


print(Calc_table[Num][Max_weight])


# 진짜 DP 로 풀기

# import sys
# input = sys.stdin.readline

# N, K = map(int, input().split())  # N(물품 수), K(가능한 최대 무게) 입력받기

# bag = [0] * (K + 1)
# for _ in range(N):
#     W, V = map(int, input().split())  # W(무게), V(가치) 입력받기
#     for i in range(K, W - 1, -1):
#         bag[i] = max(bag[i], bag[i - W] + V)  # 새로 들어온 물건으로 최대 가치 수정

# # 결과 출력
# print(bag[-1])



'''
<input>
5 10
1 1
2 2
3 3
4 4
5 5

<output> : 10

6 7
6 13
4 8
3 6
5 12    --> o
3 7
2 6     --> o

6 7
6 13
4 8
3 6
5 12
3 7
2 6

<output> : 18

'''


