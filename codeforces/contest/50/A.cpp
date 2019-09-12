#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long a, b;

int main() {
    scanf("%lld%lld", &a, &b);
    long long out = b / a;
    if (b % a) {
    	out++;
    }
    printf("%lld\n", out);
    return 0;
}

