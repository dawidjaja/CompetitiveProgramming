#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

void dfs(int skrg) {
	on[skrg] = 1;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(on[v[skrg][i]] == 1) {
			
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &a);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &qw, &er, &cc);
		v[qw].push_back({er, cc});
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			dfs(i);
		}
	}
	return 0;
}