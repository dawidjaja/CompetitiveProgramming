from math import *
x = int(input())

cap = floor(sqrt(x))
ptr = 0
first = True
fac = []
for i in range(1, cap + 1):
    if (x % i == 0):
        if (not first):
            print(' ', end='')
        print(i - 1, end='')
        first = False
        if (x // i != i):
            fac.append(x // i)
            ptr += 1

for i in range(ptr - 1, -1, -1):
    print(' ', end='')
    print(fac[i] - 1, end='')

print()
