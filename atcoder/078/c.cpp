#include <algorithm>
#include <cstdio>

using namespace std;

long long n, list[200005], ps[200005], sf[200005], ans, a, b, l, r;

int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &list[i]);	
	}
	for(int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + list[i];
	}
	for(int i = n; i >= 1; i--) {
		sf[i] = sf[i + 1] + list[i];
	}
	ans = 2000000001;
	for(int i = 1; i < n; i++) {
		ans = min(ans, abs(ps[i] - sf[i + 1]));
	}
	printf("%lld\n", ans);
	return 0;
}