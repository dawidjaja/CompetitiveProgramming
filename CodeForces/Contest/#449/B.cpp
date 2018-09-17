#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long k, MOD, ctr, ans, tmp, bnyk;

long long balik(long long xx, long long idx) {
	long long tmp = 0;
	long long x = xx;
	for(long long i = 1; i <= idx; i++) {
		tmp *= 10;
		tmp += x % 10;
		x /= 10;
	}
	tmp = tmp % MOD;
	// printf("-- %lld %lld --> %lld --\n", xx, idx, tmp);
	return tmp;
}

int main() {
	// while(true) {
	// 	scanf("%lld%lld", &k, &MOD);
	// 	printf("%lld\n", balik(k, MOD));
	// }
	scanf("%lld%lld", &k, &MOD);
	ctr = 1;
	while(k > 0) {
		tmp = pow(10, ctr - 1) * 9;
		bnyk = pow(10, ctr);
		// printf("%lld bnyk]\n", bnyk);
		for(long long i = pow(10, ctr - 1); i <= bnyk - 1; i++) {
			// printf("%lld %lld-%lld\n", ctr, i, balik(i, ctr));
			ans += i * bnyk;
			ans += balik(i, ctr);
			ans = ans % MOD;
			k--;
			if(k == 0) {
				break;
			}
		}
		ctr++;
	}
	printf("%lld\n", ans);
	return 0;
}