n = int(input())

asu = map(int, input().split())

arr = []
for i in asu:
    arr.append(i)
# print(arr)
arr.sort()

cnt = len(arr)
ans = 0

for i in arr:
    ans = max(ans, cnt + i)
    cnt -= 1

print(ans + 1)
