#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long pwr(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long tmp = pwr(a, b / 2);
    tmp *= tmp;
    tmp = tmp % MOD;
    if (b & 1) {
        tmp *= a;
        tmp = tmp % MOD;
    }
    return tmp;
}

int main() {
    long long ans = 0;
    int n;
    scanf("%d", &n);
    vector<long long> x(n), carry(n);
    for (long long i = 0; i < n; i++) {
        long long xx;
        scanf("%lld", &xx);
        x[i] = xx;
        if (i != 0) {
            carry[i] = (carry[i - 1] + x[i - 1]) / 2;
        }
        //printf("carry %lld %lld\n", i, carry[i]);
    }
    long long debt = 0;
    for (long long i = n - 1; i >= 0; i--) {
        if (debt > x[i]) {
            debt -= x[i];
            x[i] = 0;
        } else {
            //debt < x[i]
            x[i] -= debt;
            debt = 0;
        }

        //printf("-- %lld %lld %lld --\n", i, debt, x[i]);

        x[i] %= 2;

        if (i != 0 && x[i] == 1) {
            if (carry[i - 1] + x[i - 1] >= 2) {
                debt = 1;
                x[i] = 0;
            }
        }
        if (x[i]) {
            ans += pwr(2, i);
            ans = ans % MOD;
        }
        debt *= 2;
    }

    printf("%lld\n", ans);

    return 0;
}
