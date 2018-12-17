#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = 1000000000;
int vis[2][155];
int n, m, q, adj[2][155][155];

void dfs(int cur, int x) {
    vis[x][cur] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[x][cur][i] == 1 && vis[x][i] == 0) {
            dfs(i, x);
        }
    }
}

int main() {
    int cek = 0;
    while (scanf("%d%d%d", &n, &m, &q) && (n || m || q)) {
        int sp[155][155];
        int a, b, c;
        if (cek) {
            printf("\n");
        }
        cek = 1;
        for (int i = 0; i < n; i++) {
            vis[0][i] = vis[1][i] = 0;
            for (int j = 0; j < n; j++) {
                adj[i][j] = 0;
                sp[i][j] = (i == j) ? 0 : INF;
            }
        }

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            if (sp[a][b] == INF && c < sp[a][b])
                adj[0][a][b] = 1;
                adj[1][b][a] = 1;
            if (c < sp[a][b])
                sp[a][b] = c;
        }
        
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (sp[i][k] != INF && sp[k][j] != INF &&
                            sp[i][k] + sp[k][j] < sp[i][j])
                        sp[i][j] = sp[i][k] + sp[k][j];

        for (int i = 0; i < n; i++)
            if (sp[i][i] < 0)
                dfs(i, 0), dfs(i, 1);

        while (q--) {
            scanf("%d%d", &a, &b);
            if (sp[a][b] == INF) {
                printf("Impossible\n");
            } else {
                if (vis[a] || vis[b]) 
                    printf("-Infinity\n");
                else
                    printf("%d\n", sp[a][b]);
            }
        }
    }
    return 0;
}
