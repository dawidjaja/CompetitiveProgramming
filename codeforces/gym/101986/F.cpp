#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

#define fs first
#define sc second
#define pii pair<long long,long long>
#define ppi pair<pii,long long>
#define pip pair<long long,pii>

using namespace std;

const long long INF = 1ll << 60;

priority_queue <ppi> pq;
long long sp[2][100005][2], vis[100005], from[2][100005][2];
ppi list[100005];
vector<pip> v[2][100005];
long long n, m, a, b, c;
set<long long> s;

void shortestPath(long long x) {
    if (x == 0) {
        vis[1] = 1;
        sp[0][1][0] = 0;
        sp[0][1][1] = 0;
        pq.push({{0, 1}, -1});
    } else {
        sp[1][2][0] = 0;
        sp[1][2][1] = 0;
        pq.push({{0, 2}, -1});
        for (long long i = 1; i <= n; i++) vis[i] = 0;
        vis[2] = 1;
    }
    while (pq.size()) {
        long long len = -pq.top().fs.fs;
        long long cur = pq.top().fs.sc;
        long long frm = pq.top().sc;
        pq.pop();
        if (vis[cur] < 2) {
            from[x][cur][vis[cur]] = frm;
            sp[x][cur][vis[cur]] = len;
            vis[cur]++;
            for (long long i = 0; i < v[x][cur].size(); i++) {
                if (len + v[x][cur][i].sc.fs < sp[x][v[x][cur][i].fs][1]) {
                    sp[x][v[x][cur][i].fs][1] = len + v[x][cur][i].sc.fs;
                    pq.push({{-len - v[x][cur][i].sc.fs, v[x][cur][i].fs}, 
                            v[x][cur][i].sc.sc});
                }
            }
        }
    }
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        list[i] = {{a, b}, c};
        v[0][a].push_back({b, {c, i}});
        v[1][b].push_back({a, {c, i}});
    }
    for (long long i = 1; i <= n; i++) {
        sp[0][i][0] = INF;
        sp[0][i][1] = INF;
        sp[1][i][0] = INF;
        sp[1][i][1] = INF;
        from[0][i][0] = -1;
        from[0][i][1] = -1;
        from[1][i][0] = -1;
        from[1][i][1] = -1;
        vis[i] = 0;
    }

    shortestPath(0);
    shortestPath(1);

    long long tmp = 2;
    while (tmp > 1) {
        s.insert(from[0][tmp][0]);
        tmp = list[from[0][tmp][0]].fs.fs;
    }

    for (long long i = 0; i < m; i++) {
        long long x = list[i].fs.fs;
        long long y = list[i].fs.sc;
        long long z = list[i].sc;
        long long dpn, blkg;
        long long ans;
        if (from[0][y][0] == i) {
            dpn = sp[0][y][1];
        } else {
            dpn = sp[0][y][0];
        }
        if (from[1][x][0] == i) {
            blkg = sp[1][x][1];
        } else {
            blkg = sp[1][x][0];
        }
        ans = dpn + blkg + z;
        if (s.count(i) && ans > sp[0][2][0]) {
            printf("SAD\n");
        } else if (ans < sp[0][2][0]) {
            printf("HAPPY\n");
        } else {
            printf("SOSO\n");
        }
    }
    return 0;
}
