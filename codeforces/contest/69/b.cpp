#include <bits/stdc++.h>

using namespace std;

int n, a[200005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int l = 0, r = n - 1;
    int cur = 1;
    while (l < r) {
        if (cur == a[l]) {
            l++;
            cur++;
        } else if (cur == a[r]) {
            r--;
            cur++;
        } else {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
