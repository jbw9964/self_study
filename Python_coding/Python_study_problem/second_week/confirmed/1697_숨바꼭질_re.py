



import time

from collections import deque

Pos, Target = map(int, input().split())

Visit_table = [0] * ((10**5) + 100)

start = time.time()

Queue = deque()
Queue.append(Pos)

while Queue : 
    value = Queue.popleft()

    if value == Target : 
        print(Visit_table[value])
        del Queue
        del Visit_table
        break

    for temp in (value - 1, value + 1, 2 * value) : 
        if 0 <= temp <= 10**5 and not Visit_table[temp] : 
            Visit_table[temp] = Visit_table[value] + 1
            Queue.append(temp)


end = time.time()

print(end - start, 'sec')
