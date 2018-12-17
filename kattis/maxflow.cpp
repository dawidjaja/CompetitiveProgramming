#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int ans, flow[505][505], n, m, s, t, lvl[505], prv[505], start[505][505];
vector <pii> edge;
vector <int> v[505];

bool make_level() {
    queue<pii> q;
    for (int i = 0; i < n; i++) {
        lvl[i] = -1;
        prv[i] = -1;
    }
    q.push({s, 0});
    lvl[s] = 0;
    while (q.size()) {
        int now = q.front().fs;
        int depth = q.front().sc;
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            if (lvl[v[now][i]] == -1 && flow[now][v[now][i]] > 0) {
                lvl[v[now][i]] = depth + 1;
                q.push({v[now][i], depth + 1});
            }
        }
    }
    return lvl[t] != -1;
}

int getFlow(int now) {
    //printf("-- %d %d -> %d\n", prv[now], now, flow[prv[now]][now]);
    if (prv[now] == s)
        return flow[s][now];

    return min(getFlow(prv[now]), flow[prv[now]][now]);
}

void dfs(int now) {
    if (now == t) {
         int cap = getFlow(t);
         int cur = t;
         //printf("cap = %d\n", cap);
         while (cur != s) {
              flow[prv[cur]][cur] -= cap;
              flow[cur][prv[cur]] += cap;
              //printf("-- %d %d --\n", prv[cur], cur);
              cur = prv[cur];
         }
         ans += cap;
         return;
    }

    for (int i = 0; i < v[now].size(); i++) {
        if (lvl[now] + 1 == lvl[v[now][i]] &&
                flow[now][v[now][i]] > 0) {
            prv[v[now][i]] = now;
            dfs(v[now][i]);
        }
    }
}

int find() {
    int ret = 0;
    for (int i = 0; i < edge.size(); i++) {
        int a, b;
        a = edge[i].fs;
        b = edge[i].sc;
        if (flow[a][b] < start[a][b]) {
            ret++;
        }
        if (flow[b][a] < start[b][a]) {
            ret++;
        }
    }
    return ret;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (flow[a][b] == 0 && flow[b][a] == 0) {
            v[a].push_back(b);
            v[b].push_back(a);
            edge.push_back({a, b});
        }
        flow[a][b] += c;
        start[a][b] += c;
    }
    while (make_level()) {
        //dinic's
        dfs(s);
    }
    printf("%d %d %d\n", n, ans, find());
    for (int i = 0; i < edge.size(); i++) {
        int a, b;
        a = edge[i].fs;
        b = edge[i].sc;
        if (flow[a][b] < start[a][b]) {
            printf("%d %d %d\n", a, b, start[a][b] - flow[a][b]);
        }
        if (flow[b][a] < start[b][a]) {
            printf("%d %d %d\n", b, a, start[b][a] - flow[b][a]);
        }
    }
    return 0;
}
