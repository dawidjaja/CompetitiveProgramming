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
typedef vector<pii> vp;
typedef vector<double> vd;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    vi t(4);
    rep(i, 0, 4) {
        int a, b;
        scanf("%d.%d", &a, &b);
        t[i] = a * 100 + b;
    }

    sort(t.begin(), t.end());

    int a, b;
    scanf("%d.%d", &a, &b);

    int target = a * 300 + b * 3;

    if (t[1] + t[2] + t[3] <= target) {
        cout << "infinite\n";
        return 0;
    }

    if (t[0] + t[1] + t[2] > target) {
        cout << "impossible\n";
        return 0;
    }

    int ans = target - t[1] - t[2];
    printf("%d.%02d\n", ans/100, ans%100);
}
