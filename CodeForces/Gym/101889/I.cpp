#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

#define fs first
#define sc second
#define pii pair<int,int>
#define pip pair<int,pii>

using namespace std;

int ds[100005], p[100005][21], low[100005], gde[100005][21], n, r;
map <int,int> price[100005];
vector <int> v[100005];
priority_queue <pip> pq;

int par(int x) {
    if (ds[x] == x)
        return x;
    return ds[x] = par(ds[x]);
}

void dfsFindPar(int cur, int prev) {
    low[cur] = low[prev] + 1;
    p[cur][0] = prev;
    if (price[min(cur, prev)].count(max(cur, prev))) {
        gde[cur][0] = price[min(cur, prev)][max(cur, prev)];
    }
    for (int i = 0; i < v[cur].size(); i++) {
        if (v[cur][i] != prev)
            dfsFindPar(v[cur][i], cur);
    }
}

void initLCA() {
    for(int j = 1; j <= 20; j++) {
        for(int i = 1; i <= n; i++) {
            int par = p[i][j - 1];
            if (par != -1) {
                p[i][j] = p[par][j - 1];
                gde[i][j] = max(gde[i][j - 1], gde[par][j - 1]);
            }
        }
    }
}

int findLCA(int a, int b) {
    if (low[a] < low[b]) {
        swap(a, b);
    }
    int ret = 0;
    for (int i = 20; i >= 0; i--) {
        int par = p[a][i];
        if (par != -1 && low[par] >= low[b]) {
            ret = max(ret, gde[a][i]);
            a = p[a][i];
        }
    }
    if (a == b) return ret;
    for(int i = 20; i >= 0; i--) {
        if (p[a][i] != -1 && p[a][i] != p[b][i]) {
            ret = max(ret, gde[a][i]);
            ret = max(ret, gde[b][i]);
            a = p[a][i];
            b = p[b][i];
        }
    }
    ret = max(ret, max(gde[a][0], gde[b][0]));
    return ret;
}

int main() {
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= r; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        pq.push({-c, {a, b}});
        price[min(a, b)][max(a, b)] = c;
    }
    for (int i = 0; i <= n; i++)
        ds[i] = i;
    memset(p, -1LL, sizeof(p));
    int startPrice = 0;
    int tEdge = 0;
    while (tEdge < n - 1 && pq.size()) {
        int cost = -pq.top().fs;
        int na = pq.top().sc.fs;
        int nb = pq.top().sc.sc;
        pq.pop();
        if (par(ds[na]) != par(ds[nb])) {
            ds[par(na)] = par(nb);
            startPrice += cost;
            v[na].push_back(nb);
            v[nb].push_back(na);
            tEdge++;
        }
    }
    dfsFindPar(1, 0);
    initLCA();
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", startPrice + price[min(x, y)][max(x, y)] - 
                findLCA(x, y));
    }
    return 0;
}

