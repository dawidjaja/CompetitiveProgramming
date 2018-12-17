import sys
input_file = sys.stdin

n = int(input_file.readline())
ls = [False] * 365
for i in range(n):
    [a,  b] = list(int(x) for x in input_file.readline().split())
    for j in range(a-1, b):
        ls[j] = True
print(ls.count(True))
    
