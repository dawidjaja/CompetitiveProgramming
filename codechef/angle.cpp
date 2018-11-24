#include <algorithm>
#include <cstdio>
#include <cmath>

#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

bool valid(long long a, long long b, long long c, long long p, long long q) {
    if (((a * a + b * b - c * c) * q) >= p * 2 * a * b) {
        return true;
    }
    return false;
}

double getAcos(long long a, long long b, long long c) {
    return acos(1.0 * (a * a + b * b - c * c) / (2 * a * b));
}

int main() {
    long long tc;
    scanf("%lld", &tc);
    while (tc--) {
        long long n, p, q;
        pii list[1005];
        scanf("%lld%lld%lld", &n, &p, &q);
        for (long long i = 0; i < n; i++) {
            scanf("%lld", &list[i].fs);
            list[i].sc = i + 1;
        }
        long long a, b, c;
        a = b = c = -1;
        double teta = -1;
        sort(list, list + n);
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < n; j++) {
                if (i == j) continue;
                long long l = 0;
                long long r = n - 1;
                while (r - l >= 5) {
                    long long mid = ((l + r) >> 1) + 1;
                    if(valid(list[i].fs, list[j].fs, list[mid].fs, p, q)) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                for (long long k = r; k >= l; k--) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (valid(list[i].fs, list[j].fs, list[k].fs, p, q) &&
                            getAcos(list[i].fs, list[j].fs, list[k].fs) > teta) {
                        c = list[i].sc;
                        b = list[j].sc;
                        a = list[k].sc;
                        teta = getAcos(list[i].fs, list[j].fs, list[k].fs);
                    }
                }
            }
        }
        if (teta == -1) {
            printf("-1\n");
            continue;
        } 
        printf("%lld %lld %lld\n", a, b, c);
    }
    return 0;
}
