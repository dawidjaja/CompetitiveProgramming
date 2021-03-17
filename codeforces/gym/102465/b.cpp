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
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<ll> vll;
typedef vector<pii> vp;
typedef vector<double> vd;
const int INF = 1000005;

int solver(vp &bd) {
    vi lo(n);
    vi hi(n);

    vp vdu(bd);
    for (int i = 0; i < n; i++) {
        vdu[i].fs -= i;
        vdu[i].sc -= i;
    }

    vp st;
    st.pb({INF, n});
    for (int i = n - 1; i >= 0; i--) {
        while (st.back().fs <= bd[i].fs) {
            st.pop_back();
        }
        lo[i] = st.back().sc - 1;
        if (i != 0 && bd[i].fs != bd[i - 1].fs && bd[i].fs < st.back().fs) {
            st.pb({bd[i].fs, i});
        }
    }

    st.clear();
    st.pb({-INF, n});
    for (int i = n - 1; i >= 0; i--) {
        while (st.back().fs >= bd[i].sc) {
            st.pop_back();
        }
        hi[i] = st.back().sc - 1;
        if (i != 0 && bd[i].sc != bd[i - 1].sc && bd[i].sc > st.back().fs) {
            st.pb({bd[i].sc, i});
        }
    }
    int ans;
    for (int i = 0; i < n; i++) {
        int l = 1;
    }
}

inline void solve() {
    int n;
    cin >> n;

    vp bd(n);
    rep(i, 0, n) {
        cin >> bd[i].fs >> bd[i].sc;
    }

    int ans = solver(bd);
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
