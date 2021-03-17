#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi topo_sort(const vector<vi>& gr) {
    vi indeg(sz(gr)), ret;
    trav(li, gr) trav(x, li) indeg[x]++;
    queue<int> q; // use pr ior ity queue for l e x i c . sma l lest ans .
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(-i);
    while (!q.empty()) {
        int i = -q.front(); // top () for pr ior ity queue
        ret.push_back(i);
        q.pop();
        trav(x, gr[i])
            if (--indeg[x] == 0) q.push(-x);
    }
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    getchar();
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        char c = getchar();
        val[i] = c == '.' ? -1 : 1;
    }

    const int INF = 1e9;
    vector<int> par(n), vis(n, -INF);
    vector<vi> v(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        par[b]++;
    }

    vis[0] = 0;
    val[0] = 0;
    val[n - 1] = 0;
    vi ord = topo_sort(v);

    for (int i = 0; i < n; i++) {
        //printf("-- %d %d --\n", i, ord[i]);
        for (int nx: v[ord[i]]) {
            //printf("inside -- %d %d\n", ord[i], nx);
            vis[nx] = max(vis[nx], vis[ord[i]] + val[nx]);
        }
    }

    printf("%d\n", vis[n - 1]);
    return 0;
}
