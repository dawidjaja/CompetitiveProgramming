def main():
    n = int(input())
    s = set()
    for i in range(n):
        inp = input()
        if len(inp) > 6:
            continue
        s.add(int(inp))

    for i in range(1000002):
        if i not in s:
            print(i)
            return

if __name__ == "__main__":
    main()
