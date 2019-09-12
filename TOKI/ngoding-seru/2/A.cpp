#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
long long cnt, lastSec, ans, n, m, last[100005];

long long pngkt(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b & 1) return (pngkt(a, b - 1) * a) % MOD;
    long long tmp = pngkt(a, b / 2);
    return (tmp * tmp) % MOD;
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (long long i = 0; i < m; i++) {
        scanf("%lld", &last[i]);
    }
    sort(last, last + m);
    cnt = m;
    lastSec = 0;
    ans = 1;
    for (long long i = 0; i < m; i++) {
        if (last[i] == 0) {
            cnt--;
            continue;
        }
        ans *= pngkt(cnt, last[i] - 1 - lastSec);
        ans = ans % MOD;
        lastSec = last[i];
        cnt--;
    }
    printf("%lld\n", ans);
    return 0;
}
