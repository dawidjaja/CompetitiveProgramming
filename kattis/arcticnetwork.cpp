#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define pip pair<int,pii>

using namespace std;

int tc, s, n;
pii pts[505];
int p[505];

int par(int x) {
    return x == p[x] ? x : p[x] = par(p[x]);
}

int dist(int a, int b) {
    int c = pts[a].fs - pts[b].fs;
    int d = pts[a].sc - pts[b].sc;
    return c * c + d * d;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &s, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &pts[i].fs, &pts[i].sc);
            p[i] = i;
        }
        priority_queue <pip> pq;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pq.push({-dist(i, j), {i, j}});
            }
        }
        int ctr = n;
        int ans;
        while (ctr > s) {
            int dis = -pq.top().fs;
            int a = pq.top().sc.fs;
            int b = pq.top().sc.sc;
            pq.pop();
            if (par(a) != par(b)) {
                ctr--;
                p[par(a)] = par(b);
                ans = dis;
            }
        }
        printf("%.2lf\n", sqrt(ans));
    }
    return 0;
}
