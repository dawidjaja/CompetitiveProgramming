#include <bits/stdc++.h>

using namespace std;

int p[100005][22], h[100005], n, q, a, b, c, d;
vector <int> v[100005];

int dfs(int cur, int prev, int hei) {
    p[cur][0] = prev;
    h[cur] = hei;
    for (int i = 0; i < v[cur].size(); i++) {
        if (v[cur][i] == prev) {
            continue;
        }
        dfs(v[cur][i], cur, hei + 1);
    }
}

void buildLCA() {
    dfs(1, 0, 0);
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (p[i][j - 1] == -1) continue;
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
}

int getLCA(int a, int b) {
    if (h[b] < h[a]) {
        swap(a, b);
    }

    for (int i = 19; i >= 0; i--) {
        if (p[b][i] == -1) continue;
        if (h[p[b][i]] >= h[a]) {
            b = p[b][i];
        }
    }

    if (a == b) return a;

    for (int i = 19; i >= 0; i--) {
        if (p[a][i] == -1) continue;
        if (p[a][i] != p[b][i]) {
            a = p[a][i];
            b = p[b][i];
        }
    }

    return p[a][0];
}

int getDist(int a, int b) {
    int c = getLCA(a, b);
    return h[a] - h[c] + h[b] - h[c];
}

bool intersect(int a, int b, int c, int d) {
    int e = getLCA(a, b);
    int f = getLCA(c, d);
    int cd = getDist(c, d);
    int ab = getDist(a, b);
    if (cd == getDist(c, a) + getDist(a, d) || 
        cd == getDist(c, b) + getDist(b, d) || 
        cd == getDist(c, e) + getDist(e, d) || 
        ab == getDist(a, c) + getDist(c, b) || 
        ab == getDist(a, d) + getDist(d, b) || 
        ab == getDist(a, f) + getDist(f, b)) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 20; j++) {
            p[i][j] = -1;
        }
    }

    buildLCA();

    while (q--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (intersect(a, b, c, d)) {
            int ad = getDist(a, d);
            int bc = getDist(b, c);
            int ac = getDist(a, c);
            int bd = getDist(b, d);
            int ans = abs((ad + bc - ac - bd) / 2) + 1;
            printf("%d\n", ans);
        } else {
            printf("0\n");
            continue;
        }
    }

    return 0;
}
