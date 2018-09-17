#include <algorithm>
#include <cstdio>

#define MOD (long long)1000000007

using namespace std;

long long ans, n, m;

int main() {
	scanf("%lld%lld", &n, &m);
	ans = 1;
	for(int i = 1; i <= m; i++) {
		ans *= n;
		ans = ans % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
