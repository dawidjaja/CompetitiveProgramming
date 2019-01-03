#include <bits/stdc++.h>

using namespace std;

int bit[2][1000005], n, k, con[1000005];

inline void update(int x) {
    for (int i = x; i <= n; i += (i & -i)) {
        bit[con[x]][i]++;
        //printf("update %d %d -> %d\n", con[x], x, bit[con[x]][x]);
    }
}

int get(int x) {
    if (x == 0) return 0;
    int ret = 0;
    for (int i = x; i >= 1; i -= (i & -i)) {
        ret += bit[1][i] - bit[0][i];
    }
    //printf("get %d -> %d\n", x, ret);
    return ret;
}

int main() {
    scanf("%d%d", &n, &k);
    while (k--) {
        getchar();
        char type = getchar();
        if (type == 'F') {
            int x;
            scanf("%d", &x);
            con[x] ^= 1;
            update(x);
        } else {
            int l, r;
            int ans;
            scanf("%d%d", &l, &r);
            ans = get(r) - get(l - 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}
