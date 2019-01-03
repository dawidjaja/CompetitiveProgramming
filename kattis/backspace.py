s = input()

now = []
ptr = 0

for c in s:
    if (c == '<'):
        ptr -= 1
    else:
        if (len(now) <= ptr):
            now.append(c)
        else:
            now[ptr] = c
        ptr += 1

print("".join(now)[:ptr])
