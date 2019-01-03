tc = int(input())

for i in range(tc):
    num = list(map(int, input().split()))
    arit = True
    for j in range(3, num[0] + 1):
        if (num[j] - num[j - 1] != num[j - 1] - num[j - 2]):
            arit = False
    if (arit):
        print('arithmetic')
    else:
        num[1:num[0] + 1] = sorted(num[1:num[0] + 1])
        permut = True
        for j in range(3, num[0] + 1):
            if (num[j] - num[j - 1] != num[j - 1] - num[j - 2]):
                arit = permut = False
        if (permut):
            print('permuted arithmetic')
        else:
            print('non-arithmetic')

