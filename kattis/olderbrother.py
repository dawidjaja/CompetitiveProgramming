from math import *
x = int(input())
if (x == 1):
    print('no')
    exit()

first = True
for i in range(2, floor(sqrt(x)) + 1):
    if (x % i == 0):
        tmp = 0
        while (x % i == 0):
            tmp += 1
            x /= i
        if (first):
            ans = tmp
            first = False
        else:
            print('no')
            exit()
if (x == 1 or first):
    print('yes')
else:
    print('no')
