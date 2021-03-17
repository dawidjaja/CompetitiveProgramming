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
typedef vector<pii> vp;
typedef vector<double> vd;

int n;
int cm, cd;
vi s;

bool same(int a, int b) {
    if (a < 0 && b < 0) return true;
    if (a > 0 && b > 0) return true;
    return false;
}

ll getAns(int m) {
    ll ret = 0;
    int nx = 1;
    for (int i = 0; i < n; i++) {
        if (same(s[i], nx)) {
            nx *= -1;
        } else {
            if (abs(s[i]) + 1 <= m) {
                nx *= -1;
            } else {
                ret += cd;
            }
        }
    }
    ll ans = ret;

    ret = 0;
    nx = -1;
    for (int i = 0; i < n; i++) {
        if (same(s[i], nx)) {
            nx *= -1;
        } else {
            if (abs(s[i]) + 1 < m) {
                nx *= -1;
            } else {
                ret += cd;
            }
        }
    }

    ans = min(ans, ret);
    ans += 1LL * cm * m;
    return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


    cin >> n >> cm >> cd;

    s.resize(n);
    rep(i, 0, n) {
        cin >> s[i];
    }

    int l, r;
    l = 0;
    r = 1000000002;

    while (l < r) {
        int mid1 = (2 * l + r) / 3;
        int mid2 = (l + 2 * r) / 3;
        printf("%d %d\n", l, r);
        printf("%d %d\n", mid1, mid2);
        printf("ans: %lld %lld\n", getAns(mid1), getAns(mid2));

        if (getAns(mid1) < getAns(mid2)) {
            r = mid2 - 1;
        } else {
            l = mid1 + 1;
        }
    }
    printf("%lld\n", getAns(l));

}
