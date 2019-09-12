#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll idx;

vector <ll> v[100005];
ll lazy[400050], stree[400050], n, q, node, w, pre[100005], pos[100005], root, p[100005];
const ll MOD = 100123456789LL;

void dfs(ll cur, ll prev) {
    pre[cur] = ++idx;

    for (ll i = 0; i < v[cur].size(); i++) {
        if (v[cur][i] != prev) {
            dfs(v[cur][i], cur);
        }
    }

    pos[cur] = idx;
}

ll update(ll cur, ll l, ll r, ll a, ll b, ll x) {
    if (b < l || r < a) {
        return (stree[cur] + ((lazy[cur] * (r - l + 1)) % MOD)) % MOD;
    }

    if (a <= l && r <= b) {
        lazy[cur] += x;
        return (stree[cur] + ((lazy[cur] * (r - l + 1)) % MOD)) % MOD;
    }

    ll mid = (l + r) >> 1;
    
    ll ta = update(cur * 2, l, mid, a, b, x);
    ll tb = update(cur * 2 + 1, mid + 1, r, a, b, x);

    stree[cur] = (ta + tb) % MOD;

    //printf("%lld asdf %lld\n", ta, tb);
    //printf("-- %lld - %lld %lld -- %lld %lld - %lld - %lld\n", cur, l, r, a, b, x, stree[cur]);

    return (stree[cur] + (lazy[cur] * (min(r, b) - max(l, a) + 1) % MOD) % MOD);
}

ll query(ll cur, ll l, ll r, ll a, ll b) {
    if (b < l || r < a) {
        return 0;
    } 

    if (a <= l && r <= b) {
        return (stree[cur] + (((lazy[cur] * (r - l + 1))) % MOD)) % MOD;
    }

    ll mid = (l + r) >> 1;

    ll ta = query(cur * 2, l, mid, a, b);
    ll tb = query(cur * 2 + 1, mid + 1, r, a, b);

    //printf("query %lld asdf %lld\n", ta, tb);
    //printf("query -- %lld - %lld %lld -- %lld %lld - %lld\n", cur, l, r, a, b, stree[cur]);
    
    return (((ta + tb) % MOD) + (lazy[cur] * (min(r, b) - max(l, a) + 1)) % MOD) % MOD;
}

int main() {
    while(scanf("%lld%lld", &n, &q)) {
        if (n == 0 && q == 0) return 0;

        idx = 0;
        for (ll i = 0; i < n; i++) {
            v[i].clear();
        }

        for (ll i = 0; i < 400050; i++) {
            lazy[i] = 0;
            stree[i] = 0;
        }

        for (ll i = 0; i < n; i++) {
            scanf("%lld", &p[i]);
            if (p[i] != -1) {
                v[p[i]].push_back(i);
            }
            if (p[i] == -1) {
                root = i;
            }
        }

        dfs(root, -1);

        /*
        for (ll i = 0; i < n; i++) {
            printf("-- %lld -- %lld %lld\n", i, pre[i], pos[i]);
        }*/

        while (q--) {
            char cmd[3];
            scanf("%s", cmd);
            if (cmd[0] == 'U') {
                scanf("%lld%lld", &node, &w);
                update(1, 1, 100005, pre[node], pos[node], w);
            } else {
                scanf("%lld", &node);
                printf("%lld\n", ((query(1, 1, 100005, pre[node], pos[node]) + MOD) % MOD));
            }
        }
        printf("\n");
    }
    return 0;
}
