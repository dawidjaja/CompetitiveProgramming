#include <algorithm>
#include <cstdio>

using namespace std;

long long t, n, l, r, dp[25][25][25], ans;

long long f(long long skrg, long long kiri, long long kanan) {
	if(skrg == 1 && kiri == 1 && kanan == 1) {
		return 1;
	}
	if(kiri == 0 || kanan == 0 || skrg == 0) {
		return 0;
	}
	if(dp[skrg][kiri][kanan] != -1) {
		return dp[skrg][kiri][kanan];
	}
	long long &ret = dp[skrg][kiri][kanan];
	ret = f(skrg - 1, kiri - 1, kanan) + f(skrg - 1, kiri, kanan - 1) + f(skrg - 1, kiri, kanan) * (skrg - 2);
	return ret;
}

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld%lld", &n, &l, &r);
		for(long long i = 0; i <= n; i++) {
			for(long long j = 0; j <= l; j++) {
				for(long long k = 0; k <= r; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		ans = f(n, l, r);
		printf("%lld\n", ans);
	}
	return 0;
}