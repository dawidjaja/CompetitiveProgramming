#include <bits/stdc++.h>

using namespace std;

int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        deg[i] = i;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
        deg[a].fs++;
        deg[b].fs++;
        p[a] = par(b);
    }

    for (int i = 1; i <= n; i++) {

    }
    return 0;
}
