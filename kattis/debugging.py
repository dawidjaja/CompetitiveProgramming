import math

def main():
    (n, r, p) = map(int, input().split()) 
    ans = math.inf

    if (n == 1):
        print(0)
        return

    for i in range(2, n + 1):
        ans = min(ans, (r + i * p) * math.log(n, i))
    print(int(ans))

if __name__ == '__main__':
    main()

