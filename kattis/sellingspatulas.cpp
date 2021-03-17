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
    vp v(n);
    rep(i, 0, n) {
        double x;
        scanf("%d%lf", &v[i].fs, &x);
        v[i].sc = x * 100;
    }

    vi ps(n);
    rep(i, 0, n) {
        if (i != 0) assert(v[i - 1].fs != v[i].fs);
        if (i == 0) {
            ps[i] = v[i].sc;
        } else {
            ps[i] = ps[i - 1] + v[i].sc;
        }
    }
    pip ans = {0, {0, 0}};
    int minCur = -8 * (v[0].fs - 1);
    int last = v[0].fs;
    rep(i, 0, n) {
        int cur = ps[i] + v[i].fs * -8;
        printf("-- %d %d %d = %d \n", i, cur, minCur, cur - minCur);
        cur -= minCur;
        if (ans.fs < cur || 
                (ans.fs == cur && (ans.sc.sc - ans.sc.fs > v[i].fs - last)) ||
                (ans.fs == cur && (ans.sc.sc - ans.sc.fs == v[i].fs - last) && ans.sc.fs > last)) {
            ans = {cur, {last, v[i].fs}};
        }
        if (i < n - 1) {
            if (cur + -8 * (v[i + 1].fs - v[i].fs) <= minCur) {
                minCur = cur + -8 * (v[i + 1].fs - v[i].fs);
                last = v[i + 1].fs;
            }
        }
    }
    if (ans.fs == 0) {
        printf("no profit\n");
    } else {
        assert(ans.fs > 0);
        printf("%d.%02d %d %d\n", ans.fs / 100, ans.fs % 100, ans.sc.fs, ans.sc.sc);
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
