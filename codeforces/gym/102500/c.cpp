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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vp v(n);
    rep(i, 0, n) {
        cin >> v[i].fs >> v[i].sc;
    }

    int p;
    cin >> p;
    vi x(p);
    vi cnt(n);

    unordered_map <int,int> ada;

    rep(i, 0, p) {
        cin >> x[i];
        ada[x[i]] = 1;
    }

    int ptr = 0;
    if (p != 0) {
        rep(i, 0, n) {
            while (ptr < p && x[ptr] < v[i].fs) {
                ptr++;
            }

            while (ptr < p && x[ptr] < v[i].sc) {
                cnt[i]++;
                ptr++;
            }

            if (x[ptr] == v[i].sc) {
                cnt[i]++;
            }
        }
    }

    int impo = 0;
    vi ans;
    rep(i, 0, n) {
        if (cnt[i] > 2) {
            impo = 1;
            break;
        }
        if (i < n - 1 && cnt[i] < 2 && 
                cnt[i + 1] < 2) {
            if (v[i].sc == v[i + 1].fs && 
                !ada.count(v[i].sc)) {
                ans.push_back(v[i].sc);
                ada[v[i].sc] = 1;
                cnt[i]++;
                cnt[i + 1]++;
            }
        }
        while (cnt[i] < 2) {
            for (int j = v[i].fs; j <= v[i].sc; j++) {
                if (!ada.count(j)) {
                    if (j == v[i].fs && i != 0 && v[i].fs == v[i - 1].sc) {
                        continue;
                    }
                    ada[j] = 1;
                    cnt[i]++;
                    ans.push_back(j);
                    break;
                }
            }
        }
    }

    if (impo) {
        cout << "impossible\n";
    } else {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }

}
