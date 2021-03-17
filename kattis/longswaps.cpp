#include <bits/stdc++.h>

using namespace std;

int main() {
    char s[205];
    int n;

    scanf("%s", s);
    scanf("%d", &n);
    int l = strlen(s);

    vector <char> srtd;

    for (int i = 0; i < l; i++) {
        srtd.push_back(s[i]);
    }

    sort(srtd.begin(), srtd.end());

    int check = 1;
    for (int i = l - n; i < n; i++) {
        if (srtd[i] != s[i]) {
            check = 0;
            break;
        }
    }

    if (check == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
