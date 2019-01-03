#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    while (true) {
        scanf("%d", &x);
        if (x == 0) return 0;
        if (x <= 6) {
            if (x == 3) {
                printf("4\n");
            } else {
                printf("No such base\n");
            }
            continue;
        }
        x -= 3;
        int cap = sqrt(x);
        int ans = -1;
        for (int i = 4; i <= cap; i++) {
            if (x % i == 0) {
                ans = i;
                break;
            }
        }
        if (ans == -1) {
            for (int i = 3; i >= 1; i--) {
                if (ans == -1 && x % i == 0 && x / i >= 4) {
                    ans = x / i;
                    break;
                }
            }
        }
        if (ans == -1) { 
            printf("No such base\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
