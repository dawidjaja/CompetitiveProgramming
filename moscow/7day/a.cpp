#include <bits/stdc++.h>

using namespace std;

int n, q, p[100005], from[100005], c[100005];

int main() {
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        from[p[i]]++;
    }
    
    int odd = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        if (c[i] & 1) {
            odd = 1;
        }
    }

    /*
    for (int i = 1; i <= n; i++) {
        if (from[i] == 0) {
            int ada = find(i, 0);
        }
    }
    */

    while (q--) {
        int m;
        scanf("%d", &m);

        if ((m & 1 && !odd) || m <= 0) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
