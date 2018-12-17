from math import log10

def main():
    x = input()

    if len(x) < 25:
        logx = log10(int(x))
    else:
        logx = log10(int(x[:5]) / 10**5) + len(x) - 1

    logc = 0

    for i in range(1, 1000000):
        logc += log10(i)
        if logc - logx > -1e-2:
            print(i)
            return

if __name__ == '__main__':
    main()
