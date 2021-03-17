#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

int n, m, vis[1005][1005];
char loc[1005][1005];
queue <ppi> q;
map<char,int> freq;

pii dir[8] = {
    {0, 1},
    {-1, 1},
    {-1, 0},
    {-1, -1},
    {0, -1},
    {1, -1},
    {1, 0},
    {1, 1}
};

bool inside(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= m) return false;
    return true;
}

bool can(pii dd, int y, int x, int d) {
    if (!inside(y + dd.fs, x + dd.sc)) return false;

    if (vis[y + dd.fs][x + dd.sc] == -2) return true;
    if (vis[y + dd.fs][x + dd.sc] > d + 1) return true;

    return false;
}

void bfs(int y, int x, int d) {
    queue <pii> tq;
    tq.push({y, x});
    vis[y][x] = d;
    q.push({{y, x}, d});

    while (tq.size()) {
        int ty = tq.front().fs;
        int tx = tq.front().sc;
        tq.pop();
        //printf("-- %d %d --\n", ty, tx);
        for (pii dd: dir) {
            if (inside(ty + dd.fs, tx + dd.sc) &&
                    loc[ty][tx] == loc[ty + dd.fs][tx + dd.sc] &&
                    vis[ty + dd.fs][tx + dd.sc] == -2) {
                vis[ty + dd.fs][tx + dd.sc] = d;
                tq.push({ty + dd.fs, tx + dd.sc});
                q.push({{ty + dd.fs, tx + dd.sc}, d});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            loc[i][j] = getchar();
            if (loc[i][j] == 'W') {
                vis[i][j] = -1;
                q.push({{i, j}, -1});
            } else {
                vis[i][j] = -2;
            }
        }
    }

    while (q.size()) {
        int x, y, d;
        y = q.front().fs.fs;
        x = q.front().fs.sc;
        d = q.front().sc;
        q.pop();

        for (pii dd: dir) {
            if (can(dd, y, x, d)) {
                bfs(y + dd.fs, x + dd.sc, d + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (loc[i][j] != 'W') {
                if (!freq.count(loc[i][j])) {
                    freq[loc[i][j]] = vis[i][j];
                } else {
                    freq[loc[i][j]] = min(freq[loc[i][j]], vis[i][j]);
                }
            }
        }
    }

    for (auto &[c, num]: freq) {
        printf("%c %d\n", c, num);
    }
    
    return 0;
}
