#include <cstdio>
#include <algorithm>

#define MOD 1000000009

using namespace std;

long long fak[360100], n, m, l, r, t, ans;

long long pngkt(long long a, long long b) {
	if(a <= 1) {
		return a;
	}
	if(b == 1) {
		return a;
	}
	long long ret;
	ret = pngkt(a, b/2);
	ret *= ret;
	ret = ret % MOD;
	if(b & 1) {
		ret *= a;
		ret = ret % MOD;
	}
	return ret;
}

long long combi(long long a, long long b) {
	long long ret;
	if (b == 0 || a == b) {
		// printf("0 --> %lld %lld\n", a, b);
		return 1;
	}
	ret = fak[a];
	if(fak[b]) {
		ret *= pngkt(fak[b], MOD - 2);
		ret = ret % MOD;
	}
	if(fak[a - b]) {
		ret *= pngkt(fak[a - b], MOD - 2);
		ret = ret % MOD;
	}
	// printf("----- %lld C %lld == %lld\n", a, b, ret);
	return ret;
}

int main() {
	scanf("%lld", &t);
	fak[1] = 1;
	for(int i = 2; i <= 360010; i++) {
		fak[i] = (fak[i - 1] * i) % MOD;
	}
	while(t--) {
		scanf("%lld%lld%lld%lld", &n, &m, &l, &r);
		long long a, b, c, d;
		// printf("a ");
		a = combi(n - 1, m - 1);
		// printf("b ");
		b = combi(n + l - 1, m - 1);
		// printf("c ");
		c = combi(n + r - 1, m + r - 1);
		// printf("d ");
		d = combi(n + l + r - 1, m + r - 1);
		ans =  a + d - b - c;
		ans += MOD + MOD;
		ans = ans % MOD;
		// printf("-- %lld %lld %lld %lld --\n", a, b, c, d);
		printf("%lld\n", ans);
	}
	return 0;
}