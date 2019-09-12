#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, m, a, b, sedge[505][505], sdeg[505], edge[505][505], curDeg[505];

int can(int x) {
    priority_queue<pii> pq;

    for (int i = 1; i <= n; i++) {
        curDeg[i] = sdeg[i];
        pq.push({curDeg[i], i});
        for (int j = 1; j <= n; j++) {
            edge[i][j] = sedge[i][j];
        }
    }

    int tot = m;
    while (pq.size()) {
        int degree = pq.top().fs;
        int cur = pq.top().sc;
        pq.pop();
        if (degree == curDeg[cur]) {
            vector<pii> neigh;
            for (int i = 1; i <= n; i++) {
                if (i != cur && edge[cur][i] == 0) {
                    neigh.push_back({curDeg[i], i});
                }
            }

            sort(neigh.begin(), neigh.end());

            for (int i = neigh.size() - 1; i >= 0; i--) {
                if (neigh[i].fs + curDeg[cur] >= x) {
                    edge[cur][neigh[i].sc] = edge[neigh[i].sc][cur] = 1;
                    curDeg[cur]++;
                    curDeg[neigh[i].sc]++;
                    tot++;
                    pq.push({curDeg[neigh[i].sc], neigh[i].sc});
                }
            }
        }
    }
    if (tot == n * (n - 1) / 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        sedge[a][b] = 1;
        sedge[b][a] = 1;
        sdeg[a]++;
        sdeg[b]++;
    }
    int l = 0;
    int r = 2 * n;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (can(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", l);
    return 0;
}
