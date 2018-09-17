#include <algorithm>
#include <cstdio>

using namespace std;

int dp[300005], n, m, ans, list[300005];

int f(int pos) {
    if (pos >= n) return 0;
    if (dp[pos] != -1) return dp[pos];
    return dp[pos] = max(f(pos + 1), f(pos + m) + list[pos]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
        dp[i] = -1;
    }
    ans = f(m);
    printf("%d\n", ans);
    return 0;
}
