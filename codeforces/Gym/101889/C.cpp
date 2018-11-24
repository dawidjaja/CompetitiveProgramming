#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int k, n, list[10005], freq[10005], gde, kcl;
vector <int> s, l;

int main () {
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &list[i]);
        freq[list[i]]++;
    }
    gde = freq[1];
    kcl = freq[1];
    for (int i = 1; i <= k; i++) {
        kcl = min(kcl, freq[i]);
        gde = max(gde, freq[i]);
    }
    for (int i = 1; i <= k; i++) {
        if (freq[i] == kcl) {
            s.push_back(i);
        }
        if (freq[i] == gde) {
            l.push_back(i);
        }
    }
    if ((n % k) == 1) {
        if (s.size() == k - 1 && l.size() == 1) {
            printf("-%d\n", l[0]);
        } else {
            printf("*\n");
        }
    } else if (n % k == 0) {
        if (s.size() == 1 && l.size() == 1) {
            printf("-%d +%d\n", l[0], s[0]);
        } else {
            printf("*\n");
        }
    } else if ((n % k) == k - 1) {
        if (s.size() == 1 && l.size() == k - 1) {
            printf("+%d\n", s[0]);
        } else {
            printf("*\n");
        }
    } else {
        printf("*\n");
    }
    return 0;
}
