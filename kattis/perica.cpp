#include <bits/stdc++.h>

#define vi vector<long long>

using namespace std;

const long long MOD = 1e9 + 7;

bool cmp(long long a, long long b) {
    return a > b;
}

long long pwr(long long a, long long b) {
    if (b == 1) return a;
    if (b == 0) return 1;
    long long ret = pwr(a, b / 2);
    ret *= ret;
    ret = ret % MOD;
    if (b & 1) {
        ret *= a;
        ret = ret % MOD;
    }
    return ret;
}

int main() {
    long long n, k;
    long long ans = 0;
    scanf("%lld%lld", &n, &k);
    vi a(n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a.begin(), a.end());

    long long cur = 1;
    for (long long i = k - 1; i < n; i++) {
        ans += (a[i] * cur) % MOD;
        ans = ans % MOD;

        cur *= (i + 1);
        cur = cur % MOD;
        cur *= pwr(i + 2 - k, MOD - 2);
        cur = cur % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
