#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long pwr(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long tmp = pwr(a, b / 2);
    tmp = (tmp * tmp) % MOD;
    if (b & 1) {
        tmp *= a;
        tmp = tmp % MOD;
    }
    return tmp;
}

int main() {
    string a, b;
    while (true) {
        cin >> a;
        if (cin.eof()) {
            return 0;
        }
        cin >> b;
        long long n = a.length();
        long long m = b.length();
        long long hash = 0;
        long long curHash = 0;
        if (m < n) {
            printf("\n");
            continue;
        }
        for (long long i = n - 1; i >= 0; i--) {
            hash *= 300;
            hash += a[i];
            hash = hash % MOD;
            curHash *= 300;
            curHash += b[i];
            curHash = curHash % MOD;
        }
        long long first = 1;
        long long tmp = pwr(300, m);
        for (long long i = n; i < m; i++) {
            printf("-- %lld -- %lld -- %lld --\n", i - n, hash, curHash);
            if (curHash == hash) {
                if (!first) {
                    printf(" ");
                } else {
                    first = 0;
                }
                printf("%lld", i - n);
            }
            curHash = (curHash * pwr(300, MOD - 2)) % MOD; 
            curHash += b[i] * pwr(300, n - 1);
            curHash = curHash % MOD;
        }
        printf("-- %lld -- %lld -- %lld --\n", m - n, hash, curHash);
        if (hash == curHash) {
            if (!first) {
                printf(" ");
            }
            printf("%lld", m - n);
        }
        printf("\n");
    }
    return 0;
}
