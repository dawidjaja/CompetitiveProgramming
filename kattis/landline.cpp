#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define pip pair<int,pii>

using namespace std;

int p[1005], n, m, pp, insec[1005], con[1005];
vector<pip> edge, next_e;
int ans = 0;

int par(int x) {
    //if (p[x] == x) return x;
    //return p[x] = par(p[x]);
    return p[x] == x ? x : (p[x] = par(p[x]));
}

int main() {
    scanf("%d%d%d", &n, &m, &pp);
    
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < pp; i++) {
        int x;
        scanf("%d", &x);
        insec[x] = 1;
    }

    for (int i = 0; i < m; i++) {
        int x, y, l;
        scanf("%d%d%d", &x, &y, &l);
        edge.push_back({l, {x, y}});
    }

    if (n == pp) {
        if (n == 2 && m == 1) {
            ans += edge[0].fs;
            printf("%d\n", ans);
        } else if (n == 1) {
            printf("0\n");
        } else {
            printf("impossible\n");
        }
        return 0;
    }

    sort(edge.begin(), edge.end());

    for (int i = 0; i < edge.size(); i++) {
        int a, b, l;
        l = edge[i].fs;
        a = edge[i].sc.fs;
        b = edge[i].sc.sc;
        
        if (!insec[a] && !insec[b] && par(a) != par(b)) {
            p[par(a)] = par(b);
            ans += l;
        } else if (insec[a] + insec[b] == 1) {
            next_e.push_back(edge[i]);
        }
    }

    for (int i = 0; i < next_e.size(); i++) {
        int a, b, l;
        l = next_e[i].fs;
        a = next_e[i].sc.fs;
        b = next_e[i].sc.sc;
        
        if (((insec[a] && con[a] == 0) ||
            (insec[b] && con[b] == 0)) &&
            par(a) != par(b)) {
            p[par(a)] = par(b);
            con[a] = con[b] = 1;
            ans += l;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (par(i) != par(1)) {
            printf("impossible\n");
            return 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
