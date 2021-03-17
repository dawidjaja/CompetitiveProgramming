#include<bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int, int>
#define mp make_pair

using namespace std;

const int INF = 1e9;

bool cmp(pii a, pii b) {
    return mp(a.fs, b.sc) < mp(b.fs, a.sc);
}

int main() {
    int tc; 
    scanf("%d", &tc);
    while(tc--) {
        int n;
        scanf("%d", &n);
        vector<pii> dolls(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &dolls[i].fs, &dolls[i].sc);
        }

        sort(dolls.begin(), dolls.end(), cmp);

        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            h[i] = dolls[i].sc;
        }
        reverse(h.begin(), h.end());

        vector<int> lis(n + 1, INF);
        for (int i = 0; i < h.size(); i++) {
            *upper_bound(lis.begin(), lis.end(), h[i]) = h[i];
        }
        for (int i = 0; i <= n; i++) {
            if (lis[i] == INF) {
                printf("%d\n", i);
                break;
            }
        }
    }
}
