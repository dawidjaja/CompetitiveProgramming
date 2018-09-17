#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>
using namespace std;

int vis[300005], fis[300005], arah[300005], n, m, s, uu, vv, t, ctr, gde, kcl;
vector <ppi> bi[300005];
vector <int> v[300005];

int dfs(int skrg, int sblm) {
	vis[skrg] = 1;
	for(int i = 0; i < bi[skrg].size(); i++) {
		if(bi[skrg][i].fs.fs != sblm && vis[bi[skrg][i].fs.fs] == 0) {

			arah[bi[skrg][i].sc] = bi[skrg][i].fs.sc;
			// printf("--- %d %d %d %d---\n", skrg, bi[skrg][i].fs.fs, bi[skrg][i].fs.sc, bi[skrg][i].sc);

			dfs(bi[skrg][i].fs.fs, skrg);
		}
	}

	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm && vis[v[skrg][i]] == 0) {
			dfs(v[skrg][i], skrg);
		}
	}
}

int dd(int skrg, int sblm) {
	fis[skrg] = 1;

	for(int i = 0; i < bi[skrg].size(); i++) {
		arah[bi[skrg][i].sc] = 1 - bi[skrg][i].fs.sc;
	}
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm && fis[v[skrg][i]] == 0) {
			dd(v[skrg][i], skrg);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &t, &uu, &vv);
		if(t == 1) {
			// directed
			v[uu].push_back(vv);
		} else {
			bi[uu].push_back({{vv, 0}, ++ctr});
			bi[vv].push_back({{uu, 1}, ctr});
		}
	}
	dfs(s, 0);
	for(int i = 1; i <= n; i++) {
		if(vis[i]) {
			gde++;
		}
	}
	printf("%d\n", gde);
	for(int i = 1; i <= ctr; i++) {
		if(arah[i]) {
			printf("-");
		} else {
			printf("+");
		}
	}
	printf("\n");

	dd(s, 0);
	for(int i = 1; i <= n; i++) {
		if(fis[i]) {
			kcl++;
		}
	}
	printf("%d\n", kcl);
	for(int i = 1; i <= ctr; i++) {
		if(arah[i]) {
			printf("-");
		} else {
			printf("+");
		}
	}
	printf("\n");
	return 0;
}