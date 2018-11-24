#include <algorithm>
#include <cstdio>

using namespace std;

int n, ans, list[1005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &list[i]);
    }
    list[0] = 0;
    list[n + 1] = 1001;
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (list[i - 1] + 1 == list[i] &&
            list[i] + 1 == list[i + 1]) {
            tmp++;
            ans = max(tmp, ans);
        } else {
            tmp = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
