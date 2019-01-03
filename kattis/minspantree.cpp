#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define pii pair<int,int>
#define pip pair<int,pii>
using namespace std;

int n, m, a, b, c, p[20005], ans, cek;
vector<pip> edge;
vector<pii> solu;

int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}

int main() {
    while (scanf("%d%d", &n, &m) && (n || m)) {
        edge.clear();
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            edge.push_back({c, {a, b}});
        }
        sort(edge.begin(), edge.end());
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        ans = 0;
        solu.clear();
        for (int i = 0; i < edge.size(); i++) {
            if (par(edge[i].sc.fs) != par(edge[i].sc.sc)) {
                solu.push_back({min(edge[i].sc.fs, edge[i].sc.sc),
                                max(edge[i].sc.fs, edge[i].sc.sc)});
                p[par(edge[i].sc.fs)] = par(edge[i].sc.sc);
                ans += edge[i].fs;
            }
        }
        cek = 1;
        for (int i = 1; i < n; i++) {
            if (par(i) != par(0)) {
                cek = 0;
            }
        }
        if (cek) {
            printf("%d\n", ans);
            sort(solu.begin(), solu.end());
            for (int i = 0; i < solu.size(); i++) {
                printf("%d %d\n", solu[i].fs, solu[i].sc);
            }
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
