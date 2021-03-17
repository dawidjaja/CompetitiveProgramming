#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

const int INF = 1e9 + 7;
int a, b, n, p[105];
pii ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    scanf("%d%d", &a, &b);

    sort(p, p + n);

    for (int i = 0; i < n - 1; i++) {
        int mid = p[i] + p[i + 1];
        mid /= 2;

        for (int j = mid - 1; j <= mid + 1; j++) {
            if (j & 1 && a <= j && j <= b) {
                pii ta = {abs(p[i + 1] - j), j};
                pii tb = {abs(j - p[i]), j};
                ans = max(ans, min(ta, tb));
            }
        }
    }

    for (int j = a; j <= a + 1; j++) {
        if (j & 1 && a <= j && j <= b) {
            pii tmp = {INF, j};
            for (int i = 0; i < n; i++) {
                pii prr = {abs(p[i] - j), j};
                tmp = min(tmp, prr);
            }
            ans = max(ans, tmp);
        }
    }

    for (int j = b - 1; j <= b; j++) {
        if (j & 1 && a <= j && j <= b) {
            pii tmp = {INF, j};
            for (int i = 0; i < n; i++) {
                pii prr = {abs(p[i] - j), j};
                tmp = min(tmp, prr);
            }
            ans = max(ans, tmp);
        }
    }
    printf("%d\n", ans.sc);
    return 0;
}
