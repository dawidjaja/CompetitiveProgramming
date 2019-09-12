#include <bits/stdc++.h>

using namespace std;

int tc, n, m, l, vis[10005];
vector<int> v[10005];

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d", &n, &m, &l);
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            v[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
        }

        queue<int> q;
        int ctr = 0;
        for (int i = 0; i < l; i++) {
            int x;
            scanf("%d", &x);
            q.push(x);
            if (vis[x] == 0)
                ctr++;
            vis[x] = 1;
        }
        while (q.size()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < v[now].size(); i++) {
                if (vis[v[now][i]] == 0) {
                    vis[v[now][i]] = 1;
                    q.push(v[now][i]);
                    ctr++;
                }
            }
        }
        printf("%d\n", ctr);
    }
}
