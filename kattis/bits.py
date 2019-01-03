n = int(input())

def bitsoncount(x):
    return bin(x).count('1')

for i in range(n):
    x = input()
    cur = 0
    ans = 0
    for c in x:
        cur *= 10
        cur += int(c)
        ans = max(ans, bitsoncount(cur))
    print(ans)
