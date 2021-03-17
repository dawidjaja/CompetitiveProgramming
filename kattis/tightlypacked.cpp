#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long l = ceil(sqrt(1.0 * n / 2));
    long long r = floor(sqrt(2 * n));
    long long ans = 1e18;
    for (long long i = l; i <= r; i++) {
        ans = min(ans, ((-n % i) + i) % i);
    }
    printf("%lld\n", ans);
}
