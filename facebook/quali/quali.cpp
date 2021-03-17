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

    string in, out;
    cin >> in;
    cin >> out;

    vvi grid(n);
    rep(i, 0, n) {
        vi x(n);
        grid[i] = x;

        int can = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (out[j + 1] == 'N' || in[j] == 'N') {
                can = 0;
            }
            grid[i][j] = can;
        }
        can = 1;
        for (int j = i + 1; j < n; j++) {
            if (out[j - 1] == 'N' || in[j] == 'N') {
                can = 0;
            }
            grid[i][j] = can;
        }
        grid[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                cout << "Y";
            } else {
                cout << "N";
            }
        }
        cout << endl;
    }


}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int tc = 1;

    cin >> tc;
    int tcc = 1;
    while (tc--) {
        cout << "Case #" << tcc << ":" << endl;
        tcc++;
        solve();
    }
}
