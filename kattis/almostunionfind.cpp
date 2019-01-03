#include <bits/stdc++.h>

using namespace std;

long long n, m, p[200005], sz[200005], sum[200005], a, b, type;

long long par(long long x) {
    return p[x] == x ? x : p[x] = par(p[x]);
}

int main() {
    while(scanf("%lld%lld", &n, &m) != EOF){
        for (long long i = 1; i <= n; i++) {
            p[i] = i + n;
            p[i + n] = i + n;
            sz[i + n] = 1;
            sum[i + n] = i;
        }
        for (long long i = 0; i < m; i++) {
            scanf("%lld", &type);
            if (type == 1) {
                scanf("%lld%lld", &a, &b);
                if (par(a) != par(b)) {
                    sz[par(a)] += sz[par(b)];
                    sum[par(a)] += sum[par(b)];
                    p[par(b)] = par(a);
                }
            } else if (type == 2) {
                scanf("%lld%lld", &a, &b);
                if (par(a) != par(b)) {
                    sz[par(a)]--;
                    sz[par(b)]++;
                    sum[par(a)] -= a;
                    sum[par(b)] += a;
                    p[a] = par(b);
                }
            } else if (type == 3) {
                scanf("%lld", &a);
                printf("%lld %lld\n", sz[par(a)], sum[par(a)]);
            }
        }
    }
}

