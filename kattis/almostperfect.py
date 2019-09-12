from math import *
def main():
    while (True):
        try:
            x = int(input())
            cap = floor(sqrt(x))
            ans = 0
            for i in range(1, cap + 1):
                if (x % i == 0):
                    ans += i
                    if (x // i != i and i != 1):
                        ans += x // i
            if (ans == x):
                print('{} perfect'.format(x))
            elif (abs(ans - x) <= 2):
                print('{} almost perfect'.format(x))
            else:
                print('{} not perfect'.format(x))
        except EOFError:
            break

if __name__ == '__main__':
    main()
