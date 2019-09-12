#include <bits/stdc++.h>

using namespace std;

int tc, n, p;
long long ans, skill[100005];

int main() {
    scanf("%d", &tc);
    for (int _ = 1; _ <= tc; _++) {
        scanf("%d%d", &n, &p);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &skill[i]);
        }
        sort(skill, skill + n);
        long long tmp = 0;
        for (int i = 0; i < p - 1; i++) {
            tmp += skill[p - 1] - skill[i];
        }
        //printf(" %lld\n", tmp);
        ans = tmp;
        for (int i = p; i < n; i++) {
            tmp += (skill[i] - skill[i - 1]) * (p - 1);
            tmp -= skill[i - 1] - skill[i - p];
            //printf("%lld -- %lld - %lld\n", skill[i], skill[i - p], tmp);
            ans = min(tmp, ans);
        }
        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}
