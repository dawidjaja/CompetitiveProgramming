#include <bits/stdc++.h>

using namespace std;

int n, v[5005], vis[5005][5005], ans;
unordered_map <int, int> pos;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        pos[v[i]] = i;
    }
    sort(v, v + n);
    ans = 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vis[i][j] == 1) {
                continue;
            }
            int tmp = 2;
            int l = v[i];
            int r = v[j];
            int pos_l = i;
            int pos_r = j;
            int dif = r - l;
            while (pos.count(r + dif)) {
                r += dif;
                vis[pos_r][pos[r]] = 1;
                pos_r = pos[r];
                tmp++;
            }
            while (pos.count(l - dif)) {
                l -= dif;
                vis[pos_l][pos[l]] = 1;
                pos_l = pos[l];
                tmp++;
            }
            ans = max(ans, tmp);
        }
    }
    printf("%d\n", ans);
    return 0;
}
