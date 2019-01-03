from math import sqrt

x = int(input())
k = 0
n = 2
tmp = sqrt(x)
while (x != 1 and n <= tmp):
    while (x % n == 0):
        k += 1
        x /= n
    n += 1
if (x != 1):
    k += 1
print(k)
