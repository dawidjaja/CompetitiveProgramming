n = int(input())

s = input()

last = -1
now = 1
for i in range(n - 1):
    if (s[i] == 'R'):
        for j in range(i, last, -1):
            print(j + 1)
        last = i

for j in range(n, last + 1, -1):
    print(j)

