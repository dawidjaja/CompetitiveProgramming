#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            ans += j / i;
        }
    }
    printf("%lld\n", ans * 4);
    return 0;
}
