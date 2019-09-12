#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, k, bat[2000000], vis[1000006];

int main() {
    priority_queue <pii> pq;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n * k * 2; i++) {
        scanf("%d", &bat[i]);
    }
    sort(bat, bat + 2 * n * k);
    pq.push({bat[0] - bat[1], 0});
    int cnt = 0;
    int ans = 0;
    int r = 0;
    for (int i = 0; i < n * k * 2; i++) {
        if (cnt >= n) break;
        int dif = -pq.top().fs;
        int now = -pq.top().sc;
        pq.pop();
        if (vis[now] == 0 && vis[now + 1] == 0) {
            vis[now] = vis[now + 1] = 1;
            //printf("-- %d --\n", now);
            ans = max(ans, dif);
            for (int j = 1; j <= 2 * k && r + j + 1 < 2 * n * k; j++) {
                pq.push({bat[r + j] - bat[r + j + 1], -(r + j)});
            }
            r += 2 * k;
            cnt++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
