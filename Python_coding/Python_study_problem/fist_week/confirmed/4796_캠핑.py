
import sys
input = sys.stdin.readline

Result_list = []
count = 1
while True : 

    Use, Term, Vac = map(int, input().split())

    if not Use and not Term and not Vac : break

    quotient = Vac // Term
    remain = Vac % Term
    Total_use = quotient * Use + min(Use, remain)

    Result_list.append(Total_use)

for i in range(len(Result_list)) : 

    print(f"Case {i + 1}: {Result_list[i]}")        # 진짜 어이가 없네 (Case 1:) 이 아니라 (Case 1 : ) 이라 쳐서 틀림
                                                    # 이딴게 채점인가??



