#include <algorithm>
#include <cstdio>

using namespace std;

int dfs(int skrg, int sblm) {
	int ctr = 0;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm) {
			if(vis[v[skrg][i]] == 1) {
				ttk.push_back(v[skrg][i]);
				list[skrg][v[skrg][i]]++;
				ctr++;
			}
		}
	}
	return ctr - krg;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			krg = 0;
			dfs(i, 0, 0);
		}
	}
	return 0;
}