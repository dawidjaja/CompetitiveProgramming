from math import *

(a, b, c) = map(int, input().split())

group = b // c

print(ceil((a - 1) / group))

