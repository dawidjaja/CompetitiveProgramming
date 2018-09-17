#include <algorithm>
#include <cstdio>

#define MOD 1000000007

using namespace std;

int n, m, dp[1000005], a, b;

int main() {
	scanf("%d%d", &n, &m);
	a = 2;
	b = m + 3;
	dp[2*m] = 1;
	for(int i = 2*m + 1; i <= n; i++) {
		if(i-a >= 0) {
			dp[i] += dp[i-a];
		}
		dp[i] = dp[i] % MOD;
		if(i-b >= 0) {
			dp[i] += dp[i-b];
		}
		dp[i] = dp[i] % MOD;
		if(i%2 == 0) {
			dp[i] += dp[i/2];
			dp[i] = dp[i] % MOD;
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
