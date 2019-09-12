#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;

long long dp[5][100005], a[5], n, list[100005], ans, gede;

long long f(long long idx, long long skrg) {
	if(idx > 3 || skrg > n) {
		if(skrg > n && idx <= 3) {
			return LLONG_MIN;
		}
		return 0;
	} 
	if(dp[idx][skrg] != gede) {
		return dp[idx][skrg];
	}
	dp[idx][skrg] = max(f(idx + 1, skrg) + a[idx] * list[skrg], f(idx, skrg + 1));
	// printf("%lld %lld --> %lld\n", idx, skrg, dp[idx][skrg]);
	return dp[idx][skrg];
}

int main() {
	scanf("%lld%lld%lld%lld", &n, &a[1], &a[2], &a[3]);
	gede = pow(10, 18) * 3 + 5;
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &list[i]);
		for(long long j = 1; j <= 3; j++) {
			dp[j][i] = gede;
		}
	}
	ans = f(1, 1);
	printf("%lld\n", ans);
	return 0;
}