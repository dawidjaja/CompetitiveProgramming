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

bool cmp(ppi a, ppi b) {
    return a.sc > b.sc;
}

inline void solve() {
    int n, m, k;
    pii start;
    rep(i, 0, n) {
        getchar();
        rep(j, 0, m) {
            char c = getchar();
            if (c == '#') {
                grid[i][j] = 1;
            } else if (c == '.') {
                grid[i][j] = 0;
            } else if (c == 'S') {
                start = {i, j};
                grid[i][j] = 0;
            } else if (c == 'E') {
                grid[i][j] = 0;
            }
        }
    }
    
    int k;
    scanf("%d", &k);

    vector<ppi> guards(k);
    rep(i, 0, k) {
        scanf("%d%d%d", &guards[i].fs.fs, &guards[i].fs.sc, &guards[i].sc);
        guards[i].fs.fs--;
        guards[i].fs.sc--;
    }
    sort(guards.begin(), guards.end(), cmp);
    int ptr = 0;

    vi a{0, -1, 0, 1};
    vi b{1, 0, -1, 0};

    q.push(guards[ptr]);
    while (q.size()) {
        ppi cur = q.front();
        q.pop();
        if (
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;

    //cin >> tc;
    while (tc--) {
        solve();
    }
}
