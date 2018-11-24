#include <algorithm>
#include <cstdio>

#define MOD 1000000007

using namespace std;

long long n, m;

long long itung(int a, int b) {
	if(a > b) {
		swap(a, b);
	}
	long long ret = 1;
	for(int i = 2; i <= a; i++) {
		ret *= i;
		ret = ret % MOD;
	}
	ret *= ret;
	ret = ret % MOD;
	for(int i = a + 1; i <= b; i++) {
		ret *= i;
		ret = ret % MOD;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	if(abs(n-m) > 1) {
		printf("0\n");
		return 0;
	} else if(n == m) {
		printf("%lld\n", (2*itung(n, m)) % MOD);
	} else {
		printf("%lld\n", itung(n, m));
	}
	return 0;
}