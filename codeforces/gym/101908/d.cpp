#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    while(n--) {
        int x;
        scanf("%d", &x);
        if (x != 1) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
