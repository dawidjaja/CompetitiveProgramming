#include <bits/stdc++.h>

using namespace std;

int main() {
    while (scanf("%d%d%d", &n, &m, &q) && (n || m || q)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sp[i][j] = INF;
            }
        }
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            sp[a][b] = c;
        }
    }
}
