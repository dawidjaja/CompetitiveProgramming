#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int l, n;
        int mini, maxi;
        scanf("%d%d", &l, &n);
        maxi = 0;
        mini = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            maxi = max(maxi, max(x, l - x));
            mini = max(mini, min(x, l - x));
        }
        printf("%d %d\n", mini, maxi);
    }
    return 0;
}
