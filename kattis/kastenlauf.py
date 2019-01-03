from math import *
from queue import Queue

tc = int(input())

for tt in range(tc):
    n = int(input())
    x = []
    y = []
    for i in range(n + 2):
        (a, b) = map(int, input().split())
        x.append(a)
        y.append(b)
    
    vis = []
    for i in range(n + 2):
        vis.append(0)

    def dist(a, b):
        return abs(x[a] - x[b]) + abs(y[a] - y[b])

    q = Queue()
    q.put(0)
    vis[0] = 1;
    while (not q.empty()):
        now = q.get()
        for i in range(n + 2):
            if (vis[i] == 0):
                if (dist(i, now) <= 1000):
                    q.put(i)
                    vis[i] = 1

    if (vis[n + 1] == 1):
        print('happy')
    else:
        print('sad')


