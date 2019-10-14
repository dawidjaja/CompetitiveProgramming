#include <bits/stdc++.h>

using namespace std;

unordered_map <int, int> rg, day;
int bit[300005], tc, n, x[300005], ptr, sml[300005], nx[300005];
long long ps[300005];

void updateBit(int idx, int x) {
    for (int i = idx; i <= n; i += (i & -i)) {
        bit[i] = max(bit[i], x);
    }
}

int queryBit(int idx) {
    int ret = bit[idx];
    for (int i = idx; i >= 1; i -= (i & -i)) {
        ret = max(bit[i], ret);
    }
    return ret;
}

long long queryPS(int l, int r) {
    return ps[r] - ps[l - 1];
}

int getInt() {
    char c = getchar_unlocked();
    while ((c < '0' || c > '9') && c != '-') c = getchar_unlocked();

    bool neg = (c == '-');

    int ret = (c == '-') ? 0 : (c - '0');

    c = getchar_unlocked();
    while ('0' <= c && c <= '9') {
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar_unlocked();
    }
    if (neg) ret = -ret;
    //printf("-- %d -- \n", ret);
    return ret;
}

int main() {
    //scanf("%d", &tc);
    tc = getInt();
    while (tc--) {
        //scanf("%d", &n);
        n = getInt();

        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            x[i] = getInt();
            //scanf("%d", &x[i]);
            bit[i] = -300005;
            ps[i] = ps[i - 1] + x[i];
        }

        sml[n + 1] = 300005;
        for (int i = n; i >= 1; i--) {
            updateBit(i, x[i]);
            sml[i] = min(sml[i + 1], x[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (day[x[i]] != tc) {
                day[x[i]] = tc;
                nx[i] = -1;
            } else {
                nx[i] = rg[x[i]];
            }

            rg[x[i]] = i;
            //printf("next %d -> %d\n", i, nx[i]);
        }
        
        ptr = n;
        while (ptr != 1) {
            int big = queryBit(ptr);
            int tmp = rg[big];
            //printf("-- %d %d --\n", big, tmp);
            if (tmp == ptr) {
                int rgBig = queryBit(ptr - 1);
                ans += big - rgBig;

                rg[x[ptr]] = nx[rg[x[ptr]]];
                ptr--;
            } else {
                long long tot = queryPS(tmp + 1, ptr);
                tot -= 1LL * (ptr - tmp) * big;
                ans += tot;

                //printf("-- %d %d %d %d--\n", tmp, x[tmp], rg[x[tmp]], nx[rg[x[tmp]]]);

                rg[x[tmp]] = nx[rg[x[tmp]]];

                x[tmp] = sml[tmp];
                rg[x[tmp]] = tmp;
                nx[tmp] = nx[rg[sml[tmp]]];
                while (nx[tmp] >= ptr) {
                    nx[tmp] = nx[nx[tmp]]; 
                }

                ps[tmp] = ps[tmp - 1] + x[tmp];
                bit[tmp] = sml[tmp];

                ptr = tmp;
            }
        }

        printf("%lld\n", ans);
        
    }
    return 0;
}
