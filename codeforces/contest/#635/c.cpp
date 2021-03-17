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

vector<int> h;
vi v[200005];
int p[200005];
vi ch;

void dfs(int cur, int prv) {
    for (int x: v[cur]) {
        if (x != prv) {
            h[x] = h[cur] + 1;
            p[x] = cur;
            dfs(x, cur);
            ch[cur] += ch[x] + 1;
        }
    }
    h[cur] -= ch[cur];
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, k;
    cin >> n >> k;
    h.resize(n);
    ch.resize(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }


    h[0] = 0;
    p[0] = -1;
    dfs(0, -1);

    //sort(h.begin(), h.end(), cmp);

    vi car(n, 1);

    priority_queue<pii> pq;

    /*
    rep(i, 0, n) {
        cout << "k: " << i << ' ' << h[i] << endl;
    }
    */

            /*
    for (int i = 0; i < n; i++) {
        pq.push({h[i], i});
    }
    */
    long long ans = 0;
    sort(h.begin(), h.end(), cmp);
    rep(i, 0, k) {
        ans += h[i];
    }
    /*
    while (k) {
        int cur = pq.top().sc;
        int val = pq.top().fs;
        pq.pop();
        if (val == h[cur]) {
            ans += h[cur];
            if (cur != 0) {
                h[p[cur]] -= car[cur];
                car[p[cur]] = car[cur] + 1;
                pq.push({h[p[cur]], p[cur]});
            }
            k--;
        }
    }
    */
    cout << ans << endl;
}
