a = input()
b = input()

dpn = 0
for i in range(len(b)):
    if (i >= len(a)):
        break
    if (a[i] == b[i]):
        dpn += 1
    else:
        break

blkg = 0
for i in range(1, len(b) + 1):
    if (i > len(a)):
        break
    if (a[-i] == b[-i]):
        blkg += 1
    else:
        break

if (len(a) < len(b) and dpn == len(a) and blkg == len(a)):
    print(len(b) - len(a))
else:
    print(max(len(b) - dpn - blkg, 0))
