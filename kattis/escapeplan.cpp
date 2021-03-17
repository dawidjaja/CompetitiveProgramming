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
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<ll> vll;
typedef vector<pii> vp;
typedef vector<double> vd;
typedef vector<pdd> vpd;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

int n, m;

double dist(int x, int y, vpd &h, vpd &r) {
    double xx = h[x].fs - r[y].fs;
    xx *= xx;
    double yy = h[x].sc - r[y].sc;
    yy *= yy;
    return xx + yy;
}

void solve() {

    vpd holes(m);

    rep(i, 0, m) {
        cin >> holes[i].fs >> holes[i].sc;
    }

    cin >> n;

    vpd robot(n);
    rep(i, 0, n) {
        cin >> robot[i].fs >> robot[i].sc;
    }

    vi times = {5, 10, 20};
    for (int t : times) {
        vvi a(n);
        vi b(m, -1);

        rep(i, 0, m) {
            rep(j, 0, n) {
                if (dist(i, j, holes, robot) < 100 * t * t) {
                    a[j].push_back(i);
                }
            }
        }

        int ans = hopcroftKarp(a, b);

        cout << "In " << t << " seconds " << ans << " robot(s) can escape" << endl;
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


    int tc = 1;
    do {
        cin >> m;
        if (m == 0) break;
        cout << "Scenario " << tc++ << endl;
        solve();
        cout << endl;
    } while (true);
}
