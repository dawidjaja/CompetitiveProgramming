#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
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
    int n;

    cin >> n;
    vi a(n), b(n);
    int pos = n + 1;
    int neg = n + 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            pos = min(pos, i);
        } 
        if (a[i] == -1) {
            neg = min(neg, i);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] == a[i]) {
            continue;
        } else if (b[i] < a[i]) {
            if (neg >= i) {
                ans = 0;
                break;
            }
        } else if (b[i] > a[i]) {
            if (pos >= i) {
                ans = 0;
                break;
            }
        }
    }
    if (ans) {
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
