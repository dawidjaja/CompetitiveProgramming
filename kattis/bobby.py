import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom

tc = int(input())

for tt in range(tc):
    (r, s, x, y, w) = map(int, input().split())
    yes = (s - r + 1) / s
    no = 1 - yes
    probs = 0
    # print(yes, no)
    for i in range(x, y + 1):
        probs += (yes ** i) * (no ** (y - i)) * ncr(y, i)
        # print(x, y - x, probs)
    # print(probs)
    if (probs * w > 1):
        print('yes')
    else: 
        print('no')
