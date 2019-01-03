#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

const int INF = 1e9;
bool first = true;
vector <pii> v[10005];
int n, m, q, s, sp[10005], vis[10005];

inline void findSP() {
    priority_queue <pii> pq;
    pq.push({0, s});
    while (pq.size()) {
        int dis = -pq.top().fs;
        int cur = pq.top().sc;
        pq.pop();
        if (vis[cur] == 0) {
            //printf("-- %d %d --\n", cur, dis);
            vis[cur] = 1;
            for (int i = 0; i < v[cur].size(); i++) {
                if (vis[v[cur][i].fs] == 0 && 
                        dis + v[cur][i].sc < sp[v[cur][i].fs]) {
                    sp[v[cur][i].fs] = dis + v[cur][i].sc;
                    pq.push({-sp[v[cur][i].fs], v[cur][i].fs});
                }
            }
        }
    }
}

int main() {
    while (true) {
        scanf("%d%d%d%d", &n, &m, &q, &s);
        if (n + m + q + s == 0) {
            return 0;
        }
        if (!first) {
            printf("\n");
        }
        first = false;
        for (int i = 0; i < n; i++) {
            sp[i] = INF;
            vis[i] = 0;
            v[i].clear();
        }
        sp[s] = 0;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            v[a].push_back({b, c});
        }
        findSP();
        while (q--) {
            int x;
            scanf("%d", &x);
            if (sp[x] == INF) {
                printf("Impossible\n");
            } else {
                printf("%d\n", sp[x]);
            }
        }
    }
}
