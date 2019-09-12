#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long n, list[500005], kcl, ttl, gde;

int main() {
    scanf("%lld", &n);
    kcl = 1000000005;
    gde = -1000000005;
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &list[i]);
        kcl = min(kcl, list[i]);
        gde = max(gde, list[i]);
        ttl += abs(list[i]);
    }
    if (n == 1) 
        printf("%lld\n", list[1]);
    else {
        printf("%lld\n", ttl - max(0LL, kcl * 2) + min(0LL, gde * 2));
    }
}

