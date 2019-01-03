from math import *

def main():
    while True:
        try:
            s = input()
            letters = {}
            probs = factorial(len(s))
            for c in s:
                # print(probs)
                if c in letters:
                    letters[c] += 1
                else:
                    letters[c] = 1
                probs //= int(letters[c])
                probs = round(probs)
            print(probs)
        except EOFError:
            break

if __name__ == '__main__':
    main()
