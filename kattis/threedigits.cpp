#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;

int fact(int x) {
    return x == 1 ? 1 : x * fact(x - 1);
}

int nolead(int x) {
    while (x % 10 == 0) x /= 10;
    return x;
}

int pngkt(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b & 1) return (a * pngkt(a, b - 1)) % 1000;
    int tmp = pngkt(a, b / 2);
    return (tmp * tmp) % 1000;
}

int ans;

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 7) {
        printf("%d\n", nolead(fact(n)));
        return 0;
    }
    ans = 1;
    for (int i = 1; i <= 999; i++) {
        ans *= i;
        while (ans % 10 == 0)
            ans /= 10;
        ans = ans % 1000;
    }
    ans = pngkt(ans, n / 1000);
    n = n % 1000;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        while (ans % 10 == 0)
            ans /= 10;
        ans = ans % 1000;
    }
    cout << ans;
    //cout << setfill('0') << setw(3) << ans;
    cout << endl;
    return 0;
}
