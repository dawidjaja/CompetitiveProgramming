#include <algorithm>
#include <cstdio>
#include <vector>
#include <assert.h>

#define fs first
#define sc second
#define mp make_pair

using namespace std;

int lvl[100005], p[100005][20], hrg[100005][20], n, m, q, a, b, c, ans;
vector <pair<int, int> > v[100005];

void dfs(int skrg, int sblm, int heit, int lolol) {
	
	lvl[skrg] = heit;
	p[skrg][0] = sblm;
	hrg[skrg][0] = lolol;
	
	for(int i = 1; i < 20; i++) {
		if(p[p[skrg][i-1]][i-1] == -1) {
			for(int j = i; j < 20; j++) {
				p[skrg][j] = -1;
			}
			break;
		}
		p[skrg][i] = p[p[skrg][i-1]][i-1];
		hrg[skrg][i] = hrg[skrg][i-1] + hrg[p[skrg][i-1]][i-1];
	}
	
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i].fs != sblm) {
			dfs(v[skrg][i].fs, skrg, heit+1, v[skrg][i].sc);
		}
	}
	return;
}

inline int LCA(int a, int b) {
	int ret;
	ret = 0;
	if(lvl[a] > lvl[b]) {
		swap(a, b);
	}
	for(int i = 19; i >= 0; i--) {
		if(p[b][i] != -1 && lvl[p[b][i]] >= lvl[a]) {
			ret += hrg[b][i];
			b = p[b][i];
		}
	}
	if(a == b) {
		return ret;
	}
	int tempa, tempb;
	tempa = a;
	tempb = b;
	for(int i = 19; i >= 0; i--) {
		if((p[tempa][i] != -1) && (p[tempa][i] != p[tempb][i])) {
			ret += hrg[tempa][i];
			ret += hrg[tempb][i];
			tempa = p[tempa][i];
			tempb = p[tempb][i];
		}
	}
	ret += hrg[tempa][0];
	ret += hrg[tempb][0];
	return ret;
}

int main() {
	
	scanf("%d%d%d", &n, &m, &q);
	assert(n-1 == m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c); 
		v[a].push_back(mp(b, c));
		v[b].push_back(mp(a, c));
	}
	for(int i = 0; i < 20; i++) {
		p[1][i] = -1;
	}
	
	dfs(1, -1, 0, 0);
	
//	int damdam;
//	damdam = 0;
//	while(true) {
//		damdam++;
//	}
	
	while(q--) {
		scanf("%d%d", &a, &b);
		ans = LCA(a, b);
		printf("%d\n", ans);
	}
	return 0;
}
