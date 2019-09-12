#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    for (int _ = 1; _ <= tc; _++) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", _);
        getchar();
        for (int i = 0; i < 2 * (n - 1); i++) {
            char c = getchar();
            if (c == 'S') {
                printf("E");
            } else {
                printf("S");
            }
        }
        printf("\n");
    }
}
