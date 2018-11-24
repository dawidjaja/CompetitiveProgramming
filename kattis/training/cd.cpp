#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) && n && m) {
        int a = 0;
        int b = 0;
        int ans = 0;
        int jack[1000005], jill[1000005];
        for (int i = 0; i < n; i++) {
            scanf("%d", &jack[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &jill[i]);
        }
        while (a < n && b < m) {
            if (jack[a] == jill[b]) a++, b++, ans++;
            if (jack[a] < jill[b]) a++;
            if (jack[a] > jill[b]) b++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
