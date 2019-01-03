#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000007;
int tc, x, n, coin[105], ttl[10005];

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &x);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &coin[i]);
        }
        ttl[0] = 0;
        for (int i = 1; i <= 10000; i++) {
            ttl[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 10000; j >= 0; j--) {
                if (j - coin[i] >= 0 && ttl[j - coin[i]] != -1) {
                    ttl[j] = min(ttl[j - coin[i]] + 1, 
                            (ttl[j] == -1 ? INF : ttl[j]));
                }
            }
        }
        for (int i = x; i <= 10000; i++) {
            if (ttl[i] != -1) {
                printf("%d %d\n", i, ttl[i]);
                break;
            }
        }
    }
    return 0;
}
