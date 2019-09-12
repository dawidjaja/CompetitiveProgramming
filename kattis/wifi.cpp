#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000005;

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int house[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &house[i]);
        }
        if (n == m) {
            printf("0.0\n");
            continue;
        }
        sort(house, house + m);

        int l = 0;
        int r = 1000000;

        while (l < r) {
            int mid = ((l + r) >> 1);

            // checking the houses whether it fits in the router range
            int last = -INF;
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (last + mid < house[i]) {
                    cnt++;
                    last = house[i];
                }
            }

            // if it's possible, right pointer move to middle
            if (cnt <= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        printf("%.1lf\n", 1.0 * l / 2);

    }
}
