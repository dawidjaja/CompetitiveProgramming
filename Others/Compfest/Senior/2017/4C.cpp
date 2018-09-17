#include <algorithm>
#include <cstdio>
#include <vector>

#define MOD 1000000007

using namespace std;

long long ans;
int list[50005], vis[50005], n, m, t, a, b;
vector <int> v[50005];

void dfs(int skrg, int x, int sblm) {
	if(vis[skrg]) {
		ans *= x - list[skrg];
		// printf("-- %d %d %d %d --\n", skrg, sblm, list[skrg], x);
		ans = ans % MOD;
	} else {
		vis[skrg] = 1;
		list[skrg] = x;
		for(int i = 0; i < v[skrg].size(); i++) {
			if(v[skrg][i] == sblm || list[v[skrg][i]] > list[skrg]) {
				continue;
			}
			dfs(v[skrg][i], x + 1, skrg);
		}
	}
	return;
}

int main(){ 
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		ans = 1;
		for(int i = 0; i <= n; i++) {
			v[i].clear();
			list[i] = 0;
			vis[i] = 0;
		}
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i = 0; i < n; i++) {
			if(vis[i] == 0) {
				// printf("%d\n", i);
				dfs(i, 0, -1);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}