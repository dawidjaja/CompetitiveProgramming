#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int a[4];
int b[4], tc, r, c;

bool in(pii cur, int i) {
    //printf("-- %d %d %d\n", cur.fs, cur.sc, i);
    if (0 <= cur.fs + a[i] && cur.fs + a[i] < r &&
        0 <= cur.sc + b[i] && cur.sc + b[i] < c) {
        //.printf("true\n");
        return true;
    }
    //printf("false\n");
    return false;
}

int main() {
    scanf("%d", &tc);
    a[0] = b[1] = 1;
    a[2] = b[3] = -1;
    for (int _ = 1; _ <= tc; _++) {
        queue <pii> q;
        int grid[255][255];
        scanf("%d%d", &r, &c);
        int adanol = 0;
        while (q.size()) q.pop();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%1d", &grid[i][j]);
                if (grid[i][j] == 0) adanol = 1;
                grid[i][j] -= 1;
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    //printf("cok %d %d\n", i, j);
                }
            }
        }
        if (!adanol) {
            printf("Case #%d: 0\n", _);
            continue;
        }
        pii last;
        while (q.size()) {
            pii cur = q.front();
            last = cur;
            //printf("-- %d %d --\n", cur.fs, cur.sc);
            q.pop();
            for (int i = 0; i < 4; i++) {
                if (in(cur, i) && grid[cur.fs + a[i]][cur.sc + b[i]] == -1) {
                    grid[cur.fs + a[i]][cur.sc + b[i]] = 
                        grid[cur.fs][cur.sc] + 1;
                    q.push({cur.fs + a[i], cur.sc + b[i]});
                }
            }
        }
        int tmp = 0;
        //printf("-- %d %d --\n", last.fs, last.sc);
        q.push(last);
        grid[last.fs][last.sc] = 0;
        while (q.size()) {
            pii cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                if (in(cur, i) && grid[cur.fs + a[i]][cur.sc + b[i]] > 
                        grid[cur.fs][cur.sc] + 1) {
                    grid[cur.fs + a[i]][cur.sc + b[i]] = 
                        grid[cur.fs][cur.sc] + 1;
                    q.push({cur.fs + a[i], cur.sc + b[i]});
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                tmp = max(tmp, grid[i][j]);
            }
        }
        printf("Case #%d: %d\n", _, tmp);
    }
    return 0;
}
