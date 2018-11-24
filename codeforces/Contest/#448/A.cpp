#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n, list[100005], ttl, ps[363], ans;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		ps[i] = ps[i - 1] + list[i];
	}
	ans = 360;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			ans = min(ans, abs(360 - 2 * (ps[j] - ps[i - 1])));
		}
	}
	printf("%d\n", ans);
	return 0;
}