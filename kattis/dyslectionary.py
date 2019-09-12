def reversestring(a, b):
    return a[::-1] - b[::-1]

def main():
    r = 0
    s = []
    while (True):
        try:
            x = input()
            if (x == ''):
                s.sort()
                for i in s:
                    print(i[::-1].rjust(r))
                s = []
                r = 0
            r = max(r, len(x))
            s.append(x[::-1])
        except (EOFError):
            s.sort()
            for i in s:
                print(i.rjust(r))


if __name__ == '__main__':
    main()
