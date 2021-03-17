#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<ll> vll;
typedef vector<pii> vp;
typedef vector<double> vd;

inline void solve() {
    int n, m, p, q;
    scanf("%d%d", &n, &m);
    vi s(n);

    vvi va(m, vi(m, 0)), vb(m, vi(n));

    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    scanf("%d%d", &p, &q);

    // user follow user
    rep(i, 0, p) {
        int a, b;
        scanf("%d%d", &a, &b);
    }


    vector<set<int> > sfol(n);
    vvi vsfol(n);
    //user follow story
    rep(i, 0, q) {
        int a, b;
        scanf("%d%d", &a, &b);
        sfol[b].insert(a);
        vsfol[b].push_back(a);
    }

    rep(i, 1, n + 1) {
        rep(j, 0, vsfol[i].size()) {
            rep(k, j + 1, vsfol[i].size()) {
                va[vsfol[i][j]][vsfol[i][k]] = 1;
            }
        }
    }

    rep(i, 1, m + 1) {
        rep(j, i, m + 1) {

        }
    }
    return 0;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;

    //cin >> tc;
    while (tc--) {
        solve();
    }
}
