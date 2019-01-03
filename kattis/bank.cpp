#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

pii cust[10005];
int sched[50], ans, n, t;

bool cmp(pii a, pii b) {
    return a.fs > b.fs;
}
int getPos(int x) {
    if (x == -1 || sched[x] == 0) {
        return x;
    }
    return getPos(x - 1);
}

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &cust[i].fs, &cust[i].sc);
    }
    sort(cust, cust + n, cmp);
    for (int i = 0; i < n; i++) {
        int x = getPos(cust[i].sc);
        if (x >= 0) {
            sched[x] = 1;
            ans += cust[i].fs;
        }
    }
    printf("%d\n", ans);
    return 0;
}
