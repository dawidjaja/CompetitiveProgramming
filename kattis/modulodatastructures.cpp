#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n, q, query, a, b, c, list[200005], add[1005][1005], d;

int main() {
	scanf("%d%d", &n, &q);
	while (q--) {
		scanf("%d", &query);
		if (query == 1) {
			scanf("%d%d%d", &a, &b, &c);
			if (b > sqrt(n)) {
				for (int i = a; i <= n; i += b) {
					list[i] += c;
				}
			} else {
				add[b][a] += c;
			}
		} else {
			scanf("%d", &d);
			long long ans = list[d];
			for (int i = 1; i <= sqrt(n); i++) {
				ans += add[i][d % i];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
