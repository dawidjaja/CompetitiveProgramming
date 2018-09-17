#include <algorithm>
#include <cstdio>

using namespace std;

long long dp[405][205][205], ans;
int n;
char s[505];
const long long MOD = 1000000007;

long long pwr(long long a, long long b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	long long tmp = pwr(a, b / 2);
	tmp *= tmp;
	tmp = tmp % MOD;
	if (b & 1) {
		tmp *= a;
		tmp = tmp % MOD;
	}
	return tmp;
}

long long f(int size, int l, int r) {
	if (size <= 0) {
		if (l > r && size == 0) {
			return 1;
		} else {
			return 0;
		}
	}
	long long &ret = dp[size][l][r];
	if (ret != -1) {
		return ret;
	}
	if (l > r) {
		ret = pwr(26, size / 2 + (size & 1));
	} else if (s[l] == s[r]) {
		ret = f(size - 2, l + 1, r - 1);
		ret += 25 * f(size - 2, l, r);
		ret = ret % MOD;
	} else {
		ret = f(size - 2, l + 1, r);
		ret += f(size - 2, l, r - 1);
		ret = ret % MOD;
		ret += 24 * f(size - 2, l, r);
		ret = ret % MOD;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		s[i] = getchar();
	}
	for (int i = 0; i <= 2*n; i++) {
		for (int j = 0; j <= n; j++) {
			 for (int k = 0; k <= n; k++) {
				 dp[i][j][k] = -1;
			 }
		}
	}
	ans = f(n * 2, 0, n - 1);
	printf("%lld\n", ans);
}

