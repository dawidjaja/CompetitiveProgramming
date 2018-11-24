#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n, k, list[100005];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    int l = 0;
    int r = 0;
    int maxi = 1;
    while (r < n - 1) {
        r++;
        while (l < n - 1 && list[l] + 1000 <= list[r]) {
            l++;
        }
        maxi = max(maxi, r - l + 1);
    }
    printf("%d\n", (int) ceil(1.0 * maxi / k));
    return 0;
}
