#include <algorithm>
#include <cstdio>

using namespace std;

int list[100005];

int main() {
    int n, t, ans;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
        if (i == 0) ans = t / list[i] + 1;
        else {
            ans = min(max(0, ans), t / list[i] + 1);
        }
        t -= list[i];
        printf("%d\n", ans);
    }
    return 0;
}
