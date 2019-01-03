#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, lim, ans;
pii minion[105];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &minion[i].fs, &minion[i].sc);
    }
    sort(minion, minion + n);
    lim = 0;
    for (int i = 0; i < n; i++) {
        if (minion[i].fs > lim) {
            ans++;
            lim = minion[i].sc;
        } else {
            lim = min(lim, minion[i].sc);
        }
    }
    printf("%d\n", ans);
}
