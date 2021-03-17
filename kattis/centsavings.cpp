#include <bits/stdc++.h>

using namespace std;

int dp[2005][2005][21], n, d, p[2005], ps[2005], ans;

int nearRound(int x) {
    if (x % 10 < 5) {
        return x - (x % 10);
    } else {
        return x + (10 - (x % 10));
    }
}

int getSum(int a, int b) {
    return ps[b] - (a == 0 ? 0 : ps[a - 1]);
}

int f(int i, int j, int k) {
    if (j >= n) {
        return nearRound(getSum(i, n - 1));
    }
    if (k == 0) {
        return nearRound(getSum(i, n - 1));
    }

    int &ret = dp[i][j][k];
    if (ret != -1) return ret;

    ret = min(f(i, j + 1, k),
              f(j + 1, j + 1, k - 1) + nearRound(getSum(i, j)));
    return ret;
}

int main() {
    scanf("%d%d", &n, &d);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        ps[i] = (i == 0 ? 0 : ps[i - 1]) + p[i];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= 20; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    ans = f(0, 0, d);
    printf("%d\n", ans);
    return 0;
}
