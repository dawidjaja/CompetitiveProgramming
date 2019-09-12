#include<bits/stdc++.h>

using namespace std;

long long n;

int main() {
    while (scanf("%lld", &n) && n) {
        vector<long long> factors;
        for (long long i = 2; i * i <= abs(n); i++) {
            long long cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            factors.push_back(cnt);
        }
        if (abs(n) != 1)
            factors.push_back(1);
        long long cur = 0;
        for (long long factor: factors)
            cur = __gcd(cur, factor);
        while (n < 0 && cur % 2 == 0)
            cur /= 2;
        printf("%lld\n", cur ? : 1LL);
    }
}
