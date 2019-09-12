#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

const int INF = 1000000005, MAXE = 10005;
int source, sink, p, r, c, e[1005], d[1005], work[2500], dist[2500], a, b, t, q[10005];
vector <ppi> allEdges;

struct edge{
    int to, rev;
    int flow, cap;
};
vector <edge> G[MAXE];

inline void add(int s, int t, int cap) {
    edge a = {t, G[t].size(), 0, cap};
    edge b = {s, G[s].size(), 0, 0};
    G[s].push_back(a);
    G[t].push_back(b);
}

inline bool search() {
    for(int i = 0; i <= r + p + 1; i++) dist[i] = -1;
    dist[source] = 0;
    int tail = 0;
    q[tail] = source;
    for(int head = 0; head <= tail; head++) {
        int u = q[head];
        int sz = G[u].size();
        for(int i = 0; i < sz; i++) {
            int v = G[u][i].to;
            if (dist[v] < 0 && G[u][i].flow < G[u][i].cap) {
                dist[v] = dist[u] + 1;
                q[++tail] = v;
            }
        }
    }
    return dist[sink] >= 0;
}

int dinic(int now, int flo) {
    if (now == sink)
        return flo;
    int size = G[now].size();
    for(int &i = work[now]; i < size; i++) {
        int to = G[now][i].to;
        int flow = G[now][i].flow;
        int cap = G[now][i].cap;
        int rev = G[now][i].rev;
        if (flow >= cap) continue;
        if (dist[to] == dist[now] + 1) {
            int fflow = dinic(to, min(flo, cap - flow));
            if (fflow) {
                G[now][i].flow += fflow;
                G[to][rev].flow -= fflow;
                return fflow;
            }
        }
    }
    return 0;
}

inline int maxflow() {
    int ans = 0;
    while(search()) {
        for(int i = 0; i <= r + p + 1; i++) work[i] = 0;
        while(true) {
            int res = dinic(source, INF);
            if (res == 0) break;
            ans += res;
        }
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &p, &r, &c);
    int target = 0;
    for (int i = 0; i < p; i++) {
        scanf("%d", &d[i]);
        target += e[i];
    }
    for (int i = 0; i < r; i++) {
        scanf("%d", &e[i]);
    }
    for (int i = 0; i < c; i++) {
        scanf("%d%d%d", &a, &b, &t);
        allEdges.push_back({{a, b}, t});
    }

    int l = 1, r = 1000001;
    source = 0;
    sink = r + p + 1;
    while (l < r) {
        int piv = (l + r) >> 1;
        for (int i = 0; i < MAXE; i++) {
            G[i].clear();
        }
        for (int i = 1; i <= r; i++) {
            add(source, i, e[i]);
        }

        for (int i = 1; i <= p; i++) {
            add(r + i, sink, d[i]);
        }

        for (int i = 0; i < allEdges.size(); i++) {
            if (allEdges[i].sc <= piv) {
                add(allEdges[i].fs.sc, allEdges[i].fs.fs, 10005);
            }
        }

        int tmp = maxflow();
        // printf("-- %d --\n", tmp);
        if (tmp == target) {
            r = piv;
        } else {
            l = piv + 1;
        }
    }
    if (r == 1000001) {
        printf("-1\n");
    } else {
        printf("%d\n", r);
    }

    return 0;
}
