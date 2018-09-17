#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, p[30005], sz[30005], a, b, t, ans;

int par(int x) {
	if(p[x] == x) {
		return x;
	} else {
		p[x] = par(p[x]);
		return p[x];
	}
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			p[i] = i;
			sz[i] = 1;
		}
		ans = 1;
		while(m--) {
			scanf("%d%d", &a, &b);
			if(par(a) == par(b)) {
				continue;
			} else {
				sz[par(a)] += sz[par(b)];
				ans = max(ans, sz[par(a)]);
				p[par(b)] = par(a);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}