from itertools import product
from fractions import Fraction

def main():
    (n, m) = map(int, input().split())

    f = map(int, input().split())
    b = map(int, input().split())

    tmp = product(f, b)

    tmp = map(lambda x: (Fraction(x[0], x[1]), x[0], x[1]), tmp)
    tmp = sorted(tmp)
                
    for (i, j, k) in tmp:
        print("(%d,%d)" % (j, k))

if __name__ == "__main__":
    main()
