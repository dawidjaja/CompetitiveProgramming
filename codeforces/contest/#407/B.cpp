#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

long long vis[1000005], ctr, n, m, a, b, ans, cc, p[1000005], loop, blkg;
vector <long long> v[1000005];

int par(int x) {
	if(p[x] == x) {
		return x;
	} else {
		return p[x] = par(p[x]);
	}
}

int main() {
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		p[i] = i;
	}
	for(long long i = 1; i <= m; i++) {
		scanf("%lld%lld", &a, &b);
		vis[a] = vis[b] = 1;
		if(a == b) {
			// lup[a] = 1;
			loop++;
		} else {
			v[a].push_back(b);
			v[b].push_back(a);
		}
		p[par(a)] = par(b);
	}
	cc = 2;
	for(int i = 1; i <= n; i++) {
		if(cc == 2) {
			if(vis[i] == 1) {
				blkg = i;
				cc = 1;
			}
		} else if(vis[i] == 1 && par(i) != par(blkg)) {
			printf("0\n");
			return 0;
		}
	}
	for(long long i = 1; i <= n; i++) {
		ans += 1LL * v[i].size() * (v[i].size() - 1) / 2;
		// printf("-- %lld --\n", ans);
	}
	ans += loop * (loop - 1) / 2;
	ans += loop * (m - loop);
	printf("%lld\n", ans);
	return 0;
}