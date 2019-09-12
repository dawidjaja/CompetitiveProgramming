def bnyk(x):
	if(x in freq.keys()):
		return freq[x]
	else:
		return 0;

freq = {

}


n = int(input())
list = input().split()
ans = 0
ttl = 0
for i in range(n):
	x = int(list[i])
	a = bnyk(x - 1)
	b = bnyk(x)
	c = bnyk(x + 1)
	ans += x * (i - a - b - c) - (ttl - (x - 1) * a - x * b - (x + 1) * c)
	ttl += x
	if(x in freq.keys()):
		freq[x] += 1
	else:
		freq[x] = 1
print("%d\n" % ans)