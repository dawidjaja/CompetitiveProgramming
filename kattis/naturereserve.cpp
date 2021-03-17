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

    int n, m, l, s;
    cin >> n >> m >> l >> s;

    priority_queue<pii> pq;

    rep(i, 0, s) {
        int x;
        cin >> x;
        pq.push_back({0, x});
    }
    
    while (pq.size()) {
        pii cur = pq.top();
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;

    cin >> tc;
    while (tc--) {
        solve();
    }
}
