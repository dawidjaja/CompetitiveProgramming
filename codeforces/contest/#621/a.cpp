#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);

    while (tc--) {
        int n, d;
        scanf("%d%d", &n, &d);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (i == 0) {
                ans += x;
            } else {
                int tmp = min(d / i, x);
                d -= tmp * i;
                ans += tmp;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
