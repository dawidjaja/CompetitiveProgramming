#include <bits/stdc++.h>

using namespace std;

unordered_map <int, double> dp[2005];
double p[2005], ans;
int n, m;

double f(int cur, int diff) {
    if (cur == n + m - 1) {
        if (diff > 0) return 1;
        return 0;
    }

    if (dp[cur].count(diff)) {
        return dp[cur][diff];
    }

    dp[cur][diff] = p[cur] * f(cur + 1, diff + 1) + 
                    (1 - p[cur]) * f(cur + 1, diff - 1);

    return dp[cur][diff];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n + m - 1; i++) {
        scanf("%lf", &p[i]);
    }

    ans = f(0, n - m);
    printf("%.6lf\n", ans);

    return 0;
}
