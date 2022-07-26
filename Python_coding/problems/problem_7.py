
import tempfile
import this
from turtle import end_fill


print('\n\n')


num = input("how many reports do you need? : ")
num = int(num)

for i in range(1,num + 1) :
    temp_file = open(f"{i}주차.txt", 'w', encoding='utf8')

    temp_file.write(f"- {i}주차 주간보고 - \n")
    temp_file.write('부서 : \n')
    temp_file.write('이름 : \n')
    temp_file.write('업무 요약 : \n')

    temp_file.close()

# or you can do like this

# for i in range(1, num + 1) : 
#     with open(f'{i}주차.txt', 'w', encoding='utf8') as tempfile :

#         tempfile.write(f"- {i}주차 주간보고 - \n")
#         tempfile.write('부서 : \n')
#         tempfile.write('이름 : \n')
#         tempfile.write('업무 요약 : \n')

print('\n\n')