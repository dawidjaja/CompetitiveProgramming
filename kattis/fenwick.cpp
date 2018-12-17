#include <algorithm>
#include <cstdio>

using namespace std;

long long bit[5000005], n, q, x, a, b;

long long getBit(long long x) {
    long long ret = 0;
    for (long long i = x; i >= 1; i -= (i & -i)) {
        ret += bit[i];
    }
    return ret;
}

void updateBit(long long idx, long long x) {
    for (int i = idx; i <= n; i += (i & -i)) {
        bit[i] += x;
    }
}

int main() {
    scanf("%lld%lld", &n, &q);
    while (q--) {
        getchar();
        char query = getchar();
        if (query == '?') {
            scanf("%lld", &x);
            /*
            if (x == 0) {
                printf("0\n");
                continue;
            }
            */
            printf("%lld\n", getBit(x));
        } else if (query == '+') {
            scanf("%lld %lld", &a, &b);
            a += 1;
            updateBit(a, b);
        }
    }
    return 0;
}
