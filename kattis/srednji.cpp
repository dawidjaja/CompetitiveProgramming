#include <bits/stdc++.h>

using namespace std;

int n, b, num[100005], diff[100005], now, pos;
map <int,int> freq;

int main() {
    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        if (num[i] == b) {
            pos = i;
        }
    }
    now = 0;
    for (int i = pos + 1; i < n; i++) {
        if (num[i] > b) {
            now++;
        } else {
            now--;
        }
        diff[i] = now;
    }
    now = 0;
    for (int i = pos - 1; i >= 0; i--) {
        if (num[i] > b) {
            now++;
        } else {
            now--;
        }
        diff[i] = now;
    }
    for (int i = pos; i < n; i++) {
        freq[diff[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i <= pos; i++) {
        if (freq.count(-diff[i])) {
            ans += freq[-diff[i]];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
