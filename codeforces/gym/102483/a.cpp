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

inline double getAns(vector<int> &p) {
    
    vector<pair<double, int> > cur;
    double ttl;

    rep(i, 0, n) {
        double run = p[i];
        int freq = 1;
        while (cur.size() != 0 && cur[cur.size() - 1].fs >= run) {
            pair<double,int> tmp = cur[cur.size() - 1];
            cur.pop_back();
            double ttl = run * freq + tmp.fs * tmp.sc;
            freq += tmp.sc;
            run = ttl / freq;
        }
        cur.pb({run, freq});
    }

    int ptr = 0;
    double ans = 0;
    for (pair<double,int> x: cur) {
        rep(i, 0, x.sc) {
            ans += (x.fs - p[ptr]) * (x.fs - p[ptr]);
            ptr++;
        }
    }
    return ans;
}

inline void solve() {
    cin >> n;

    vi y(n), x(n);
    
    rep(i, 0, n) {
        cin >> y[i] >> x[i];
    }

    double yy = getAns(y);
    double xx = getAns(x);
    double ans = yy + xx;

    cout << fixed << setprecision(6) <<  ans << endl;

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
