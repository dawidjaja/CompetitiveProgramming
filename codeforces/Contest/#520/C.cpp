#include <algorithm>
#include <cstdio>

#define MOD 1000000007

using namespace std;

long long nol[100005], satu[100005], l, r, n, q;
int list[100005];

long long getNol(long long l, long long r) {
    return nol[r] - nol[l - 1];
}

long long getSatu(long long l, long long r) {
    return satu[r] - satu[l - 1];
}

long long pngkt(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return (a * pngkt(a, b - 1)) % MOD;
    long long tmp = pngkt(a, b / 2);
    tmp *= tmp;
    tmp = tmp % MOD;
    return tmp;
}

int main() {
    scanf("%lld%lld", &n, &q);
    for (long long i = 1; i <= n; i++) {
        scanf("%1d", &list[i]);
        nol[i] = nol[i - 1];
        satu[i] = satu[i - 1];
        if (list[i] == 0) {
            nol[i]++;
        } else {
            satu[i]++;
        }
    }
    while (q--) {
        scanf("%lld%lld", &l, &r);
        long long ones = getSatu(l, r);
        long long zero = getNol(l, r);
        long long ans = pngkt(2, ones) - 1;
        ans += (ans * (pngkt(2, zero) - 1)) % MOD;
        ans = ans % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
