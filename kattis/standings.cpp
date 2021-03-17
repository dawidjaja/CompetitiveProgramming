#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);

    while (tc--) {
        string s;
        int n, k;
        cin >> n;
        long long ans = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> s >> k;
            v[i] = k;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            ans += abs(v[i] - (i + 1));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
