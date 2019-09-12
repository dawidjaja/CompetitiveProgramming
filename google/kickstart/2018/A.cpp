#include <algorithm>
#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;

string seq[105];
long long n, p, t;
map <string, long long> vis;

bool cmp(string a, string b) {
    long long la = a.length();
    long long lb = b.length();
    if (la == lb) return a < b;
    else return la < lb;
}

long long pngkt(long long a, long long b) {
    if (b == 0) return 1;
    if (b & 1) return a * pngkt(a, b - 1);
    long long tmp = pngkt(a, b / 2);
    return tmp * tmp;
}

int main() {
    scanf("%lld", &t);
    for (long long _ = 1; _ <= t; _++) {
        scanf("%lld%lld", &n, &p);
        for (long long i = 0; i < p; i++) {
            cin >> seq[i];
        }
        sort(seq, seq + p, cmp);
        long long ans = pngkt(2, n);
        vis.clear();
        for (long long i = 0; i < p; i++) {
            string s = "";
            s += seq[i][0];
            long long l = seq[i].length();
            long long cek = 0;
            for (long long j = 1; j < l; j++) {
                if (vis.count(s)) {
                    cek = 1;
                    break;
                }
                s += seq[i][j];
            }
            if (vis.count(s)) cek = 1;
            if (cek == 0) {
                ans -= pngkt(2, n - l);
                vis[s] = 1;
            }
        }
        printf("Case #%lld: %lld\n", _, ans);
    }
    return 0;
}
