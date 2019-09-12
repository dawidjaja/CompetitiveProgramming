#include <bits/stdc++.h>

using namespace std;

int n, m, p[10005];
long long money[10005];

int par(int x) {
    return x == p[x] ? x : p[x] = par(p[x]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &money[i]);
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (par(a) != par(b)) {
            money[par(b)] += money[par(a)];
            p[par(a)] = par(b);
        }
    }
    for (int i = 0; i < n; i++) {
        if (money[par(i)] != 0) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    printf("POSSIBLE\n");
}
