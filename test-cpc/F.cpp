#include <bits/stdc++.h>

using namespace std;

int n, m;
long long ans, freq[26];

int main() {
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++) {
        char c = getchar();
        freq[c - 'A']++;
    }
    while (m--) {
        getchar();
        char c, rep[105];
        cin >> c >> rep;

        int awal = c - 'A';
        long long tmp = 0;
        for (int i = 0; i < strlen(rep); i++) {
            int now = rep[i] - 'A';
            if (now == awal) {
                tmp += freq[awal];
            } else {
                freq[now] += freq[awal];
            }
        }
        freq[awal] = tmp;
    }
    for (int i = 0; i < 26; i++) {
        ans += freq[i];
    }
    printf("%lld\n", ans);
    return 0;
}
