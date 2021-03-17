#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<long long,long long>
#define pdp pair<double,pii>
#define ppp pair<pii,pii>

using namespace std;

long long n, m, f[105], b[105];
vector <pii> v;

double eps = 1e-6;

bool cmp(pii a, pii b) {
    if (a.fs * b.sc == a.sc * b.fs) {
        return a.fs < b.fs;
    }

    return a.fs * b.sc < a.sc * b.fs;
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &f[i]);
    }
    for (long long i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        for (long long j = 0; j < n; j++) {
            v.push_back({f[j], b[i]});
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (long long i = 0; i < v.size(); i++) {
        printf("(%lld,%lld)\n", v[i].fs, v[i].sc);
    }


    return 0;
}
