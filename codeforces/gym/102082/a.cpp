#include <bits/stdc++.h>

using namespace std;

string s, st;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> st;
        if (st < s) {
            printf("-\n");
        } else {
            printf("+\n");
        }
    }
}
