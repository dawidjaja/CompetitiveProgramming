#include <bits/stdc++.h>

#define fs first
#define sc second
#define pid pair<int,double>
#define pdi pair<double,int>

using namespace std;

vector <pid> v[100005];
int vis[10005];
double dist[10005];
int n, m;

int main() {
    while (true) {
        scanf("%d%d", &n, &m);
        if (n == 0) return 0;
        for (int i = 0; i < n; i++) {
            v[i].clear();
            vis[i] = 0;
            dist[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            double c;
            scanf("%d%d%lf", &a, &b, &c);
            v[a].push_back({b, c});
        }
        priority_queue <pdi> pq;
        pq.push({1, 0});
        int cek = 1;
        while (pq.size()) {
            double sz = pq.top().fs;
            int cur = pq.top().sc;
            pq.pop();
            if (cur == n - 1) {
                printf("%.4lf\n", sz);
                cek = 0;
                break;
            }
            if (vis[cur] == 0) {
                vis[cur] = 1;
                for (int i = 0; i < v[cur].size(); i++) {
                    if (vis[v[cur][i].fs] == 0 && sz * v[cur][i].sc > dist[v[cur][i].fs]) {
                        dist[v[cur][i].fs] = sz * v[cur][i].sc;
                        pq.push({sz * v[cur][i].sc, v[cur][i].fs});
                    }
                }
            }
        }
        if (cek) {
            printf("1.0000\n");
        }
    }
}
