tc = int(input())

for _ in range(tc):
    input()
    n = int(input())
    ttl = 0
    for _ in range(n):
        ttl += int(input())
    if (ttl % n == 0):
        print("YES")
    else:
        print("NO")
