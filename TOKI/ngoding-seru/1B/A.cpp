#include <bits/stdc++.h>

using namespace std;

vector <int> v[100005];
int n, t, tmp, x;

int main() {
    scanf("%d", &n);
    int x = 1000000005;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &tmp);
            v[i].push_back(tmp);
        }
        x = min(x, v[i][t - 1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size() - 1; j++) {
            if (v[i][j] >= x) {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", x);
}
