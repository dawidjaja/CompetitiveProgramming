#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
//#define endl '\n'
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

int n;

inline void solve() {

    cin >> n;
    vi e(n), d(n), child(n);

    vvi par(n);

    rep(i, 0, n) {
        par[i] = vi();
    }

    rep(i, 0, n) {
        cin >> e[i];
        cin >> d[i];

        rep(j, 0, d[i]) {
            int x;
            cin >> x;
            x--;
            par[i].pb(x);
            child[x]++;
        }
    }

    priority_queue <pii> pq;
    rep(i, 0, n) {
        if (child[i] == 0) {
            pq.push({-e[i], i});
        }
    }

    int ord = n - 1;
    int ans = 0;
    while (pq.size()) {
        int cur = pq.top().sc;
        int c = -pq.top().fs;
        pq.pop();


        ans = max(ans, c + ord);
        ord--;

        for (int nx: par[cur]) {
            child[nx]--;
            if (child[nx] == 0) {
                pq.push({-e[nx], nx});
            }
        }
    }

    cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int tc = 1;

    //cin >> tc;
    while (tc--) {
        solve();
    }
}
