#include <algorithm>
#include <cstdio>

using namespace std;

long long n, m, kcl[100005], ans, p[100005], x, y;

long long par(long long x) {
	if(p[x] == x) {
		return x;
	}
	return p[x] = par(p[x]);
}

int main() {
	scanf("%lld%lld", &n, &m);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &kcl[i]);
		p[i] = i;
	}
	for(long long i = 1; i <= m; i++) {
		scanf("%lld%lld", &x, &y);
		kcl[par(y)] = min(kcl[par(x)], kcl[par(y)]);
		p[par(x)] = par(y);
	}
	// for(int i = 1; i <= n; i++) {
	// 	printf("-- %lld %lld --\n", par(i), kcl[par(i)]);
	// }
	for(long long i = 1; i <= n; i++) {
		if(par(i) == i) {
			ans += kcl[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}