s = input()

mod = {
    'R':'S',
    'B':'K',
    'L':'H'
}

def cek(x):
    if (x + 2 >= len(s)):
        return False
    return s[x] != s[x + 1] and s[x + 1] != s[x + 2] and s[x] != s[x + 2]

i = 0
while i < len(s):
    if (cek(i)):
        print('C', end='')
        i += 2
    else:
        print(mod[s[i]], end='')
    i += 1
print()
