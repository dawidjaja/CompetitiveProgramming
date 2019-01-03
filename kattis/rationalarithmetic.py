from fractions import Fraction

tc = int(input())

for tt in range(tc):
    (a, b, c, d, e) = input().split()
    (a, b, d, e) = map(int, [a, b, d, e])
    
    x = Fraction(a, b)
    y = Fraction(d, e)
    if (c == '+'):
        z = x + y
    elif (c == '-'):
        z = x - y
    elif (c == '*'):
        z = x * y
    elif (c == '/'):
        z = x / y

    aa = z.numerator
    bb = z.denominator

    print(aa, '/', bb)

