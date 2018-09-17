#include <algorithm>
#include <cstdio>

using namespace std;

long long n, a[300005], b[300005], l, r, m, ans;

int main() {
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &m);
    for (long long i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    long long tota, totb;
    tota = a[0];
    totb = b[0];
    l = 1;
    r = 1;
    while ((l <= n || r <= m) && l <= n + 1 && r <= m + 1) {
        if (tota < totb) {
            tota += a[l++];
        } else if (tota > totb) {
            totb += b[r++];
        } else if (tota == totb) {
            ans++;
            tota = a[l++];
            totb = b[r++];
        }
    }
    if (tota == totb && l == n + 1 && r == m + 1) {
        printf("%lld\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}
