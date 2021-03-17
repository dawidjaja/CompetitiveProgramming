#include<bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

int n, b, tt, cost[105], sp[1005][15000];
map<int, int> adl[1005];
pii s, t, coor[1005];
priority_queue <ppi> pq;

int dist(int x, int y) {
    pii a = coor[x];
    pii b = coor[y];
    return ceil(sqrt(pow(a.fs - b.fs, 2) +
                pow(a.sc - b.sc, 2)));
}



int main() {

    scanf("%d%d", &s.fs, &s.sc);
    scanf("%d%d", &t.fs, &t.sc);

    scanf("%d", &b); // dist limit

    scanf("%d", &cost[0]); // car cost

    scanf("%d", &tt);

    for (int i = 1; i <= tt; i++) {
        scanf("%d", &cost[i]);
    }

    scanf("%d", &n);

    coor[n] = s;
    coor[n + 1] = t;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &coor[i].fs, &coor[i].sc);
        int l;
        scanf("%d", &l);
        for (int j = 0; j < l; j++) {
            int a, b;
            scanf("%d%d", &a, &b);

            if (adl[i].count(a)) {
                adl[i][a] = min(adl[i][a], cost[b]);
                adl[a][i] = adl[i][a];
            } else {
                adl[i][a] = cost[b];
                adl[a][i] = cost[b];
            }
        }
        adl[i][n] = cost[0];
        adl[n][i] = cost[0];
        adl[i][n + 1] = cost[0];
        adl[n + 1][i] = cost[0];
    }
    adl[n][n + 1] = cost[0];
    adl[n + 1][n] = cost[0];

    int INF = b + 1;

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j < 150; j++) {
            sp[i][j] = INF * 105;
        }
    }

    sp[n][0] = 0;
    pq.push({{0, 0}, n});

    while (pq.size()) {
        int c, d, cur;
        c = -pq.top().fs.fs;
        d = -pq.top().fs.sc;
        cur = pq.top().sc;
        pq.pop();
        //printf("-- %d %d %d --\n", c, d, cur);

        if (cur == n + 1 && d <= b) {
            printf("%d\n", c);
            return 0;
        }

        if (sp[cur][d] >= c) {
            sp[cur][d] = c;
            for (auto it = adl[cur].begin(); it != adl[cur].end(); it++) {
                int nx = it->fs;
                int nc = it->sc;
                int nxDist = dist(nx, cur);
                int newCost = c + nc * nxDist;
                //printf("- loop - %d %d  && %d %d --\n", nx, nc, nxDist, newCost);
                if (d + nxDist <= b && 
                        sp[nx][d + nxDist] > newCost) {
                    sp[nx][d + nxDist] = newCost;
                    pq.push({{-newCost, -(d + nxDist)}, nx});
                }
            }
        }
    }

    printf("-1\n");
    return 0;
}
