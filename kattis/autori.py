import functools
s = input().split('-')
s[0] = s[0][0]

print(functools.reduce(lambda a,b : a + b[0], s))
