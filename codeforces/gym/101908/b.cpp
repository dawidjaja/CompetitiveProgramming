#include <bits/stdc++.h>

using namespace std;

int grundy[105][105], n, a, b, ans;
set <int> s;

int main() {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (i == 0 || j == 0 || i == j) {
                grundy[i][j] = 1000;
                continue;
            }
            s.clear();
            for (int k = 0; k < i; k++) {
                s.insert(grundy[k][j]);
            }
            for (int k = 0; k < j; k++) {
                s.insert(grundy[i][k]);
            }
            for (int k = 1; k <= 100; k++) {
                if (i - k < 0 || j - k < 0) {
                    break;
                }
                s.insert(grundy[i - k][j - k]);
            }
            for (int k = 0; k <= 1000; k++) {
                if (!s.count(k)) {
                    grundy[i][j] = k;
                    break;
                }
            }
        }
    }

    ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        ans ^= grundy[a][b];
    }
    if (ans != 0) {
        printf("Y\n");
    } else {
        printf("N\n");
    }
}
