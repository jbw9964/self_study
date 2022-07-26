

print('\n\n')

from random import *

time  = []

for i in range(0,50) :
    time.append(randint(5,50))
    print(f"{i + 1}th customer : {time[i]} min")

time.sort()

result = []
count = 0

for i in time :
    if (5 <= i <= 15) :
        result.append(i)
        count += 1
    elif (i > 15) :
        break

print(f"\ntoday, you faced {count} customers")

for i in range(0,count) :
    print(f"{i + 1}th customer : {result[i]}")

print('\n\n')
