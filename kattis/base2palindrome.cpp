#include <bits/stdc++.h>

using namespace std;

int n, goback;

bool allone(int x) {
    if (x == 0) return true;
    return ((x & (x + 1)) == 0);
}

bool oneone(int x) {
    return ((x & (x - 1)) == 0);
}

int main() {
    scanf("%d", &n);
    int x = 0;
    int mid = 1;
    int goback = 1;
    if (n == 1) {
        printf("1\n");
    } else {
        while (--n) {
            if ((!allone(x) && mid == -1) || mid == 1) {
                if (mid == 1) {
                    mid = allone(x) ? -1 : 0;
                }

                x++;

                if (oneone(x)) {
                    goback = x;
                }
            } else if (allone(x) && mid == -1) {
                x = goback;
                mid = 0;
            } else if (mid == 0) {
                mid++;
            }
        }
        vector<int> vbit;
        while (x) {
            vbit.push_back(x % 2);
            x /= 2;
        }

        int ans = 0;
        for (int i = vbit.size() - 1; i >= 0; i--) {
            ans *= 2;
            ans += vbit[i];
        }
        if (mid != -1) {
            ans *= 2;
            ans += mid;
        }
        for (int i = 0; i < vbit.size(); i++) {
            ans *= 2;
            ans += vbit[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
