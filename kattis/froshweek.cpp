#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, ans, bit[1000005], list[1000005];
pii tmp[1000005];

int getBit(int x) {
    int ret = 0;
    for (int i = x; i >= 1; i -= (i & -i)) {
        ret += bit[i];
    }
    return ret;
}

void updateBit(int x) {
    for (int i = x; i <= n; i += (i & -i)) {
        bit[i]++;
    }
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp[i].fs);
        tmp[i].sc = i;
    }

    sort(tmp + 1, tmp + n + 1);

    for (int i = 1; i <= n; i++) {
        list[tmp[i].sc] = i;
    }
    
    ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += getBit(list[i]);
        updateBit(list[i]);
    }
    printf("%d\n", ans);
    return 0;
}
