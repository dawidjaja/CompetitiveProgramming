def main():
    while True:
        try:
            (a, b) = map(int, input().split())
            print(abs(a - b))
        except EOFError:
            break

if __name__ == '__main__':
    main()
