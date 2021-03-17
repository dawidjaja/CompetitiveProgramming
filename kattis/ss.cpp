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
typedef pair<int, pii> pip;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<ll> vll;
typedef vector<pii> vp;
typedef vector<double> vd;

void solve(int n) {
    vector<pair<int, long double> > v(n);
    rep(i, 0, n) {
        scanf("%d%Lf", &v[i].fs, &v[i].sc);
    }

    vector<long double> ps(n);
    rep(i, 0, n) {
        if (i != 0) assert(v[i - 1].fs != v[i].fs);
        if (i == 0) {
            ps[i] = v[i].sc;
        } else {
            ps[i] = ps[i - 1] + v[i].sc;
        }
    }
    pair<long double, pii> ans = {0, {0, 0}};
    rep(i, 0, n) {
        rep(j, i, n) {
            long double cur = ps[j] - (i == 0 ? 0 : ps[i - 1]);
            cur -= 0.08 * (v[j].fs - v[i].fs + 1);
            if (ans.fs < cur || 
                    (ans.fs == cur && (ans.sc.sc - ans.sc.fs > v[j].fs - v[i].fs)) ||
                    (ans.fs == cur && (ans.sc.sc - ans.sc.fs == v[j].fs - v[i].fs) && ans.sc.fs > v[i].fs)) {
                ans = {cur, {v[i].fs, v[j].fs}};
            }
        }
    }
    if (ans.fs <= 0.0) {
        printf("no profit\n");
    } else {
        printf("%.2Lf %d %d\n", ans.fs, ans.sc.fs, ans.sc.sc);
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    //int tc = 1;

    //cin >> tc;
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        solve(n);
    }
}
