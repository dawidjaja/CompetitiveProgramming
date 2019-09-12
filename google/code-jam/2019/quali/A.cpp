#include <bits/stdc++.h>

using namespace std;

int tc;

int main() {
    scanf("%d", &tc);
    getchar();
    for (int _ = 1; _ <= tc; _++) {
        vector<int> v, a, b;
        char c = getchar();
        while ('0' <= c && c <= '9') {
            v.push_back(c - '0');
            c = getchar();
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 4) {
                a.push_back(3);
                b.push_back(1);
            } else {
                a.push_back(v[i]);
                b.push_back(0);
            }
        }
        printf("Case #%d: ", _);
        bool lead = true;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != 0) lead = false;
            if (lead && a[i] == 0) continue;
            printf("%d", a[i]);
        }
        printf(" ");
        lead = true;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] != 0) lead = false;
            if (lead && b[i] == 0) continue;
            printf("%d", b[i]);
        }
        printf("\n");
    }
    return 0;
}
