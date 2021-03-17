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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vi v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }


    int sorted = 1;

    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) {
            sorted = 0;
        }
    }

    if (sorted) {
        cout << "1 1\n";
        return 0;
    }
    int st = -1;
    int en = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] > v[i + 1]) {
            st = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (v[i - 1] > v[i]) {
            en = i;
            break;
        }
    }

    //cout << st << ' ' << en << endl;
    while (st > 0 && v[st] == v[st - 1]) {
        st--;
    }

    while (en < n - 1 && v[en] == v[en + 1]) {
        en++;
    }

    //cout << st << ' ' << en << endl;
    if (st == n - 1 && en == -1) {
        st = 0;
        en = 0;
    }
    


    pii ans = {st + 1, en + 1};
    for (; st < en; st++, en--) {
        swap(v[st], v[en]);
    }

    int can = 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            can = 0;
            break;
        }
    }

    if (can) {
        cout << ans.fs << ' ' << ans.sc << endl;
    } else {
        cout << "impossible" << endl;
    }
}
