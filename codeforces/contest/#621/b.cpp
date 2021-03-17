#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;
int a[100005];

int main() {
    int tc;
    scanf("%d", &tc);

    while (tc--) {
        int n, x;
        scanf("%d%d", &n, &x);

        set <int> s;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }
        sort(a, a + n);


        if (s.count(x)) {
            printf("1\n");
            continue;
        }
        int ans;

        ans = x / a[n - 1];
        if (x % a[n - 1] != 0) {
            if (ans == 0) {
                ans++;
            }
            ans += 1;
        }

        printf("%d\n", ans);

        /*
        for (int i = n - 1; i >= 0; i--) {
            x -= a[i];
            if (x <= 0) {
                if (i == n - 1 && x < 0) {
                    x = -x;
                    continue;
                }
                ans = n - i;
                break;
            }
        }
        */
        //printf("%d\n", ans);
    }

    return 0;
}
