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

int f(int start, int cur, int rem) {
    /*
    if (cur >= n) {
        return nearRound(getSum(start, n - 1));
    }
    if (rem == 0) {
        return nearRound(getSum(start, n - 1));
    }

    int &ret = dp[start][cur][rem];
    if (ret != -1) return ret;
    */

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            for (int k = 0; k <= d; k++) {
                // base case
                if (j >= n || k == 0) {
                    dp[i][j][k] = nearRound(getSum(i, n - 1));
                } else {
                    dp[i][j][k] = min(dp[i][j + 1][k],
                        dp[j + 1][j + 1][k - 1] + nearRound(getSum(i, j)));
                }
            }
        }
    }

    /*
    ret = min(f(start, cur + 1, rem),
              f(cur + 1, cur + 1, rem - 1) + nearRound(getSum(start, cur)));
              */
    return dp[start][cur][rem];
    //return ret;
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
