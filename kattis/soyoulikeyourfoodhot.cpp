#include <bits/stdc++.h>

using namespace std;

int main() {
    double ta, tb, tc;
    cin >> ta >> tb >> tc;
    long long a, b, c;
    a = ceil(ta * 10000);
    b = ceil(tb * 10000);
    c = ceil(tc * 10000);
    int ans = 0;
    int up = ceil(a / b) + 1;
    for (int i = 0; i < up; i++) {
        if (b * i > a) {
            break;
        }

        long long tmp = a - b * i;
        long long x = floor(tmp / c);
        if (x * c == tmp) {
            printf("%d %d\n", i, x);
            ans++;
        }
    }
    if (ans == 0) printf("none\n");
    return 0;
}
