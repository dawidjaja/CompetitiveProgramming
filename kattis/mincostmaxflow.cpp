#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<long long,long long>
#define pip pair<long long,pii>
#define piip pair<long long,pip>
#define piiip pair<long long,piip>

using namespace std;

const long long INF = INT_MAX;
long long flow[2][255][255], cost[2][255][255], dist[255];
long long n, m, s, t, ans, money;
pii prv[255];
vector <long long> v[255];

int id(int a, int b) {
    return a < b ? 0 : 1;
}

bool findSP() {
    priority_queue <piip> pq;
    pq.push({0, {s, {-2, -2}}});
    for (long long i = 0; i < n; i++) {
        prv[i] = {-1, -1};
        dist[i] = INF;
    }
    while (pq.size()) {
        long long co = -pq.top().fs;
        long long cur = pq.top().sc.fs;
        pii from = pq.top().sc.sc;
        pq.pop();
        if (prv[cur].fs == -1) {
            prv[cur] = from;
            for (long long i = 0; i < v[cur].size(); i++) {
                for (int j = 0; j < 2; j++) {
                    if (prv[v[cur][i]].fs == -1 && 
                            co + cost[j][cur][v[cur][i]] < dist[v[cur][i]] &&
                            flow[j][cur][v[cur][i]] > 0) {
                        dist[v[cur][i]] = co + cost[j][cur][v[cur][i]];
                        pq.push({-(co + cost[j][cur][v[cur][i]]), {v[cur][i], {cur, j}}});
                    }
                }
            }
        }
    }
    return prv[t].fs != -1;
}

long long findCap(long long x) {
    if (prv[x].fs < 0) return INF;
    return min(findCap(prv[x].fs), flow[prv[x].sc][prv[x].fs][x]);
}

int main() {
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    set <pii> hehe;
    for (long long i = 0; i < m; i++) {
        long long a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        assert(!hehe.count({a, b}));
        //assert(!hehe.count({b, a}));
        hehe.insert({a, b});
        flow[id(a, b)][a][b] = c;
        cost[id(a, b)][a][b] = d;
        cost[id(a, b)][b][a] = -d;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while (findSP()) {
        long long tmp = t;
        long long cap = findCap(t);
        while (tmp != s) {
            printf("-- %lld %lld -- \n", tmp, cost[prv[tmp].sc][prv[tmp].fs][tmp]);
            flow[prv[tmp].sc][prv[tmp].fs][tmp] -= cap;
            flow[prv[tmp].sc][tmp][prv[tmp].fs] += cap;
            money += cap * cost[prv[tmp].sc][prv[tmp].fs][tmp];
            tmp = prv[tmp].fs;
        }
        printf("\n");
        ans += cap;
    }
    printf("%lld %lld\n", ans, money);
    return 0;
}
