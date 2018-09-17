#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int vis[5005], a, n, d, l, s, dep;
vector<int> v[5005], kcl, gede;

int dfs(int x, int sblm) {
	int ret = vis[x] = vis[sblm] + 1;
	// printf("%d -> %d, %d -> %d\n", x, vis[x], sblm, vis[x]);
	for(int i = 0; i < v[x].size(); i++) {
		if(v[x][i] != sblm) {
			ret = max(ret, dfs(v[x][i], x));
		}
	}
	return ret;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; i++) {
			v[i].clear();
			scanf("%d", &d);
			for(int j = 1; j <= d; j++) {
				scanf("%d", &a);
				v[i].push_back(a);
			}
		}
		vis[0] = 0;
		l = 1;
		s = 5001;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				vis[j] = -1;
			}
			dep = dfs(i, 0);
			// printf("%d --> %d\n", i, dep);
			if(dep > l) {
				l = dep;
				gede.clear();
				gede.push_back(i);
			} else if(dep == l) {
				gede.push_back(i);
			}
			if(dep < s) {
				s = dep;
				kcl.clear();
				kcl.push_back(i);
			} else if(dep == s) {
				kcl.push_back(i);
			}
		}
		rpintf("Best Roots :");
		for(int i = 0; i < kcl.size(); i++) {
			printf(" %d", kcl[i]);
		}
		printf("\n");
		printf("Worst Roots :");
		for(int i = 0; i < gede.size(); i++) {
			printf(" %d", gede[i]);
		}
		printf("\n");
	}
	return 0;
}