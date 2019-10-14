#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, m, p[10005], sz[10005], tc;
priority_queue<pii> pq;

int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}


int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
            pq.push({-1, i});
        }

        int ctr = 0;
        while (pq.size() && ctr < 2 * n) {
            int cur = pq.top().sc;
            int ts = -pq.top().fs;
            pq.pop();
            if (sz[par(cur)] == ts) {
                ctr++;
                printf("? %d\n", cur);
                fflush(stdout);

                int x;
                scanf("%d", &x);
                if (par(x) == par(cur)) {
                    pq.push({-sz[par(cur)], cur});
                    pq.push({-sz[par(cur)], x});
                } else {
                    sz[par(cur)] += sz[par(x)];
                    p[par(x)] = par(cur);
                    pq.push({-sz[par(cur)], cur});
                    pq.push({-sz[par(cur)], x});
                }
            }
        }

        int can = 1;
        for (int i = 2; i <= n; i++) {
            if (par(i) != par(1)) {
                can = 0;
            }
        }
        if (can) {
            printf("+\n");
        } else {
            printf("-\n");
        }
        fflush(stdout);
    }
}
