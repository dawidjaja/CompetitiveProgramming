from math import e, log10, pi, floor

def main():
    while True:
        try:
            n = int(input())
            if (n <= 1):
                print(1)
                continue
            print(floor(n * log10(n / e) + log10(2 * pi * n) / 2) + 1)
        except EOFError:
            return

if __name__ == '__main__':
    main()
