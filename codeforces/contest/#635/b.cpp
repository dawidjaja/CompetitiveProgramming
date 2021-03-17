#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
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

void solve() {
    int x, n, m;
    cin >> x >> n >> m;

    for (int i = 0; i < n; i++) {
        x = min(x, (x / 2) + 10);
    }

    x -= m * 10;
    if (x <= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
