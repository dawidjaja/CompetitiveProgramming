#include <bits/stdc++.h>

using namespace std;

int n, freq[2][100005];

int getAns() {
    int l = 1;
    int r = 100;

    int lcur = freq[0][l];
    int rcur = freq[1][r];
    int ret = 0;
    while (l <= 100) {
        while (lcur == 0) {
            lcur = freq[0][++l];
            if (l > 100) break;
        }
        if (l > 100) break;
        while (rcur == 0) {
            rcur = freq[1][--r];
            if (r <= 0) break;
        }
        if (r <= 0) break;

        int tmp = min(lcur, rcur);
        ret = max(ret, l + r);
        lcur -= tmp;
        rcur -= tmp;
    }
    return ret;
}

int main() {
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        freq[0][a]++;
        freq[1][b]++;

        printf("%d\n", getAns());

    }
    return 0;
}

