#include<bits/stdc++.h>
using namespace std;

int main() {
    int nQ; scanf("%d", &nQ);
    while (nQ--) {
        int n, k, p; scanf("%d%d", &n, &k);
        while (n--) {
            scanf("%d", &p);
            if (p > 1) k--;
        }
        printf(k < 0 ? "NO\n" : "YES\n");
    }
}
