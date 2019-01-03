#include <bits/stdc++.h>

using namespace std;

int p[1000005];

int par(int x) {
    return p[x] == x ? x : p[x] = par(p[x]);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    while (q--) {
        getchar();
        char op = getchar();
        int a, b;
        scanf("%d%d", &a, &b);
        if (op == '=') {
            p[par(a)] = par(b);
        } else if (op == '?') {
            printf(par(a) == par(b) ? "yes\n" : "no\n");
        }
    }
    return 0;
}
