#include <bits/stdc++.h>

using namespace std;

int main() {
    scanf("%d", &n);
    getchar();
    scanf("%s", s);
    int sz = strlen(s);
    for (int i = sz - 1; i >= 0; i--) {
        bit[sz - 1 - i] = s[i] - '0';
    }
    return 0;
}
