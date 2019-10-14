#include <bits/stdc++.h>

using namespace std;

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            vis[i] = {0, 0};
        }
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d%d", &a, &b, &c);
            v[a].push-back({b, c});
            v[b].push-back({a, c});
        }

        pq.clear();
        for (int i = 1; i <= n; i++) {
            int ss;
            scanf("%d", &ss);
            if (ss) {
                pq.push({0, -i});
            }
        }
        
    }
    return 0;
}
