#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <iostream>
#include <bitset>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int dp[100005], ds[100005];
int n;
pii list[100005];
vector<pii> v[100005];
map<pii, int> pid;

int par(int x) {
    if (ds[x] == x) return x;
    return ds[x] = par(ds[x]);
}

int f(int mask) {
    /*
    bitset<16> x(mask);
    cout << x;
    printf(" %d\n", dp[mask]);*/
    if (mask == 0) return 0;
    int &ret = dp[mask];
    if (ret != -1) return ret;
    int lsb = (mask & -mask);
    int tmp = 0;
    lsb >>= 1;
    while (lsb) {
        tmp++;
        lsb >>= 1;
    }
    //printf("--> %d %d\n", lsb, tmp);
    for (int i = 0; i < n; i++) {
        if (i != tmp && (mask & (1 << i))) {
            int pr = par(min(i, tmp) * n + max(i, tmp));
            //printf("loop %d %d %d %d\n", i, tmp, pr, v[pr].size());
            int newmask = mask;
            int tmbh = 0;
            for (int j = 0; j < v[pr].size(); j++) {
                if ((mask & (1 << v[pr][j].fs)) && (mask & (1 << v[pr][j].sc))) {
                    /*
                    bitset<16> x(newmask);
                    cout << x;
                    printf("matiin %d %d\n", v[pr][j].fs, v[pr][j].sc);
                    */
                    newmask &= ~(1 << v[pr][j].fs);
                    newmask &= ~(1 << v[pr][j].sc);
                    /*
                    bitset<16> ee(newmask);
                    cout << ee << endl;
                    */
                    tmbh++;
                }
            }
            if (tmbh != 0) {
                int tmp = (tmbh * (tmbh - 1)) / 2;
                tmp += f(newmask);
                ret = max(ret, tmp);
            }
        }
    }
    return ret;
}

pii grad(int a, int b) {
    int y = list[a].sc - list[b].sc;
    int x = list[a].fs - list[b].fs;
    if (x == 0 || y == 0) {
        if (x == 0) {
            y = 3000;
        } else {
            x = 3000;
        }
        return {y, x};
    } else {
        int tmp = __gcd(abs(y), abs(x));
        if (y < 0 && x < 0) {
            y = -y;
            x = -x;
        }
        return {y / tmp, x / tmp};
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &list[i].fs, &list[i].sc);
    }
    int tmp = (1 << n);
    for (int i = 0; i < n * n; i++) {
        ds[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pii m = grad(i, j);
            //printf("%d %d -- %d %d\n", i, j, m.fs, m.sc);
            int cur = i * n + j;
            if (pid.count(m)) {
                v[par(pid[m])].push_back({i, j});
                //printf("add edge %d -> %d %d\n", par(pid[m]), i, j);
                ds[par(cur)] = par(pid[m]);
            } else {
                pid[m] = par(cur);
                v[par(cur)].push_back({i, j});
                //printf("edge %d -> %d %d\n", par(cur), i, j);
            }
        }
    }
    /*
    for (int i = 0; i < n * n; i++) {
        printf("%d %d\n", i, v[i].size());
        for (int j = 0; j < v[i].size(); j++) {
            printf("   %d %d\n", v[i][j].fs, v[i][j].sc);
        }
    }
    */
    for (int i = 0; i < tmp; i++) {
        dp[i] = -1;
    }
    int ans = f((1 << n) - 1);
    printf("%d\n", ans);
    return 0;
}
