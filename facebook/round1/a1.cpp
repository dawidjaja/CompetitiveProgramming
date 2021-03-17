#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define endl '\n'
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vector <ll> > vvi;
typedef vector<ll> vll;
typedef vector<pii> vp;
typedef vector<double> vd;
const ll MOD = 1000000007;

inline void solve() {
    ll n, k, w;

    cin >> n >> k >> w;

    vll l(n);
    ll al, bl, cl, dl;
    vll h(n);
    ll ah, bh, ch, dh;

    rep(i, 0, k) {
        cin >> l[i];
    }
    cin >> al >> bl >> cl >> dl;
    rep(i, k, n) {
        l[i] = ((al * l[i - 2] + bl * l[i - 1] + cl) % dl) + 1;
    }

    rep(i, 0, k) {
        cin >> h[i];
    }
    cin >> ah >> bh >> ch >> dh;
    rep(i, k, n) {
        h[i] = ((ah * h[i - 2] + bh * h[i - 1] + ch) % dh) + 1;
    }

    ll ymax = h[0];
    ll xmin = l[0];
    ll xmax = l[0] + w;
    ll ttlp = 0;
    ll ans = 1;
    rep(i, 0, n) {
        if (xmax >= l[i]) {
            xmax = l[i] + w;
            ymax = max(ymax, h[i]);
        } else {
            ttlp += (ymax + xmax - xmin) * 2;
            ymax = h[i];
            xmin = l[i];
            xmax = l[i] + w;
        }
        ll p = ttlp + (ymax + xmax - xmin) * 2;
        cout << endl <<  i << ' ' << p << " - " ;
        ans *= p;
        ans = ans % MOD;
    }
    cout << ans << endl;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll tc = 1;

    cin >> tc;
    ll ctr = 1;
    while (tc--) {
        cout << "Case #" << ctr++ << ": ";
        solve();
    }
}
