#include <bits/stdc++.h>

using namespace std;

int n, k;
int vis[1000005];

int prime(int x) {
    int maks = x;
    int ans = 0;
    for (int i = 2; i <= maks; i++) {
        if (vis[i] == 0) {
            ans++;
        }
        for (int j = 2; i * j <= maks; j++) {
            vis[i * j] = 1;
        }
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    printf("%d\n", prime(n / k) + 1);
}
