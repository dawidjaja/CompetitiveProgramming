#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>
#define INF 1e9

using namespace std;

map <int, int> jrk[100005];
int size[100005], vis[100005], p[100005], list[100005], n, m, a, b;
vector <int> v[100005];

void itung(int skrg, int sblm) {
//	printf("%d %d\n", skrg, sblm);
	size[skrg] = 1;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm && vis[v[skrg][i]] == 0) {
			itung(v[skrg][i], skrg);
			size[skrg] += size[v[skrg][i]];
		}
	}
	return;
}

inline pii bigson(int skrg, int sblm) {
	int ret, maks;
	maks = 0;
	ret = -1;
	
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm && vis[v[skrg][i]] == 0) {
			if(size[v[skrg][i]] >= maks) {
				maks = size[v[skrg][i]];
				ret = v[skrg][i];
			}
		}
	}
	return mp(ret, maks);
}

int critgh(int skrg, int sblm) {
//	printf("tgh\n");
	itung(skrg, sblm);
	int luas = list[skrg]/2;
	while(true) {
		pii anak = bigson(skrg, sblm);
		if(anak.sc > luas) {
			sblm = skrg;
			skrg = anak.fs;
		} else {
			break;
		}
	}
	return skrg;
}

void dfs(int skrg, int sblm, int par, int x) {
//	printf("%d %d asdf\n", skrg, sblm);
	jrk[skrg][par] = x;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm && v[skrg][i] != par && vis[v[skrg][i]] == 0) {
			dfs(v[skrg][i], skrg, par, x+1);
		}
	}
	return;
}

void bikin(int skrg, int sblm) {
//	printf("-- %d %d --\n", skrg, sblm);
	int tgh = critgh(skrg, sblm);
	vis[tgh] = 1;
	p[tgh] = sblm;
	dfs(tgh, sblm, tgh, 0);
	for(int i = 0; i < v[tgh].size(); i++) {
		if(vis[v[tgh][i]] == 0) {
			bikin(v[tgh][i], tgh);
		}
	}
	return;
}

inline void update(int skrg) {
	int temp = skrg;
	while(temp != -1) {
		list[temp] = min(list[temp], jrk[skrg][temp]);
		temp = p[temp];
	}
	return;
}

inline int query(int skrg) {
	int ret = INF;
	int temp = skrg;
	while(temp != -1) {
		ret=  min(ret, jrk[skrg][temp] + list[temp]);
		temp = p[temp];
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n-1; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++) {
		p[i] = -1;
		list[i] = INF;
	}
	
	bikin(1, -1);
	
	
	list[1] = 0;
	update(1);
	
//	for(int i = 1; i <= n; i++) {
//		printf("%d --> %d\n", i, p[i]);
//	}
	
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		if(a == 1) {
			list[b] = 0;
			update(b);
		} else if(a == 2){
			printf("%d\n", query(b));
		}
	}
	return 0;
}
