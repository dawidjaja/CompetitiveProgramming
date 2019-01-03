n = int(input())

balon = map(int, input().split())
vis = {}

ans = 0
for i in balon:
    if ((not ((i + 1) in vis)) or vis[i + 1] == 0):
        ans += 1
    else:
        vis[i + 1] -= 1
    if (i in vis):
        vis[i] += 1
    else:
        vis[i] = 1
print(ans)
