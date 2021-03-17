#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<ll> vll;
typedef vector<ppi> vp;

vp pts;

int cross(int a, int b, int c) {
    int p, q, r, s;
    p = pts[b].fs.fs - pts[a].fs.fs;
    q = pts[b].fs.sc - pts[a].fs.sc;
    r = pts[c].fs.fs - pts[b].fs.fs;
    s = pts[c].fs.sc - pts[b].fs.sc;
    return p * s - q * r;
}

bool left(vi &v, int x) {
    return cross(v[v.size() - 2], 
              v[v.size() - 1],
              x) > 0;
}

void solve() {
    int n;
    cin >> n;
    pts.resize(n);
    vi vis(n);

    for (int i = 0; i < n; i++) {
        cin >> pts[i].fs.fs >> pts[i].fs.sc;
        pts[i].sc = i;
    }

    sort(pts.begin(), pts.end());

    vi uh;
    for (int i = 0; i < n; i++) {
        while (uh.size() > 1 && left(uh, i)) {
            vis[uh[uh.size() - 1]] = 0;
            uh.pop_back();
        }
        uh.push_back(i);
        vis[i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (vis[i] == 0) {
            uh.push_back(i);
        }
    }

    int first = 1;
    for (int x: uh) {
        if (first) {
            cout << pts[x].sc;
        } else {
            cout << ' ' << pts[x].sc;
        }
        /*
        cout << pts[x].fs.fs << ' ' << pts[x].fs.sc << endl;
        */
        first = 0;
    }
    cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

}
