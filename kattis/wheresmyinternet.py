n, m = map(int, input().split())

p = []

def par(x):
    if (p[x] == x):
        return x
    else:
        p[x] = par(p[x])
        return p[x]

for i in range(n + 1):
    p.append(i)

for i in range(m):
    a, b = map(int, input().split())
    p[par(a)] = par(b)

connected = True
for i in range(1, n + 1):
    if (par(1) != par(i)):
        connected = False
        print(i)

if (connected):
    print("Connected")
