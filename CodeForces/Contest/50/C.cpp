#include <algorithm>
#include <cstdio>

using namespace std;

long long arr[5];

long long findLen(long long x) {
    long long ret = 0;
    while (x) {
        x = x / 10;
        ret++;
    }
    return ret;
}

long long getFront(long long x) {
    while (x >= 10) {
        x = x / 10;
    }
    return x;
}

long long getCut(long long x) {
    long long ret = 0;
    long long tmp = 1;
    while (x >= 10) {
        ret += tmp * (x % 10);
        x = x / 10;
        tmp *= 10;
    }
    return ret;
}

long long combi(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (a < b) {
        return 0;
    }
    long long ret = 1;
    for (int i = 0; i < b; i++) {
        ret *= a - i;
    }
    for (int i = 2; i <= b; i++) {
        ret = ret / i;
    }
    return ret;
}

long long find(long long x, long long sisa) {
    if (x == 0) {
        return 0;
    }
    long long pjg = findLen(x);
    long long dpn = getFront(x);
    printf("--%lld %lld %lld %lld\n", x, sisa, pjg, dpn);
    if (pjg <= sisa) {
        return x;
    }
    long long ans = 0;
    for (int i = 0; i <= sisa; i++) {
        ans += combi(pjg - 1, i) * arr[i];
        // printf("test %lld, %lld\n", combi(pjg - 1, i), arr[i]);
    }
    ans += find(getCut(x), sisa - 1) * (dpn - 1);
    return (ans);
}

int tc;
long long l, r, ans;

int main() {
    scanf("%d", &tc);
    arr[3] = 729;
    arr[2] = 81;
    arr[1] = 9;
    arr[0] = 1;
    while (tc--) {
        scanf("%lld%lld", &l, &r);
        ans = find(r, 3) - find(l - 1, 3);
        printf("testab >> %lld %lld\n", find(r, 3), find(l - 1, 3));
        printf("%lld\n", ans);
    }
    return 0;
}

