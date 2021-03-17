#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, loc[2005][2005], vis[2005][2005], ans;
queue<pii> q;

pii dirs[4] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

bool inside(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= n) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &loc[i][j]);
            if (loc[i][j] == 3) {
                vis[i][j] = 0;
                q.push({i, j});
            } else {
                vis[i][j] = -1;
            }
        }
    }

    while (q.size()) {
        int y, x;
        y = q.front().fs;
        x = q.front().sc;
        q.pop();
        if (loc[y][x] == 1) {
            ans = vis[y][x];
        }

        for (pii dir: dirs) {
            int ny, nx;
            ny = y + dir.fs;
            nx = x + dir.sc;
            if (inside(ny, nx) && vis[ny][nx] == -1) {
                vis[ny][nx] = vis[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
