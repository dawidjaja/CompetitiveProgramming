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
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1 || n + m == 4) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int tc = 1;

    cin >> tc;
    while (tc--) {
        solve();
    }
}
