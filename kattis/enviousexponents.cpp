#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    scanf("%lld%lld", &n, &k);
    int bctr = 0;
    for (int i = 19; i >= 0; i--) {
        if (n & (1 << i)) {
            bctr++;
            if (bctr == k) {
                tmp = i;
                break;
            }
        }
    }
    return 0;
}
