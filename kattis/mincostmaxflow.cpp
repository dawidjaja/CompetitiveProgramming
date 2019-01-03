#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<long long,long long>
#define pip pair<long long,pii>

using namespace std;

const long long INF = INT_MAX;
long long prv[255], lvl[255], flow[255][255], cost[255][255], dist[255];
long long n, m, s, t, ans, money;
vector <long long> v[255];

bool findSP() {
    priority_queue <pip> pq;
    pq.push({0, {s, -2}});
    for (long long i = 0; i < n; i++) {
        prv[i] = -1;
        dist[i] = INF;
    }
    while (pq.size()) {
        long long co = -pq.top().fs;
        long long cur = pq.top().sc.fs;
        long long from = pq.top().sc.sc;
        pq.pop();
        if (prv[cur] == -1) {
            prv[cur] = from;
            for (long long i = 0; i < v[cur].size(); i++) {
                if (prv[v[cur][i]] == -1 && 
                        co + cost[cur][v[cur][i]] < dist[v[cur][i]] &&
                        flow[cur][v[cur][i]] > 0) {
                    dist[v[cur][i]] = co + cost[cur][v[cur][i]];
                    pq.push({-(co + cost[cur][v[cur][i]]), {v[cur][i], cur}});
                }
            }
        }
    }
    return prv[t] != -1;
}

long long findCap(long long x) {
    if (prv[x] < 0) return INF;
    return min(findCap(prv[x]), flow[prv[x]][x]);
}

int main() {
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    set <pii> hehe;
    for (long long i = 0; i < m; i++) {
        long long a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        assert(!hehe.count({a, b}));
        hehe.insert({a, b});
        flow[a][b] = c;
        cost[a][b] = d;
        cost[b][a] = -d;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while (findSP()) {
        long long tmp = t;
        long long cap = findCap(t);
        while (tmp != s) {
            flow[prv[tmp]][tmp] -= cap;
            flow[tmp][prv[tmp]] += cap;
            money += cap * cost[prv[tmp]][tmp];
            tmp = prv[tmp];
        }
        ans += cap;
    }
    printf("%lld %lld\n", ans, money);
    return 0;
}
