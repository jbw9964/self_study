
Count = int(input())

D = [0, 1, 1]
for i in range(3, Count + 2) : 
    D.append(D[i - 1] + D[i - 2])
    
print(D[Count])