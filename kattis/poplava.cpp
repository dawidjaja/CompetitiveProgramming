#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, x;

int main() {
    scanf("%lld%lld", &n, &x);
    ll ttl = (n - 2) * (n - 1) / 2;
    if (x > ttl) {
        printf("-1\n");
        return 0;
    }
    printf("%lld", n);
    vector <int> v;
    for (int i = 1; i <= n - 2; i++) {
        if (ttl - (n - 1 - i) >= x) {
            ttl -= (n - 1 - i);
            v.push_back(i);
        } else {
            printf(" %d", i);
        }
    }
    v.push_back(n - 1);
    for (int i = v.size() - 1; i >= 0; i--) {
        printf(" %d", v[i]);
    }
    printf("\n");
}
