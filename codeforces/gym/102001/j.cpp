#include <bits/stdc++.h>

using namespace std;

int main() {
    scanf("%d", &n);

    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%s", name[i]);
    }

    for (int i = 0; i < n; i++) {
        int sz = strlen(name[i]);
        int maxmask = 1 << sz;
        for (int j = 0; j < maxmask; j++) {
            string s = "";
            for (int k = 0; k < sz; k++) {
                if (j & (1 << k)) {
                    s += name[i][k];
                }
            }
            names[i].push_back(s);
        }
        sort(names[i].begin(), names[i].end());
    }
    return 0;

}
