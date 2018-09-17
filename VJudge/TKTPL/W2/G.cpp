#include <algorithm>
#include <cstdio>
#include <map>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int t, s, n, m, cek[100005], a, b, ctr, vis[10005];
map <int,int> cap[10005];

bool dfs(int skrg) {
	if(skrg == t) {
		return true;
	}
	vis[skrg] = 1;
	for(auto it = cap[skrg].begin(); it != cap[skrg].end(); ++it) {
		int i = it->fs;
		int val = it->sc;
		if(val > 0 && vis[i] == 0) {
			bool tmp = dfs(i);
			if(tmp) {
				cap[skrg][i]--;
				cap[i][skrg]++;
				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	ctr = 0;
	while(n != 0 && m != 0) {
		ctr++;
		for(int i = 1; i <= n; i++) {
			cap[i].clear();
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			cap[a][b]++;
			cap[b][a]++;
		}
		scanf("%d%d", &s, &t);
		for(int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		if(dfs(s)) {
			for(int i = 1; i <= n; i++) {
				vis[i] = 0;
			}
			if(dfs(s)) {
				printf("Case %d: YES\n", ctr);
				scanf("%d%d", &n, &m);
				continue;
			}
		}
		printf("Case %d: NO\n", ctr);
		scanf("%d%d", &n, &m);
	}
	return 0;
}