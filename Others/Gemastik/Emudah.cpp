#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

long long t, n, m, a[1005], b[1005], c[1005];

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld", &n, &m);
		ans = LLONG_MAX;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		for(int j = 1; j <= n; j++) {
			scanf("%lld", &b[j]);
		}
		for(int i = 0; i < m; i++) {
			scanf("%lld", &m[i]);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				ans = min(ans, a[i] * b[j] + c[(a[i] * b[j]) % m]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}