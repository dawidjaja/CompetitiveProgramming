#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, k, ans, lptr, vis[100005];
pii list[100005];
priority_queue <int> pq;
multiset <int> ms;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &list[i].sc, &list[i].fs);
    }
    sort(list, list + n);

    ans = 0;
    for (int i = 0; i < k; i++) ms.insert(0);

    for (int i = 0; i < n; i++) {
        auto it = ms.upper_bound(list[i].sc);
        if (it != ms.begin()) {
            it = prev(it);
            ms.erase(it);
            ms.insert(list[i].fs);
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
