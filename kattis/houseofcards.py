'''
def valid(x):
    tmp = ((x - 1) * x) // 2 + x * (x + 1)
    if (tmp % 4 == 0):
        return True
    return False


for i in range(100):
    if (valid(i)):
        print(i)
'''

x = int(input())
tmp = x % 8
if (tmp == 0):
    print(x)
elif (tmp <= 5):
    print(x - tmp + 5)
else:
    print(x - tmp + 8)
