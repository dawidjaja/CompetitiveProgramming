#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector <long long> v;
long long vis[100005];

inline void sieve() {
    for (long long i = 2; i <= 100000; i++) {
        if (vis[i] == 0) v.push_back(i);
        for (long long j = i; j <= 100000; j += i) {
            vis[j] = 1;
        }
    }
}

long long pngkt(long long a, long long b) {
    if (b == 1) return a;
    if (b & 1) return a * pngkt(a, b - 1);
    long long tmp = pngkt(a, b / 2);
    return tmp * tmp;
}

int main() {
    long long n;
    sieve();
    while (scanf("%lld", &n) && n != 0) {
        long long ans = 1;
        long long cek = 1;
        bool neg = false;
        if (n < 0) {
            neg = true;
            n = -n;
        }
        for (long long i = 0; (i < v.size() && v[i] <= n); i++) {
            if (n % v[i] == 0) {
                long long tmp = 0;
                while (n % v[i] == 0) {
                    tmp++;
                    n /= v[i];
                }
                long long y = n;
                double x = pow(n, 1.0/tmp);
                printf("%lf, %lld, %lld %lld %lld\n", x, (long long)floor(x), tmp, y, pngkt((long long) floor(x), tmp));
                if (pngkt((long long)floor(x), tmp) == y) {
                    if (neg) {
                        //printf("%lld\n", tmp);
                        while (tmp >= 1 && ((tmp % 2) == 0)) {
                            tmp /= 2;
                        }
                        tmp = max(1LL, tmp);
                    }
                    printf("%lld\n", tmp);
                } else {
                    printf("1\n");
                }
                cek = 0;
                break;
            }
        }
        if (cek) {
            printf("1\n");
        }
    }
    return 0;
}
