#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll idx;

vector <ll> v[100005];
ll n, q, node, w, pre[100005], pos[100005], root, p[100005], bit[2][100005];
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

void updateBit(ll type, ll idx, ll x) {
    for (ll i = idx; i <= 100004; i += (i & -i)) {
        bit[type][i] += x;
    }
}

long long queryBit(ll type, ll idx) {
    ll ret = 0;
    for (ll i = idx; i ; i -= (i & -i)) {
        ret += bit[type][i];
        ret = ret % MOD;
    }
    return ret;
}

void update(ll l, ll r, ll x) {
    updateBit(0, l, x);
    long long tmp = ((-l * x) % MOD + x);
    updateBit(1, l, tmp);

    updateBit(0, r + 1, -x);
    updateBit(1, r + 1, (r * x) % MOD);
}

long long query(ll l, ll r) {
    long long ret = (queryBit(0, r) * r) % MOD;
    ret -= (queryBit(0, l - 1) * (l - 1)) % MOD;
    ret += queryBit(1, r);
    ret -= queryBit(1, l - 1);
    ret = ret % MOD;
    ret += MOD;
    ret = ret % MOD;
    return ret;
}

int main() {
    while(scanf("%lld%lld", &n, &q)) {
        if (n == 0 && q == 0) return 0;

        idx = 0;
        for (ll i = 0; i < n; i++) {
            v[i].clear();
        }

        for (ll i = 0; i <= 100000; i++) {
            bit[0][i] = bit[1][i] = 0;
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
                update(pre[node], pos[node], w);
            } else {
                scanf("%lld", &node);
                printf("%lld\n", query(pre[node], pos[node]));
            }
        }
        printf("\n");
    }
    return 0;
}
