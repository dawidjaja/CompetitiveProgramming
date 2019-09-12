#include <bits/stdc++.h>

using namespace std;

long long n, m, s, t, a, b, sq[2][105];
vector <long long> v[105];

int main() {
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        sq[0][i] = sq[1][i] = 0;
    }
    sq[0][s] = 1;
    long long now = 1;
    for (long long i = 0; i < t; i++) {
        now ^= 1LL;
        for (long long j = 0; j < n; j++) {
            sq[now ^ 1LL][j] = 0;
        }
        for (long long j = 0; j < n; j++) {
            for (long long k = 0; k < v[j].size(); k++) {
                sq[now ^ 1LL][v[j][k]] += sq[now][j];
            }
        }
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        ans += sq[now ^ 1LL][i];
    }
    printf("%lld\n", ans);
}
