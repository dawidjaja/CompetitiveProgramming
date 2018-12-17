#include <algorithm>
#include <cstdio>

using namespace std;

int a[4] = {1, 0, -1, 0};
int b[4] = {0, 1, 0, -1};
int vis[1005][1005], r, c, wmap[1005][1005], q, binId, decId;

bool out(int y, int x) {
    if (1 <= y && y <= r && 1 <= x && x <= c)
        return false;
    return true;
}

void dfs(int y, int x, int id) {
    //printf("%d %d %d\n", y, x, id);
    if (out(y, x))
        return;
    //printf("%d %d %d\n", y, x, id);
    vis[y][x] = id;
    for (int i = 0; i < 4; i++)
        if (wmap[y][x] == wmap[y + a[i]][x + b[i]] &&
                vis[y + a[i]][x + b[i]] == 0)
            dfs(y + a[i], x + b[i], id);
    return;
}

int main() {
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            scanf("%1d", &wmap[i][j]);
    binId = 1;
    decId = 2;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (vis[i][j] == 0) {
                if (wmap[i][j] == 0) {
                    //binary
                    dfs(i, j, binId);
                    binId += 2;
                } else {
                    dfs(i, j, decId);
                    decId += 2;
                }
            }
        }
    }
    scanf("%d", &q);
    while (q--) {
        int y1, x1, y2, x2;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
        if (vis[y1][x1] == vis[y2][x2]) {
            if (vis[y1][x1] & 1) {
                printf("binary\n");
            } else {
                printf("decimal\n");
            }
        } else {
            printf("neither\n");
        }
    }
    return 0;
}
