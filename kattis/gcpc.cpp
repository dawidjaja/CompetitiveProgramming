#include <bits/stdc++.h>

using namespace std;

int main() {
    scanf("%d%d", &n, &m);
    int ans = 0;
    while (m--) {
        scanf("%d%d", &t, &p);
        if (t == 1) {
            for (auto it = higher.begin(); it != higher.end(); it++) {
                if(score[*it] < score[1]) {
                    ans--;
                    higher.erase(*it);
                }
            }
        }
    }
    return 0;
}
