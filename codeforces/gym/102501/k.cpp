#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, m, t;
vector<int> v[100005];
pii vis[100005];
queue<pii> q;

bool can(pii &a, int cur, int src) {
    if (a.fs == src || a.sc == src) return false;
    if (a.fs == -1) {
        a.fs = src;
        return true;
    } 
    if (a.sc == -1) {
        a.sc = src;
        return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        vis[i] = {-1, -1};
    }

    for (int i = 0; i < v[t].size(); i++) {
        vis[v[t][i]] = {v[t][i], -1};
        q.push({v[t][i], v[t][i]});
    }

    while (q.size()) {
        int cur = q.front().fs;
        int src = q.front().sc;
        q.pop();

        //printf("-- %d %d --\n", cur, src);

        for (int i = 0; i < v[cur].size(); i++) {
            if (v[cur][i] == t) continue;
            //printf("-- -- %d %d - %d %d--\n", cur, v[cur][i], 
                    //vis[v[cur][i]].fs, vis[v[cur][i]].sc);
            if (can(vis[v[cur][i]], v[cur][i], src)) {
                q.push({v[cur][i], src});
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < v[t].size(); i++) {
        if (vis[v[t][i]].sc == -1) {
            ans.push_back(v[t][i]);
        }
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
