#include <algorithm>
#include <cstdio>

using namespace std;

long long n, list[55], b[55], m, ans[10];

int main() {
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &list[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%lld", &b[i]);
	}
	sort(list + 1, list + 1 + n);
	sort(b + 1, b + 1 + m);
	ans[1] = list[1] * b[1];
	ans[2] = list[2] * b[1];
	ans[3] = list[n] * b[m];
	ans[4] = list[n - 1] * b[m];
	sort(ans + 1, ans + 5);
	printf("%lld\n", ans[3]);
	return 0;
}