#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define fs first
#define sc second
#define pii pair<long long, long long>

using namespace std;

long long x, n, m, t, a, b, ctr, sp[1005], dp[1005][1005];
const long long INF = 1000000000000000009;
pii list[1005];
vector <long long> v[1005];
priority_queue <pii> pq;

long long f(long long cur, long long trem) {
    if (trem == 0) {
        if (cur == 1)
            return 0;
        return INF;
    }
    if (trem < 0) return INF;
    if (dp[cur][trem] != -1) return dp[cur][trem];
    long long &ret = dp[cur][trem];
    ret = list[cur].sc + f(cur, trem - list[cur].fs);
    for (unsigned int i = 0; i < v[cur].size(); i++) {
        ret = min(ret, min(INF, f(v[cur][i], trem - t - list[v[cur][i]].fs)
                        + list[v[cur][i]].sc));
    }
    return ret;
}

int main() {
    scanf("%lld", &x);
    scanf("%lld%lld%lld", &n, &m, &t);
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (long long i = 1; i <= n; i++) {
        scanf("%lld%lld", &list[i].fs, &list[i].sc);
        for (long long j = 0; j <= x; j++)
            dp[i][j] = -1;
    }
    /*
    pq.push({list[1].sc, 1});
    ctr = 0;
    while (pq.size() && ctr < n) {
        long long loc = pq.top().sc;
        long long val = -pq.top().fs;
        pq.pop();
        if (sp[loc] != -1) continue;
        ctr++;
        sp[loc] = val;
        for (unsigned long long i = 0; i < v[loc].size(); i++)
            if (sp[v[loc][i]] == -1) 
                pq.push({-(val + list[v[loc][i]].sc + t), v[loc][i]});
    }
    */
    long long ans = f(1, x - list[1].fs) + list[1].sc;
    if (ans >= INF) {
        printf("It is a trap.\n");
    } else {
        printf("%lld\n", ans);
    }
    return 0;
}
