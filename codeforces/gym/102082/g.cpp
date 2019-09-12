#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<long long, long long>

using namespace std;

long long bit[100005], n, ans;
pii a[100005];

long long getBit(long long l, long long r) {
    long long ret = 0;
    for (long long i = r; i > 0; i -= (i & -i)) {
        ret += bit[i];
    }
    for (long long i = l - 1; i > 0; i -= (i & -i)) {
        ret -= bit[i];
    }
    //printf("getBit %lld %lld = %lld\n", l, r, ret);
    return ret;
}

void updateBit(long long x, long long dif) {
    for (long long i = x; i <= n; i += (i & -i)) {
        bit[i] += dif;
    }
}

long long getOpt(long long x) {
    return min(getBit(1, x - 1), getBit(x + 1, n));
}

long long count(long long x) {
    long long l = x;
    long long r = x;
    while (r <= n && a[l].fs == a[r + 1].fs) {
        r++;
    }

    long long ret = 0;
    while (l <= r) {
        long long tl = getOpt(a[l].sc);
        long long tr = getOpt(a[r].sc);
        //printf("-kntl- %lld %lld --\n", tl, tr);
        if (tl < tr) {
            updateBit(a[l].sc, -1);
            ret += tl;
            l++;
        } else {
            updateBit(a[r].sc, -1);
            ret += tr;
            r--;
        }
    }
    return ret;

}

int main() {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &a[i].fs);
        a[i].sc = i;
        updateBit(i, 1);
        //bit[i] = (i & -i);
        //printf("-- %lld -- %lld\n", i, bit[i]);
    }
    sort(a + 1, a + n + 1);
    ans = 0;
    for (long long i = 1; i <= n; i++) {
        //printf("-- %lld ", i);
        if (i == 1 || a[i].fs != a[i - 1].fs) {
            ans += count(i);
            //printf("- %lld\n", ans);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
