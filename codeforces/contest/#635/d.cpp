#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
//#define endl '\n'
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

vp gem;
vll prv[3], nxt[3];
const ll INF = 3 * 1e18;

ll get(ll a, ll b, ll c) {
    if (a == INF || b == INF || c == INF
        || a == -INF || b == -INF || c == -INF) return INF;
    //cout << a << ' ' << b << ' ' << c << endl;
    ll ret = (a - b) * (a - b) + 
        (b - c) * (b - c) + 
        (a - c) * (a - c);
    //cout << "ret: " << ret << endl;;
    return ret;
}

ll getAns(ll cur) {
    ll ret = INF;

    ll type = gem[cur].sc;
    vi pr, nx;

    for (ll i = 0; i < 3; i++) {
        if (type != i) {
            //cout << "getAns: " << i << ' '<< cur << '='<< prv[i][cur] << ' '<< type << endl;
            pr.push_back(prv[i][cur]);
            nx.push_back(nxt[i][cur]);
        }
    }

    vll asu;

    for (ll i = 0; i < 2; i++) {
        asu.push_back(pr[i]);
        asu.push_back(nx[i]);
    }
    /*
    cout << "gem: " << gem[cur].fs << endl;
    for (ll x: asu) {
        cout << "asu: " << x << endl;
    }
    */
    //cout << "ret: " << ret << endl;
    ret = min(ret, get(gem[cur].fs, asu[0], asu[2]));
    ret = min(ret, get(gem[cur].fs, asu[0], asu[3]));
    ret = min(ret, get(gem[cur].fs, asu[2], asu[1]));
    ret = min(ret, get(gem[cur].fs, asu[1], asu[3]));
    //cout << "retAns: " << ret << endl;
    return ret;

}

void solve() {
    ll na, nb, nc;
    cin >> na >> nb >> nc;
    ll n = na + nb + nc;
    gem.resize(n);
    ll x;

    rep(i, 0, na) {
        cin >> x;
        gem[i] = {x, 0};
    }
    rep(i, na, na + nb) {
        cin >> x;
        gem[i] = {x, 1};
    }
    rep(i, na + nb, na + nb + nc) {
        cin >> x;
        gem[i] = {x, 2};
    }

    sort(gem.begin(), gem.end());
    prv[0].resize(n);
    prv[1].resize(n);
    prv[2].resize(n);

    nxt[0].resize(n);
    nxt[1].resize(n);
    nxt[2].resize(n);

    vll cur = {-INF, -INF, -INF};
    for (ll i = 0; i < n; i++) {
        ll x = gem[i].sc;
        cur[x] = gem[i].fs;
        for (ll j = 0; j < 3; j++) {
            prv[j][i] = cur[j];
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        cout << "-- ";
        for (int j = 0; j < 3; j++) {
            cout << prv[j][i] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    */

    cur[0] = cur[1] = cur[2] = INF;
    for (ll i = n - 1; i >= 0; i--) {
        ll x = gem[i].sc;
        cur[x] = gem[i].fs;
        for (ll j = 0; j < 3; j++) {
            nxt[j][i] = cur[j];
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        cout << "-- ";
        for (int j = 0; j < 3; j++) {
            cout << nxt[j][i] << ' ';
        }
        //cout << endl;
    }
    */

    ll ans = INF;
    for (ll i = 0; i < n; i++) {
        ans = min(ans, getAns(i));
        //cout << "ans: " << ans << endl;
    }

    cout << ans << endl;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll tc;

    cin >> tc;

    while (tc--) {
        solve();
    }
}
