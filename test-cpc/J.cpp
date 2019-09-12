#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
long long a[2005], b[2005], dp[2005][2005][2], n, m;

long long check_sisa(int idx, int udah) {
    int check = udah;
    for (int i = idx; i < n; i++) {
        if (udah && a[i] > b[m]) {
            check = 0;
            return 0;
        }
        if (!udah && a[i] == b[m]) {
            check = 1;
        }
    }

    return check;
}

long long f(int idx, int maks, int udah) {
    if (idx == n && maks == m) return 1;
    if (idx == n) return 0;
    if (maks == m) return check_sisa(idx, udah);

    long long &ret = dp[idx][maks][udah];
    if (ret != -1) return ret;

    ret = 0;

    if (a[idx] > b[maks]) return 0;

    if (a[idx] == b[maks] || udah) {
        ret += f(idx + 1, maks + 1, 0);
        ret += f(idx + 1, maks, 1);
        ret = ret % MOD;
    } else {
        ret = f(idx + 1, maks, 0);
    }

    //printf("-- %d %d %d -- %lld\n", idx, maks, udah, ret);

    return ret;
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }

    long long ans = f(0, 0, 0);
    printf("%lld\n", ans);
    return 0;
}

