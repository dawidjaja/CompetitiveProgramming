#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (c % (__gcd(a, b)) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
