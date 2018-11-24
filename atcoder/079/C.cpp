#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, a, b, vis[200005];
vector <int> v[200005];

bool dfs(int skrg, int jrk) {
	if(vis[skrg] == 1) {
		return false;
	} else {
		vis[skrg] = 1;
	}
	if(skrg == n) {
		return true;
	}
	if(jrk > 2) {
		return false;
	}
	bool ret = false;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(dfs(v[skrg][i], jrk + 1) == true) {
			ret = true;
			break;
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if(dfs(1, 0)) {
		printf("POSSIBLE\n");
	} else {
		printf("IMPOSSIBLE\n");
	}
	return 0;
}