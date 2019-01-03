def main():
    while(True):
        n = int(input())
        if (n == 0):
            return
        x = []
        y = []
        for i in range(n):
            a, b = map(int, input().split())
            x.append(a)
            y.append(b)
        ttl = 0
        for i in range(n):
            ttl += (y[(i + 1) % n] * x[i]) - (x[(i + 1) % n] * y[i])
        if (ttl < 0):
            print("CW {}".format(-ttl / 2))
        else:
            print("CCW {}".format(ttl / 2))

if __name__ == '__main__':
    main()
