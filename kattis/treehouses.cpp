#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define pip pair<int,pii>
#define pdd pair<double,double>
#define pdp pair<double,pii>

using namespace std;

double ans = 0;
pdd pts[1005];
int n, e, p[1005], pp;
vector <pdp> v;

double dist(int a, int b) {
    return hypot(pts[a].fs - pts[b].fs, pts[a].sc - pts[b].sc);
}

int par(int x) {
    return p[x] == x ? x : (p[x] = par(p[x]));
}



int main() {
    scanf("%d%d%d", &n, &e, &pp);
    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        pts[i] = {x, y};
        p[i] = i;
    }

    for (int i = 0; i < e; i++) {
        p[i] = 0;
    }

    for (int i = 0; i < pp; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        p[par(a)] = par(b);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            v.push_back({dist(i, j), {i, j}});
        }
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        int a, b;
        a = v[i].sc.fs;
        b = v[i].sc.sc;
        double x = v[i].fs;

        if (par(a) != par(b)) {
            p[par(a)] = par(b);
            ans += x;
        }
    }
    printf("%.6lf\n", ans);
    return 0;
}
