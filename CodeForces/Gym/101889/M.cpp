#include <algorithm>
#include <cstdio>
#include <queue>
#include <assert.h>
#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

long long n, k, ans, mult, tsf[400005], ttl;
const long long MOD = 1000000007;
priority_queue <pii> pq;
queue <long long> q[100005];

int main() {
    ttl = 0;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &k);
        ttl += k;
        for (long long j = 1; j <= k; j++) {
            long long x;
            scanf("%lld", &x);
            if (j == 1) {
                pq.push({-x, i});
            } else {
                q[i].push(x);
            }
        }
    }
    tsf[0] = 1;
    for (long long i = 1; i <= ttl; i++) {
        tsf[i] = (tsf[i - 1] * 365) % MOD;
    }
    while (pq.size()) {
        long long val = -pq.top().fs;
        long long idx = pq.top().sc;
        pq.pop();
        if (q[idx].size()) {
            pq.push({-q[idx].front(), idx});
            q[idx].pop();
        }
        ans += (tsf[ttl--] * val) % MOD;
        ans = ans % MOD;
    }
    assert(ttl == 0);
    printf("%lld\n", ans);
	return 0;
}
