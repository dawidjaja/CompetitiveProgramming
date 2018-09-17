#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long>

using namespace std;

long long low[100005], ttl[100005], num[100005], ctr, n, m, a, b, temp, ans;
vector <long long> v[100005];
vector <pii> tree[100005];

long long dfs(long long skrg, long long sblm) {
	long long ret;
	low[skrg] = num[skrg] = ctr++;
	ret = 1;
	for(long long i = 0; i < v[skrg].size(); i++) {
		long long u = v[skrg][i];
		if(num[u] == 0) {
			long long gede = dfs(u, skrg);
			ret += gede;
			tree[skrg].push_back(mp(u, gede));
			low[skrg] = min(low[skrg], low[u]);
		} else if(u != sblm) {
			low[skrg] = min(low[skrg], num[u]);
		}
	}
	ttl[skrg] = ret;
	return ret;
}

int main() {
	scanf("%lld%lld", &n, &m);
	ctr = 1;
	for(long long i = 1; i <= m; i++) {
		scanf("%lld%lld", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, -1);
	temp = 0;
	ans = n-1;
	if(tree[1].size() > 1) {
		for(long long i = 0; i < tree[1].size(); i++) {
			ans += temp * ttl[tree[1][i].fs];
			temp += ttl[tree[1][i].fs];
		}
	}
	printf("%lld\n", ans*2);
	for(long long i = 2; i <= n; i++) {
		ans = n-1;
		long long ada = n - ttl[i];
		long long pts = 0;
//		printf("--- %lld %d\n", i, tree[i].size());
		for(long long j = 0; j < tree[i].size(); j++) {
			long long u = tree[i][j].fs;
			long long sz = tree[i][j].sc;
//			printf("%lld %lld ---- \n", sz, ada);
			if(low[tree[i][j].fs] >= num[i]) {
				//articulation point bwt dia
				ans += sz * pts;
				ans += sz * ada;
				pts += sz;
			} else {
				ans += sz * pts;
				ada += sz;
			}
		}
		printf("%lld\n", ans*2);
	}
	return 0;
}
