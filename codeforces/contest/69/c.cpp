#include <bits/stdc++.h>

using namespace std;

int n, k, a[300005], ans;
vector <int> v;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        v.push_back(a[i] - a[i - 1]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - k; i++) {
        ans += v[i];
    }

    printf("%d\n", ans);
    return 0;
}
