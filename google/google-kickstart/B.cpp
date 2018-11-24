#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n, ans, list[5000005];

int main() {
    int t;
    scanf("%d", &t);
    for (int _ = 1; _ <= t; _++) {
        ans = 0;
        scanf("%d", &n);
        int take = ceil(1.0 * n / 2);
        int maxi = 0;
        for (int i = 0; i < take; i++) {
            scanf("%1d", &list[i]);
            ans += list[i];
        }
        maxi = max(maxi, ans);
        for (int i = 0; i < n - take; i++) {
            scanf("%1d", &list[i + take]);
            ans -= list[i];
            ans += list[i + take];
            maxi = max(maxi, ans);
        }
        printf("Case #%d: %d\n", _, maxi);
    }
    return 0;
}
