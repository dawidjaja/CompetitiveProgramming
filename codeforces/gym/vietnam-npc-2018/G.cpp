#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <assert.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, a, b, day, vis[300005];
long long ans;
vector<int> v[300005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        day = i;
        queue <pii> q;
        q.push({i, 0});
        while (q.size()) {
            int tmp = q.front().fs;
            int s = q.front().sc;
            q.pop();
            vis[tmp] = day;
            if (s == 2) {
                ans++;
                continue;
            }
            for (int j = 0; j < v[tmp].size(); j++) {
                if (vis[v[tmp][j]] != day) {
                    vis[v[tmp][j]] = day;
                    q.push({v[tmp][j], s + 1});
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
