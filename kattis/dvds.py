tc = int(input())
for tt in range(tc):
    k = int(input())
    arr = map(int, input().split())
    ne = 1
    for i in arr:
        if (i == ne):
            ne += 1
    print(k - ne + 1)
