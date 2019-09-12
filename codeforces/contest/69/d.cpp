#include <bits/stdc++.h>

using namespace std;

long long n, m, k, a[300005], dp[300005][10];

long long f(long long idx, long long offset)  {
    if (dp[idx][offset] != -1) {
        return dp[idx][offset];
    }

    if (idx >= n) return 0;
    long long &ans = dp[idx][offset];
    ans = 0LL;
    long long tmp = 0;
    if (offset == 0) {
        tmp -= k;
    }
    offset++;
    offset = offset % m;
    ans = max(ans, f(idx + 1, offset) + a[idx] + tmp);
    return ans;
}

int main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    for (long long i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
        scanf("%lld", &a[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, f(i, 0));
    }
    printf("%lld\n", ans);

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf ("%d %d -- %lld\n", i, j, dp[i][j]);
        }
    }
    */
    return 0;
}
