#include <algorithm>
#include <cstdio>

#define MOD 1000000007

using namespace std;

int n;
long long ans;

long long pngkt(long long x, long long y) {
	if(y == 1) {
		return x;
	}
	if(y == 0) {
		return 1;
	}
	long long ret;
	ret = pngkt(x, y/2);
	ret *= ret;
	ret = ret % MOD;
	if(y & 1) {
		ret *= x;
		ret = ret % MOD;
	}
	return ret;
}

long long combi(long long a, long long b) {
	long long ret;
	ret = 1;
	for(int i = 0; i < b; i++) {
		ret *= a - i;
		ret = ret % MOD;
	}
	for(int i = 1; i <= b; i++) {
		ret *= pngkt(i, MOD - 2);
		ret = ret % MOD;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	ans = 0;
	for(int i = 0; i <= n/2; i++) {
		ans += (combi(n, i) * combi(n - i, i)) % MOD;
		// printf("-- %lld %lld --\n", combi(n, i), combi(n - i, i));
		ans = ans % MOD;
		// printf("%lld\n", ans); 
	}
	printf("%lld\n", ans);
	return 0;
}