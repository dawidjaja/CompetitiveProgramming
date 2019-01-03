n = int(input())

tmp_h = map(int, input().split())

h = []

for i in tmp_h:
    h.append(i)

h.sort()

ans = n

for i in range(n):
    ans = min(ans, n - i - 1 + h[i])

print(ans)

