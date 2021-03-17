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

    int n;
    cin >> n;

    vi lamps(n + 1, 1);
    int k;
    cin >> k;
    int ans = 0;

    rep(i, 0, k) {
        int x;
        cin >> x;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (j % x == 0) {
                lamps[j] ^= 1;
            }
            cnt += 1 - lamps[j];
        }
        ans = max(ans, cnt);
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
