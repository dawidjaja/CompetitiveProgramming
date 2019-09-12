#include <algorithm>
#include <cstdio>

using namespace std;

long long n, m, c, ans;
const long long MOD = 1000000007;

long long pwr(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long tmp = pwr(a, b / 2);
    tmp *= tmp;
    tmp = tmp % MOD;
    if (b & 1) 
        tmp = (tmp * a) % MOD;
    return tmp;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%lld%lld%lld", &n, &m, &c);
    for (long long i = 1; i <= m; i++) {
        long long tmp = gcd(i, m);
        ans += pwr(c, tmp * n * n);
        ans = ans % MOD;
    }
    ans *= pwr(m, MOD - 2);
    ans = ans % MOD;
    printf("%lld\n", ans);
    return 0;
}
