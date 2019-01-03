from math import floor
n = int(input())

arr = []
for i in range(32005):
    arr.append(1)

arr[1] = 0

prime = set()
for i in range(2, 32005):
    if (arr[i] == 1): 
        prime.add(i)
        for j in range(2 * i, 32005, i):
            arr[j] = 0

for i in range(n):
    x = int(input())
    rep = 0
    ans = set()
    for j in range(2, floor(x / 2) + 1):
        if (j in prime and x - j in prime):
            ans.add(j)
    print("{} has {} representation(s)".format(x, len(ans)))
    s = sorted(ans)
    for j in s:
        print("{}+{}".format(j, x - j))
    print()
