#include <algorithm>
#include <cstdio>

using namespace std;

int n, t, k, list[100005], ans;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &list[i]);
		}
		sort(list + 1, list + 1 + n);
		ans = list[n - k] - list[1];
		for(int i = 0; i <= k; i++) {
			ans = min(ans, list[n - k + i] - list[i + 1]);
		}
		// ans = min(list[n - k] - list[1], list[n] - list[k]);
		printf("%d\n", ans);
	}
	return 0;
}