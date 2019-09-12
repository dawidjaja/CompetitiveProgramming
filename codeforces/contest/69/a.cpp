#include <bits/stdc++.h>

using namespace std;

int tc, n, a[100005], k;

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int ans = min(a[n - 2] - 1, n - 2);
        printf("%d\n", ans);
    }
    return 0;
}

