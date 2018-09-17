#include <algorithm>
#include <cstdio>

#define MOD 1000000007

using namespace std;

long long t, n, k, dp[105];
char kata[105];

long long pngkt(long long x, long long y)
{
	long long ret = 1;
	while (y > 0)
	{
		if (y & 1) {
			ret = ret * x;
			ret = ret % MOD;
		}
		y = y >> 1;
		x = x * x;
		x = x % MOD;
	}
	return ret;
}

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%s%lld%lld", kata, &n, &k);
		if(kata[0] - 'a' + 1 > k || kata[1] - 'a' + 1 > k) {
			printf("0\n");
			continue;
		}
		if(kata[0] == kata[1]) {
			dp[0] = 1;
			dp[1] = 1;
			for(int i = 2; i <= n; i++) {
				dp[i] = dp[i - 1] * (k * k) % MOD;
				// printf("%lld\n", dp[i]);
				dp[i] += ((k - 1) * (k - 1)) * (i > 2 ? ((pngkt(k, (i - 2) * 2) - dp[i - 2] + MOD) % MOD) : 1) % MOD;
				// printf("%lld\n", dp[i]);
				dp[i] += (i >= 3 ? ((k - 1) * (k - 1)) * dp[i - 3] : 1) * ((k - 1) * (k - 1)) * 4;
				// printf("%lld\n", dp[i]);
				dp[i] += 2 * (k - 1) * dp[i - 2];
				dp[i] = dp[i] % MOD;
			}
			printf("%lld\n", dp[n]);
		} else {
			dp[0] = 1;
			dp[1] = 2;
			for(int i = 2; i <= n; i++) {
				dp[i] = dp[i - 1] * (k * k) % MOD;
				printf("%lld\n", dp[i]);
				dp[i] += 2 * ((k - 1) * (k - 1)) * (i > 2 ? ((pngkt(k, (i - 2) * 2) - dp[i - 2] + MOD) % MOD) : 1) % MOD;
				printf("%lld\n", dp[i]);
				dp[i] += (k - 2) * (k - 2) * 4 * dp[i - 2];
				dp[i] = dp[i] % MOD;
				printf("%lld\n", dp[i]);
				dp[i] += dp[i - 2] * ((k - 1) * (k - 1) + 1);
				dp[i] = dp[i] % MOD;
				printf("%lld\n", dp[i]);
			}
			printf("%lld\n", dp[n]);
		}
	}
	return 0;
}