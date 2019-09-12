#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc, n, m, cs[200005];
    
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &m);
        long long ttlc = 0;
        long long ttle = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &cs[i]);
            ttlc += cs[i];
        }
        for (int i = 0; i < m; i++) {
            int e;
            scanf("%d", &e);
            ttle += e;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (1LL * cs[i] * n < ttlc && 1LL * cs[i] * m > ttle) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
