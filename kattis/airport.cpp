#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

long long n;
double from[205];
pii pts[205];
double ans;

pii turn(long long a, long long b, long long c) {
    long long dy = pts[b].sc - pts[a].sc;
    long long dx = pts[b].fs - pts[a].fs;
    long long ey = pts[c].sc - pts[b].sc;
    long long ex = pts[c].fs - pts[b].fs;
    long long d = (c + 1) % n;
    long long fy = pts[d].sc - pts[b].sc;
    long long fx = pts[d].fs - pts[b].fs;
    long long abc = 1LL * dx * ey - 1LL * dy * ex;
    long long abd = 1LL * dx * fy - 1LL * dy * fx;
    //printf("turn -- %lld %lld %lld %lld -> %lld %lld\n", a, b, c, d, abc, abd);
    return {abc, abd};
}

bool cek(long long a, long long b, long long c) {
    //printf("cek >> %lld %lld %lld\n", a, b, c);
    if (a == c || a == (c + 1) % n || b == c || b == (c + 1) % n) {
        from[c] = 0;
        return true;
    }
    pii tmp = turn(a, b, c);
    if ((tmp.fs < 0 && tmp.sc > 0) || (tmp.fs > 0 && tmp.sc < 0)) return false;
    if (tmp.fs == 0 || tmp.sc == 0) {
        if (tmp.fs + tmp.sc == 0) {
            from[c] = from[(c - 1 + n) % n];
        } else if (tmp.fs == 0) {
            from[c] = abs(tmp.sc) / tmp.sc;
        } else if (tmp.sc == 0) {
            from[c] = abs(tmp.fs) / tmp.fs;
        }
        if (from[c] != from[(c - 1 + n) % n] && 
                from[c] != 0 && from[(c - 1 + n) % n]) {
            return false;
        }
    } else {
        from[c] = abs(tmp.fs) / tmp.fs;
    }
    return true;
}

double getDist(long long a, long long b) {
    double x = pts[a].fs - pts[b].fs;
    double y = pts[a].sc - pts[b].sc;
    return sqrt(x * x + y * y);
}

int main() {
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld%lld", &pts[i].fs, &pts[i].sc);
    }
    ans = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = i + 1; j < n; j++) {
            //printf("\n");
            bool can = true;
            from[i] = 0;
            for (long long k = i + 1; k < n; k++) {
                can = can && cek(i, j, k);
            }
            for (long long k = 0; k < i; k++) {
                can = can && cek(i, j, k);
            }
            if (can) {
                int up = 0;
                int lo = 0;
                for (int k = i; k < j; k++) {
                    if (from[k] != 0) {
                        if (up != 0) {
                            if (from[k] != up) {
                                can = false;
                            }
                        } else {
                            up = from[k];
                        }
                    }
                }
                for (int k = j; k < n; k++) {
                    if (from[k] != 0) {
                        if (lo != 0) {
                            if (from[k] != lo) {
                                can = false;
                            }
                        } else {
                            lo = from[k];
                        }
                    }
                }
                for (int k = 0; k < i; k++) {
                    if (from[k] != 0) {
                        if (lo != 0) {
                            if (from[k] != lo) {
                                can = false;
                            }
                        } else {
                            lo = from[k];
                        }
                    }
                }
                if (can && (up != lo || (up == 0 && lo == 0))) {
                    /*
                    printf("-- %lld %lld -> %lf--\n", i, j, getDist(i, j));
                    for (int k = 0; k < n; k++) {
                        printf("%d from %lf\n", k, from[k]);
                    }
                    */
                    ans = max(ans, getDist(i, j));
                }
            }
        }
    }
    printf("%lf\n", ans);
    return 0;
}
