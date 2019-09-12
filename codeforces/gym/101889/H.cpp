#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int a, b, c, d, e, f;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    scanf("%d%d%d", &d, &e, &f);
    printf("%d\n", max(d - a, 0) + max(e - b, 0) + max(f - c, 0));
    return 0;
}
