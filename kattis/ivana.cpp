#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

int n;
const int INF = 1e9 + 7;
vi s;
int dp[105][105];

int mv(int x, int a) {
    return (x + a + n) % n;
}

int f(int l, int r) {
    if (l == r) return s[l];

    int &ret = dp[l][r];
    if (ret != INF) {
        return ret;
    }
    ret = max(s[l] - f(mv(l, -1), r), 
              s[r] - f(l, mv(r, 1)));
    return ret;
}

int main() {
    scanf("%d", &n);
    s.assign(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        s[i] = s[i] % 2;
    }

    int ans = -INF;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int tmp = s[i] - f(mv(i, -1), mv(i, 1));
        //printf("-- %d %d--\n", i, tmp);
        if (tmp > 0) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
