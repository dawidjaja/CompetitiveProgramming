#include <bits/stdc++.h>

using namespace std;

const long long MAX = 360000;
const long long x = 360007;

long long hand[2][200005], hashing[200005], n, dif[2][200005], targetHash;

long long pngkt(long long a, long long b) {
    if (b == 0) return 1;
    if (b & 1)
        return pngkt(a, b - 1) * a;
    long long tmp = pngkt(a, b / 2);
    return tmp * tmp;
}

long long diff(long long x, long long idx) {
    long long tmp = hand[x][(idx + 1) % n] - hand[x][idx];
    if (tmp < 0) {
        tmp += MAX;
    }
    return tmp;
}

int main() {
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &hand[0][i]);
    }
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &hand[1][i]);
    }
    sort(hand[0], hand[0] + n);
    sort(hand[1], hand[1] + n);
    for (long long i = 0; i < n; i++) {
        dif[0][i] = diff(0, i);
        dif[1][i] = diff(1, i);
    }
    targetHash = 0;
    for (long long i = 0; i < n; i++) {
        targetHash *= x;
        targetHash += dif[0][i];
        hashing[i] = (i == 0 ? 0 : hashing[i - 1]) * x + dif[1][i];
        printf("-- %lld - %lld\n", i, hashing[i]);
    }
    printf("%lld\n", targetHash);

    long long ttl = hashing[n - 1];
    for (long long i = 0; i < n; i++) {
        long long p = pngkt(x, i);
        long long tmp = (ttl - hashing[i] * pngkt(x, n - i)) * p + hashing[i]; 
        printf("tmp %lld\n", tmp);
        if (tmp == targetHash) {
            printf("possible\n");
            return 0;
        }
    }
    printf("impossible\n");
}
