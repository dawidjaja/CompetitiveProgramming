#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

int const INF = 1005;
int n, m, vis[505], ans, day[505];
vector<int> v[505];

int bfs(int src) {
    queue<pii> q;

    q.push({src, -1});
    vis[src] = 0;
    day[src] = src;

    int ret = INF;
    while (q.size()) {
        int cur = q.front().fs;
        int prv = q.front().sc;
        q.pop();
        //printf("-- bfs %d %d--\n", cur, vis[cur]);

        for (int nx: v[cur]) {
            if (nx == prv) continue;
            if (day[nx] != src) {
                day[nx] = src;
                vis[nx] = vis[cur] + 1;
                q.push({nx, cur});
            } else if (vis[cur] + vis[nx] + 1 > 2){
                ret = min(ret, vis[cur] + 1 + vis[nx]);
            }
        }
    }

    //printf("-- %d %d --\n", src, ret);
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        v[a].push_back(b);
        v[b].push_back(a);
    }

    ans = INF;
    vector<int> ord;
    for (int i = 0; i < n; i++) {
        day[i] = -1;
        ord.push_back(i);
    }
    //random_shuffle(ord.begin(), ord.end());
    for (int i: ord) {
        ans = min(ans, bfs(i));
    }
    if (ans == INF) {
        printf("impossible\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
