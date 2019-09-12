#include <bits/stdc++.h>

using namespace std;

int f(int x, int y) {
    int ret = &dp[x][y];
    if (ret != -1) {
        return ret;
    }
    ret = max(f(x + 1, y), f(x, y + 1));
    if (s[x] == t[y]) {
        ret = max(ret, 1 + f(x + 1, y + 1));
    }
    return ret;
}

int main() {
    int n = 0;
    while (scanf("%1d", &s[n]) != EOF) {
        t[n] = 1 - s[n];
        n++;
    }
    lcs = f(0, 0);

    if ((n - lcs) * 2 > n / 2) {
        for (int i = 0; i < n; i++) {
            printf("%d", t[i]);
        }
        printf("%d\n");
    } else {

    }
    return 0;
}
