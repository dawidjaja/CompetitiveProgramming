#include <algorithm>
#include <cstdio>
#include <cmath>

#define fs first
#define sc second
#define pii pair<long long,long long>
#define ppi pair<pii,long long>
#define MOD 1000000007

using namespace std;

ppi list[100005];
long long child[100005], n, ans, dp[100005][3];

long long pwr(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    long long tmp = pwr(a, b / 2);
    tmp = (tmp * tmp) % MOD;
    if (b & 1) {
        tmp *= a;
        tmp = tmp % MOD;
    }
    return tmp;
}

long long genChild(long long x) {
    if (x == 0) {
        return 1;
    }
    child[x] = genChild(list[x].fs.fs) + genChild(list[x].fs.sc);
    return child[x];
}

long long f(long long cur, long long state) {
    if (cur == 0) {
        return 1;
    }
    if (dp[cur][state] != -1) {
        return dp[cur][state];
    }
    long long &ret = dp[cur][state];
    ret = 0;
    if (state == -1) {
        ret += (f(list[cur].fs.fs, 0) * f(list[cur].fs.sc, 0)) % MOD;
        ret = ret % MOD;
        ret += (f(list[cur].fs.fs, 0) * f(list[cur].fs.sc, 1)) % MOD;
        ret = ret % MOD;
        ret += (f(list[cur].fs.fs, 1) * f(list[cur].fs.sc, 0)) % MOD;
        ret = ret % MOD;
        ret += (f(list[cur].fs.fs, 1) * f(list[cur].fs.sc, 1)) % MOD;
        ret = ret % MOD;
    } else if (state == 0 && list[cur].sc <= 0) {
        ret += (f(list[cur].fs.fs, 1) * f(list[cur].fs.sc, 1)) % MOD;
        ret = ret % MOD;
    } else if (state == 1 && abs(list[cur].sc) == 1) {
        ret += (f(list[cur].fs.fs, 0) * f(list[cur].fs.sc, 0)) % MOD;
        ret = ret % MOD;
        ret += (f(list[cur].fs.fs, 1) * f(list[cur].fs.sc, 0)) % MOD;
        ret = ret % MOD;
        ret += (f(list[cur].fs.fs, 0) * f(list[cur].fs.sc, 1)) % MOD;
        ret = ret % MOD;
    }
    printf("%lld %lld --> %lld\n", cur, state, ret);
    return ret;
}

int main() {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &list[i].fs.fs, &list[i].fs.sc, &list[i].sc);
        for (int j = 0; j <= 2; j++) {
            dp[i][j] = -1;
        }
    }
    ans = f(1, (list[1].sc + 3) % 3);
    printf("%lld\n", ans);
    return 0;
}

