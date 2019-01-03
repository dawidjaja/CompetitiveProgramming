n = int(input())

dom = {}

ans = 0

for i in range(n):
    x = input()
    if (x in dom):
        dom[x] += 1
    else:
        dom[x] = 1

for i in range(n):
    x = input()
    if (x in dom and dom[x] >= 1):
        dom[x] -= 1
        ans += 1
print(ans)

