#include <bits/stdc++.h>

using namespace std;

int n, m, l, k, x, ans, light[1005];
vector <int> v[1005];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%d", &l);
    if (l == 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < l; i++) {
        int x;
        scanf("%d", &x);
        light[x] = 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            v[i].push_back(x);
        }
    }

    ans = 0;
    for (int ll = 0; ll < 2; ll++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                light[v[i][j]] ^= 1;
            }
            ans++;

            int ada = 0;
            for (int j = 1; j <= m; j++) {
                if (light[j] == 1) {
                    ada = 1;
                    break;
                }
            }

            if (!ada) {
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}
