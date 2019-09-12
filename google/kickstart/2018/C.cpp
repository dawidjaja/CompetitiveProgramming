#include <algorithm>
#include <cstdio>


using namespace std;

const long long MOD = 1000000007;
long long fact[100005], dua[100005];
long long pngmod[100005];
long long n, m;
int tc;

long long neg(int a) {
    if (a & 1) return -1;
    return 1;
}

long long pngkt(long long a, long long b) {
    if (b == 0) return 1;
    if (b & 1) return (a * pngkt(a, b - 1)) % MOD;
    long long tmp = pngkt(a, b / 2);
    return (tmp * tmp) % MOD;
}

long long combi(long long a, long long b) {
    long long ret = fact[a];
    ret *= pngmod[a - b];
    //ret *= pngkt(fact[a - b], MOD - 2);
    ret = ret % MOD;
    ret *= pngmod[b];
    //ret *= pngkt(fact[b], MOD - 2);
    ret = ret % MOD;
    return ret;
}

int main() {
    scanf("%d", &tc);
    fact[0] = 1;
    dua[0] = 1;
    pngmod[0] = pngkt(1, MOD-2);
    for (long long i = 1; i <= 100002; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        dua[i] = (dua[i - 1] * 2) % MOD;
        pngmod[i] = pngkt(fact[i], MOD - 2);
    }
    for (int _ = 1; _ <= tc; _++) {
        scanf("%lld%lld", &n, &m);
        long long ans = 0;
        for (long long i = 0; i <= m; i++) {
            ans += ((((neg(i) * fact[2 * n - i]) % MOD)
                    * dua[i]) % MOD 
                    * combi(m, i)) % MOD;
            ans = ans % MOD;
        }
        ans += MOD;
        ans = ans % MOD;
        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}

