#include <algorithm>
#include <cstdio>

using namespace std;

long long n, m, l, k, tc, list[100005], wait, ans;

int main() {
    scanf("%lld", &tc);
    while (tc--) {
        scanf("%lld%lld%lld%lld", &n, &m, &k, &l);
        for (long long i = 0; i < n; i++) {
            scanf("%lld", &list[i]);
        }
        sort(list, list + n);
        ans = 0;
        wait = l * m + l;
        for (long long i = 0; i < n; i++) {
            if (max(0LL, l * (m + i + 1) - list[i]) < wait) {
                wait = max(l * (m + i + 1) - list[i], 0LL);
                ans = list[i];
            }
        }
        if (max(0LL, l * (m + n + 1) - k) < wait) {
            wait = max(0LL, l * (m + n + 1) - k);
            ans = k;
        }
        printf("%lld\n", wait);
    }
    return 0;
}

