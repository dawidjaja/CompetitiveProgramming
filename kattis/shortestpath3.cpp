#include <algorithm>
#include <cstdio>
#include <vector>
#include <climits>
#include <queue>

#define fs first
#define sc second
#define pii pair<long long,long long>
#define ppi pair<pii,long long>

using namespace std;

int main() {
    long long cek = 0;
    const long long INF = (1LL << 62);
    while (true) {
        long long n, m, q, s, a, b, c;
        scanf("%lld%lld%lld%lld", &n, &m, &q, &s);
        vector<ppi> v;
        long long dist[1005], tmp[1005], vis[1005];
        if (cek == 1) {
            printf("\n");
        }
        cek = 1;
        if (n == 0 && m == 0 && s == 0 && q == 0) {
            return 0;
        }
        for (long long i = 0; i < n; i++) {
            dist[i] = INF;
            vis[i] = 0;
        }
        queue <long long> qu;
        dist[s] = 0;
        vector<long long> adj[1005];
        for (long long i = 0; i < m; i++) {
            scanf("%lld%lld%lld", &a, &b, &c);
            v.push_back({{a, b}, c});
            adj[a].push_back(b);
        }
        for (long long k = 0; k < n - 1; k++) {
            for (long long i = 0; i < v.size(); i++) {
                if (dist[v[i].fs.fs] != INF && dist[v[i].fs.fs] + v[i].sc < dist[v[i].fs.sc]) {
                    dist[v[i].fs.sc] = dist[v[i].fs.fs] + v[i].sc;
                }
            }
        }
        for (long long i = 0; i < n; i++) {
            tmp[i] = dist[i];
        }
        for (long long i = 0; i < v.size(); i++) {
            if (dist[v[i].fs.fs] != INF && dist[v[i].fs.fs] + v[i].sc < dist[v[i].fs.sc]) {
                qu.push(v[i].fs.sc);
            }
        }
        while (qu.size()) {
            int now = qu.front();
            qu.pop();
            if (vis[now] == 0) {
                vis[now] = 1;
                for (int i = 0; i < adj[now].size(); i++) {
                    if (vis[adj[now][i]] == 0) {
                        vis[adj[now][i]] = 1;
                        qu.push(adj[now][i]);
                    }
                }
            }
        }
        while (q--) {
            long long to;
            scanf("%lld", &to);
            if (vis[to] == 1) {
                printf("-Infinity\n");
            } else if (dist[to] == INF) {
                printf("Impossible\n");
            } else {
                printf("%lld\n", dist[to]);
            }
        }
    }
    return 0;
}
