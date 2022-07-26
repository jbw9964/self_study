
Female, Male, Target = input().split()

Female = int(Female)
Male = int(Male)
Target = int(Target)

temp = min(Female // 2, Male)

Remain_female = Female - temp * 2
Remain_male = Male - temp
Remain_total = Remain_female + Remain_male

## Remain_male 은 항상 정수여야 하는데 아닌 경우가 생김

if Target <= Remain_total : Result = temp
else : 

    while Target > Remain_total :       # Target >= Remain_total 해서 틀렸었음.
        Remain_total += 3
        temp -= 1

    Result = temp

print(int(temp))



# count = 0
# while True : 
#     Female -= 1
#     Male -= 1

#     if Female < 0 or Male < 0 : break
#     if 2 * Female + Male <= Target : break

#     count += 1

# print(count)



