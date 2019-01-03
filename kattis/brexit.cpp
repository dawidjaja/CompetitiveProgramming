#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <int> v[200005];
queue <int> q;
int n, m, x, l, a, b, out[200005], vis[200005];

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &l);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(l);
    while (q.size()) {
        int now = q.front();
        vis[now] = 1;
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            out[v[now][i]]++;
            int neighbor = v[v[now][i]].size();
            if (vis[v[now][i]] == 0 &&
                    out[v[now][i]] == neighbor / 2 + (neighbor & 1)) {
                q.push(v[now][i]);
            }
        }
    }
    if (vis[x] == 1) {
        printf("leave\n");
    } else {
        printf("stay\n");
    }
    return 0;
}

