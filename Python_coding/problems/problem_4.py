
from random import *

print("\n\n")

list = []
for i in range(1,21) :
    list.append(i)

shuffle(list)

print("Volunteers : ", list)

temp = sample(list, 1)
print(f"1st : {temp}")

list.remove(temp[0])

shuffle(list)

temp = sample(list, 3)
print("other : ", temp)

for i in range (0, 3) :
    list.remove(temp[i])

list.sort()
print("loosers : ", list)

print("\n\n")
