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
    int n;
    scanf("%d", &n);
    vi val(n);
    const int inf = 1e9;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    vector<vi> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            int y;
            scanf("%d", &y);
            v[i].push_back(y - 1);
        }
    }

    vi ord = topo_sort(v);

    int ans = inf;
    for (int bl = 0; bl < n; bl++) {
        vi vis(n, -inf);
        if (ord[0] == bl) {
            vis[ord[0]] = 0;
        } else {
            vis[ord[0]] = val[ord[0]];
        }
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int nx: v[ord[i]]) {
                int nv = nx == bl ? 0 : val[nx];
                vis[nx] = max(vis[nx], nv + vis[ord[i]]);
            }
            //printf("-- %d %d --\n", ord[i], vis[ord[i]]);
            tmp = max(tmp, vis[ord[i]]);
        }
        ans = min(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}
