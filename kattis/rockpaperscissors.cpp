#include <bits/stdc++.h>

using namespace std;

int n, k, w[105], l[105];

int suten(char a, char b) {
    if (a == 'r') {
        if (b == 's') return 0;
        if (b == 'r') return 1;
        if (b == 'p') return 2;
    }
    if (a == 'p') {
        if (b == 'r') return 0;
        if (b == 'p') return 1;
        if (b == 's') return 2;
    }
    if (a == 's') {
        if (b == 'p') return 0;
        if (b == 's') return 1;
        if (b == 'r') return 2;
    }
}

int main() {
    bool first = true;
    while (scanf("%d", &n) && n != 0) {
        scanf("%d", &k);
        if (!first) {
            printf("\n");
        }
        first = false;
        int game = k * n * (n - 1) / 2;
        int play = k * (n - 1);
        for (int i = 1; i <= n; i++) {
            w[i] = 0;
            l[i] = 0;
        }
        for (int i = 0; i < game; i++) {
            int p1, p2;
            char m1[15], m2[15];
            scanf("%d%s%d%s", &p1, m1, &p2, m2);
            int res = suten(m1[0], m2[0]);
            if (res == 0) w[p1]++, l[p2]++;
            if (res == 2) l[p1]++, w[p2]++;
        }
        for (int i = 1; i <= n; i++) {
            if (w[i] + l[i] == 0) {
                printf("-\n");
            } else {
                double ans = 1.0 * w[i] / (w[i] + l[i]);
                printf("%.3lf\n", ans);
            }
        }
    }
    return 0;
}
