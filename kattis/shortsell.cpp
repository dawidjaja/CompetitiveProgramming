#include <bits/stdc++.h>

using namespace std;

int n, k, price[100005], ans;

int main() {

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
        price[i] *= 100;
        price[i] += i * k;
    }

    int tmp = price[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans, price[i] - tmp);
        tmp = min(tmp, price[i]);
    }

    ans -= k;
    ans = max(0, ans);

    printf("%d\n", ans);
    return 0;
}
