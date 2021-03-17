#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
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

string s, t;
ll n, m;
ll dp[3005][3006];
const ll MOD = 998244353;

ll f(int l, int r) {
    if (l == -1 && r == n) {
        return 1;
    }

    
    if (dp[l + 1][r + 1] != -1) {
        return dp[l + 1][r + 1];
    }

    ll &ret = dp[l + 1][r + 1];
    ret = 0;
    if (l == -1 && r >= m) {
        ret = 1;
    }
    int cur = r - l - 1;
    //cout << l << ' ' << r << ' ' << cur << endl;
    if (l >= 0 && (l >= m || t[l] == s[cur])) {
        ret += f(l - 1, r);
        ret = ret % MOD;
    }
    if (r < n && (r >= m || t[r] == s[cur])) {
        ret += f(l, r + 1);
        ret = ret % MOD;
    }
    return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin >> s;
    n = s.length();
    cin >> t;
    m = t.length();
    memset(dp, -1, sizeof(dp));

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i >= m || s[0] == t[i]) {
            ans += f(i - 1, i + 1) * 2;
            ans = ans % MOD;
        }
    }
    cout << ans << endl;
}
