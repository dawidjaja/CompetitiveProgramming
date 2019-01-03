from fractions import Fraction

(n, q) = map(int, input().split())

thermo = []

for _ in range(n):
    (a, b) = map(int, input().split())
    thermo.append([a, b - a])

for _ in range(q):
    (x, y, v) = map(int, input().split())
    v -= thermo[x - 1][0]
    tmp = Fraction(v) / Fraction(thermo[x - 1][1])
    tmp *= Fraction(thermo[y - 1][1])
    tmp += Fraction(thermo[y - 1][0])
    if (tmp.denominator == 1):
        print(tmp, '/1', sep='')
    else:
        print(tmp)
