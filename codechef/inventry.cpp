#include <algorithm>
#include <stack>
#include <cstdio>

using namespace std;

int main() {
    long long tc;
    scanf("%lld", &tc);
    while (tc--) {
        long long n;
        char list[100005];
        scanf("%lld", &n);
        getchar();
        long long box = 0;
        for (long long i = 0; i < n; i++) {
            list[i] = getchar();
            if (list[i] == '#') {
                box++;
            }
        }
        if (box != n && list[n - 1] == '#') {
            printf("-1\n");
            continue;
        }
        long long id = 0;
        long long ans = 0;
        while (list[id] == '#') {
            id++;
        }
        for (long long i = id; i < n - 1; i++) {
            if (list[i + 1] != '#') {
                continue;
            }
            long long tmp = i + 1;
            long long ctr = 1;
            stack <long long> s;
            s.push(tmp);
            long long x = 1;
            while (ctr > 0 && tmp + 1 < n) {
                tmp++;
                if (list[tmp] == '#') {
                    s.push(tmp);
                    ctr++;
                    x++;
                } else {
                    ctr--;
                }
            }
            if (ctr > 0) {
                x = 0;
            }
            for (int j = tmp - 1; j > i; j -= 2) {
                ans += 2 * j;
                ans -= s.top();
                s.pop();
            }
            ans -= (2 * id + x - 1) * x / 2;
            id += x;
            i  = tmp - 1;
        }
        if (id != box) {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
