#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<long long, long long>

using namespace std;

long long n, ans;
pii a[100005];

long long count(int a, int b) {
    if (a == -1) return 0;
    return (long long)(a + b) * (b - a + 1) / 2;
}

int main() {
    scanf("%lld", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].fs, &a[i].sc);
    }
    sort(a, a + n);

    long long start = -1;
    long long last = -1;

    for (int i = 0; i < n; i++) {
        if (a[i].fs > last) {
            ans += count(start, last);
            start = a[i].fs;
        }
        last = max(a[i].sc, last);
    }
    ans += count(start, last);
    printf("%lld\n", ans);
    return 0;
}
