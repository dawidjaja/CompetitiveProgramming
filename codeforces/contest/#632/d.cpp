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
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<ll> vll;
typedef vector<pii> vp;

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    //cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);

    int n, k;
    //scanf("%d%d", &n, &k);
    cin >> n >> k;

    vector<char> s(n);
    //getchar();
    for (int i = 0; i < n; i++) {
        //s[i] = getchar();
        cin >> s[i];
    }

    char r = 'R';
    char l = 'L';

    vp ans;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == r && s[i + 1] == l) {
            ans.push_back({i, 0});
        }
    }

    int ptr = 0;
    int minlvl = 0;

    while (ptr < 9000005 && ptr < ans.size()) {
        pii cur = ans[ptr];
        ptr++;

        s[cur.fs] = l;
        s[cur.fs + 1] = r;

        if (cur.fs > 0 && s[cur.fs - 1] == r) {
            ans.push_back({cur.fs - 1, cur.sc + 1});
        }

        if (cur.sc < n - 1 && s[cur.fs + 2] == l) {
            ans.push_back({cur.fs + 1, cur.sc + 1});
        }
    }
    if (ans.size() > 0) {
        minlvl = ans[ans.size() - 1].sc;
    }

    /*
       for (pii x: ans) {
       cout << "pair: " << x.fs << ' ' << x.sc << '\n';
       }
       */

    int dui = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == r && s[i + 1] == l) {
            dui = 0;
            break;
        }
    }
    //cout << dui << '\n';


    if (dui) {
        if (minlvl + 1 <= k && k <= ans.size()) {
            int cur = ans.size();
            vvi fin;
            int cnt = minlvl + 1;
            int curlvl = 0;
            vi x;
            //fin.push_back(x);
            for (int i = 0; i < ans.size(); i++) {
                if (i != 0 &&
                        (ans[i].sc != ans[i - 1].sc ||
                         cnt < k)) {
                    if (ans[i].sc == ans[i - 1].sc) {
                        cnt++;
                    }
                    if (i != 0) {
                        //printf("%d", x.size());
                        cout << x.size();
                        for (int y: x) {
                            //printf(" %d", y + 1);
                            cout << ' ' << y + 1;
                        }
                        //printf("\n");
                        cout << '\n';
                    }
                    x.clear();
                    /*
                       curlvl++;
                       vi x;
                       */
                }
                x.push_back(ans[i].fs);
            }
            //printf("%d", x.size());
            cout << x.size();
            for (int y: x) {
                //printf(" %d", y + 1);
                cout << ' ' << y + 1;
            }
            //printf("\n");
            cout << '\n';
        } else {
            //printf("-1\n");
            cout << -1 << '\n';
        }

    } else {
        //printf("-1\n");
        cout << -1 << '\n';
    }
}
