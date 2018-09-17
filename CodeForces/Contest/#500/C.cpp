#include <algorithm>
#include <cstdio>

using namespace std;

long long n, ans, list[200005];

int main() {
	scanf("%lld", &n);
	for(long long i = 0; i < n * 2; i++) {
		scanf("%lld", &list[i]);
	}
	sort(list, list + n * 2);
	ans = (list[n - 1] - list[0]) * (list[n * 2 - 1] - list[n]);
	for(long long i = 1; i < n; i++) {
		ans = min(ans, (list[2 * n - 1] - list[0]) * (list[i + n - 1] - list[i]));
	}
	printf("%lld\n", ans);
}