#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

pii num[100005];
int n, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i].fs);
        num[i].sc = i;
    }
    sort(num, num + n);
    ans = n;
    for (int i = 1; i < n; i++) {
        if (num[i - 1].fs == num[i].fs) {
            ans = min(ans, num[i].sc - num[i - 1].sc);
        }
    }
    printf("%d\n", ans);
    return 0;
}
