#include <bits/stdc++.h>

using namespace std;

long long tc, n, s[100005], ans;

int main() {
    scanf("%lld", &tc);
    while (tc--) {
        scanf("%lld", &n);
        for (long long i = 0; i < n; i++) {
            long long w;
            scanf("%lld", &w);
            s[i] = 0;
            while (w--) {
                long long x;
                scanf("%lld", &x);
                s[i] += x;
            }
        }
        sort(s, s + n);
        long long tmp = 0;
        ans = 0;
        for (long long i = 0; i < n; i++) {
            tmp += s[i];
            ans += tmp;
        }
        printf("%lf\n", 1.0 * ans / n);
    }
    return 0;
}
