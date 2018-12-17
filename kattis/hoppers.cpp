#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int add = 1;
int color[500005];
int n, m, a, b, ans;
vector <int> v[500005];

void dfs(int cur, int prev, int col) {
    color[cur] = col;
    for (int i = 0; i < v[cur].size(); i++) {
        if (v[cur][i] != prev) {
            if (color[v[cur][i]] == -1) {
                dfs(v[cur][i], cur, col ^ 1);
            } else {
                if (color[v[cur][i]] == color[cur]) {
                    add = 0;
                } else {
                    continue;
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        color[i] = -1;
    }
    ans = -1;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            ans++;
            dfs(i, -1, 0);
        }
    }
    ans += add;
    printf("%d\n", ans);
    return 0;
}

