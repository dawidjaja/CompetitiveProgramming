#include <algorithm>
#include <cstdio>

using namespace std;

int q;

int main() {
    scanf("%d", &q);
    while(q--) {
        long long n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        long long ans = k;
        long long tmp = min(n, m);
        k -= tmp;
        n -= tmp;
        m -= tmp;
        long long a = max(n, m);
        k -= (a - (a & 1LL));
        a &= 1LL;
        if (k < a) {
            printf("-1\n");
        } else if (a == 0) {
            if ((k & 1LL) == 1) {
                printf("%lld\n", ans - 2);
            } else {
                printf("%lld\n", ans);
            }
        } else if (a == 1) {
            printf("%lld\n", ans - 1);
        }
    }
    return 0;
}

