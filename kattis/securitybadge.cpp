#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define pip pair<int,pii>

using namespace std;

int n, l, b, s, d;
pii lim[1005];
queue <int> q;
vector <pip> v[1005];

int main() {
    scanf("%d%d%d", &n, &l, &b);
    scanf("%d%d", &s, &d);
    for (int i = 0; i < l; i++) {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        v[a].push_back({b, {x, y}});
    }

    for (int i = 0; i <= n; i++) {
        random_shuffle(v[i].begin(), v[i].end());
        lim[i] = {1000000005, 0};
    }

    q.push(s);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int lo, hi, nx;
            nx = v[cur][i].fs;
            lo = v[cur][i].sc.fs;
            hi = v[cur][i].sc.sc;

            if (lo < lim[nx].fs || lim[nx].sc < hi) {
                lim[nx].fs = min(lo, lim[nx].fs);
                lim[nx].sc = max(hi, lim[nx].sc);
                q.push(nx);
            }
        }
    }
    printf("%d\n", lim[d].sc - lim[d].fs + 1);
    return 0;
}
