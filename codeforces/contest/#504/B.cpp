#include <algorithm>
#include <cstdio>

using namespace std;

long long n, k;

int main() {
	scanf("%lld%lld", &n, &k);
	long long tmp = k - n;
	if (tmp >= n) {
		printf("0\n");
	} else if (tmp <= 0) {
		printf("%lld\n", ((k / 2) - 1) + (k & 1));
	} else {
		printf("%lld\n", (n - tmp + 1) / 2);
	}
	return 0;
}