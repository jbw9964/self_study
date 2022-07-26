print("\n\n")

Coin_num, Target = input().split()

Coin_num = int(Coin_num)
Target = int(Target)

Coin_List = []

for i in range(0,Coin_num) :
    temp = int(input())
    Coin_List.append(temp)

Coin_List.sort()
Coin_List.reverse()

index = 0
count = 0

while True : 

    if not Target : break
    if Target < Coin_List[index] : 
        index += 1
        continue

    Quotient = Target // Coin_List[index]

    if Quotient >= 1 :
        temp = Quotient * Coin_List[index]
        Target -= temp
        count += Quotient
        index += 1
    elif Quotient < 1 : break

print("Result : ", count)

print("\n\n")



'''
<input>

6 2560
5000
1000
500
50
10
5

<output> : 5

<input>

10 4790
1
5
10
50
100
500
1000
5000
10000
50000

<output> : 12
'''
















