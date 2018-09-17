#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, x, t;

int main() {
	scanf("%d", &t);
	while(t--) {
		long long ans = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%d", &x);
				ans += x;
				// printf("%lld ", ans);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}