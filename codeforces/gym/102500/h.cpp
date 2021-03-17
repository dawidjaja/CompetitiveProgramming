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

double getG(int curh, int l, int r) {
    if (r == l) return 0;
    return 1.0 * curh / ((r - l) * 10);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, k;
    vi h(n + 1);

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    vd g(k);
    for (int i = 0; i < k; i++) {
        scanf("%lf", &g[i]);

        int l = 0; 
        int ans = 0;

        for (int r = 0; r < n; r++) {
            int curh = h[r] - h[l];
            while (l < r && getG(curh, l, r) < g[i]) {
                l++;
                curh = h[r] - h[l];
            }

            if (getG(curh, l, r) >= g[i]) {
                ans = max(ans, r - l);
            }
        }


        if (ans == 0) ans = -1;
        printf("%d\n", ans);

    }
    
}
