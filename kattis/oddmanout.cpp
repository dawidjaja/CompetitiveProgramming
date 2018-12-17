#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int _ = 1; _ <= t; _++) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            ans ^= x;
        }
        printf("Case #%d: %d\n", _, ans);
    }
    return 0;
}
