n = int(input())

words = {}

for i in range(n):
    s = input()
    if (s in words):
        print(words[s])
    else:
        print(0)
    for j in range(1, 1 + len(s)):
        tmp = s[:j]
        if (tmp in words):
            words[tmp] += 1
        else:
            words[tmp] = 1
