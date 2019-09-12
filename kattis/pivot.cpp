#include <bits/stdc++.h>

using namespace std;

int num[100005], n, bit[100005];

int getBit(int x) {
    if (x == 0) return 0;
    int tmp = 0;
    for (int i = x; i >= 1; i -= (i & -i)) {
        tmp += bit[i];
    }
    return tmp;
}

void updateBit(int x) {
    for (int i = x; i <= n; i += (i & -i)) {
        bit[i]++;
    }
}

int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        if (num[i] == i + 1 && getBit(i) == i) {
            ans++;
        }
        updateBit(num[i]);
    }
    printf("%d\n", ans);
}
