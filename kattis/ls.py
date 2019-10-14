import re

import sys
s = input()

n = int(input())

s = s.replace(".", "\\.")
s = s.replace("*", ".*")
s += '\n'

x = re.compile(s)

for line in sys.stdin:
    if (x.match(line) is not None):
        print(line, end='')

