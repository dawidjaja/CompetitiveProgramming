#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int low[100005], num[100005], ctr, p[100005][20], bri[100005][20], dlm[100005], n, m, a, b, q, c, ans, vis[100005];
vector<int> jln[100005], v[100005];
map<int, int> cek[100005];

void dfs(int skrg, int sblm) {
	low[skrg] = num[skrg] = ctr++;
//	printf("--asdf %d %d\n", jln[skrg][i],  skrg);
	for(int i = 0; i < jln[skrg].size(); i++) {
		if(num[jln[skrg][i]] == -1) {
			dfs(jln[skrg][i], skrg);
			if(low[jln[skrg][i]] > num[skrg]) {
				cek[skrg][jln[skrg][i]] = 1;
			}
			low[skrg] = min(low[skrg], low[jln[skrg][i]]);
		} else if(jln[skrg][i] != sblm) {
			low[skrg] = min(low[skrg], num[jln[skrg][i]]);
		}
	}
}

inline int LCA(int a, int b) {
	if(dlm[a] > dlm[b]) {
		swap(a, b);
	}
	for(int i = 18; i >= 0; i--) {
		if(p[b][i] != -1 && dlm[p[b][i]] >= dlm[a]) {
			b = p[b][i];
		}
	}
	if(a == b){
		return a;
	}
	for(int i = 18; i >= 0; i--) {
		if(p[b][i] != -1 && p[b][i] != p[a][i]) {
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[b][0];
}

void dfslg(int skrg, int sblm) {
	p[skrg][0] = sblm;
	vis[skrg] = 1;
	if(cek[sblm].count(skrg)) {
		bri[skrg][0] = 1;
	} else {
		bri[skrg][0] = 0;
	}
	if(sblm != -1) {
		dlm[skrg] = dlm[sblm] + 1;
	}
	for(int j = 1; j < 19; j++) {
		if(p[skrg][j-1] == -1) {
			for(int k = j; k < 19; k++) {
				p[skrg][k] = -1;
			}
			break;
		}
//		printf("------- %d ------\n", p[jln[skrg][i]][j-1]);
		p[skrg][j] = p[p[skrg][j-1]][j-1];
		bri[skrg][j] = bri[skrg][j-1] + bri[p[skrg][j-1]][j-1];
	}
	for(int i = 0; i < jln[skrg].size(); i++) {
		if(jln[skrg][i] != sblm && vis[jln[skrg][i]] == 0) {
			dfslg(jln[skrg][i], skrg);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		jln[a].push_back(b);
		jln[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) {
		num[i] = -1;
	}
	dlm[1] = 0;
	ctr = 1;
	for(int i = 0; i <= 18; i++) {
		p[1][i] = -1;
	}
	dfs(1, -1);
	dfslg(1, -1);
	scanf("%d", &q);
//	for(int i = 1; i <= n; i++){
//		printf("-- %d -> %d\n", i, dlm[i]);
//		for(int j = 0; j <= 18; j++) {
//			printf("------ %d --> %d %d\n", j, p[i][j], bri[i][j]);
//		}
//	}
	while(q--){
		scanf("%d%d", &a, &b);
		c = LCA(a, b);
//		printf("lca %d\n", c);
		ans = 0;
		for(int i = 18; i >= 0; i--) {
			if(p[a][i] != -1 && dlm[p[a][i]] >= dlm[c]) {
				ans += bri[a][i];
				a = p[a][i];
			}
		}

		for(int i = 18; i >= 0; i--) {
			if(p[b][i] != -1 && dlm[p[b][i]] >= dlm[c]) {
				ans += bri[b][i];
				b = p[b][i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
