from math import floor
def main():
    l = 1
    r = 1000
    while (l < r):
        mid = floor((l + r) / 2)
        print(mid)
        fb = input()
        if (fb == 'lower'):
            r = mid - 1
        elif (fb == 'higher'):
            l = mid + 1
        else:
            return
    print(l)

if __name__ == '__main__':
    main()
