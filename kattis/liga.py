n = int(input())

maxVal = [100, 100, 100, 100, 300]

cur = []
tmp = [0] * 5

def check():
    if (tmp[0] != tmp[1] + tmp[2] + tmp[3]):
        return False
    if (tmp[1] * 3 + tmp[2] != tmp[4]):
        return False
    return True

def findAns(x):
    if (x == 5):
        if check():
            return True
        else:
            return False
    if (cur[x] == -1):
        for i in range(maxVal[x] + 1):
            tmp[x] = i
            if (findAns(x + 1)):
                return True
    else:
        tmp[x] = cur[x]
        return findAns(x + 1)


for _ in range(n):
    inp = input().split()
    cur = []
    cnt = 0
    for i in inp:
        if (i == '?'):
            cur.append(-1)
        else:
            cur.append(int(i))

    for i in range(4):
        if cur[i] == -1:
            cnt += 1

    if (cnt == 1):
        if (cur[0] == -1):
            cur[0] = cur[1] + cur[2] + cur[3]
        elif (cur[1] == -1):
            cur[1] = cur[0] - cur[2] - cur[3]
        elif (cur[2] == -1):
            cur[2] = cur[0] - cur[1] - cur[3]
        elif (cur[3] == -1):
            cur[3] = cur[0] - cur[1] - cur[2]

    if (findAns(0)):
        for x in range(len(tmp)): 
            if (x == len(tmp) - 1):
                print(tmp[x])
            else:
                print(tmp[x], end=" ")
    
