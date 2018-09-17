#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <assert.h>

#define INF 1e6

using namespace std;

vector <int> v[100005];
int list[100005], atas[100005], a, b, n, m, tc, t, dlm[100005], p[100005][20];
bool vis[100005];

int LCA(int x, int y) {
//	printf("LCA %d %d\n", x, y);
	if(dlm[x] > dlm[y]) {
		swap(x, y);
	}
	// y lebih dalem
	for(int i = 17; i >= 0; i--) {
		if(p[y][i] != -1 && dlm[p[y][i]] >= dlm[x]) {
			y = p[y][i];
		}
	}
	//y setingkat x;
	if(y == x){
//		printf(" sama ----->> %d\n", y);
		return y;
	}
	
	for(int i = 17; i >= 0; i--){
		if(p[y][i] != -1 && p[x][i] != -1 && p[y][i] != p[x][i]) {
			y = p[y][i];
			x = p[x][i];
		}
	}
//	printf(" ga ------>> %d\n", p[x][0]);
	return p[x][0];
}

int jrk(int x, int y) {
	int z = LCA(x, y);
	int ret = dlm[x] + dlm[y] - 2*dlm[z];
//	printf("-- %d %d --> %d %d\n", x, y, z, ret);
	return ret;
}

void itunggede(int skrg, int sblm) {
	list[skrg] = 1;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm && vis[v[skrg][i]] == 0) {
			itunggede(v[skrg][i], skrg);
			list[skrg] += list[v[skrg][i]];
		}
	}
	return;
}

inline int caritgh(int skrg, int par) {
	itunggede(skrg, par);
	int size = list[skrg]/2;
//	int ctr = n+5;
	while(true) {
//		assert(ctr--);
		int temp, maks;
		maks = 0;
		for(int i = 0; i < v[skrg].size(); i++) {
			if((list[v[skrg][i]] >= maks && v[skrg][i] != par) && (vis[v[skrg][i]] == 0)) {
				temp = v[skrg][i];
				maks = list[v[skrg][i]];
			}
		}
		if(maks > size) {
			par = skrg;
			skrg = temp;
		} else {
			break;
		}
	}
	return skrg;
}

void bikin(int skrg, int par) {
	if(vis[skrg]) {
		return;
	}
	int tgh;
	tgh = caritgh(skrg, par);
	vis[tgh] = 1;
	atas[tgh] = par;
	for(int i = 0; i < v[tgh].size(); i++) {
		if(vis[v[tgh][i]] == 0) {
			bikin(v[tgh][i], tgh);
		}
	}
}

inline void update(int skrg) {
	int temp, ss;
	ss = 0;
	temp = skrg;
	while(atas[temp] >= 0) {
		temp = atas[temp];
		list[temp] = min(list[temp], jrk(temp, skrg));
	}
	return;
}

inline int query(int skrg) {
	int temp, ret, ss;
	ret = INF;
	temp = skrg;
	while(temp >= 0) {
		ret = min(ret, jrk(temp, skrg) + list[temp]);
		temp = atas[temp];
	}
	return ret;
}

void dfs(int skrg, int sblm) {
	p[skrg][0] = sblm;
	if(sblm == -1) {
		dlm[skrg] = 0;
	} else {
		dlm[skrg] = dlm[sblm] + 1;
	}
	for(int i = 1; i < 18; i++) {
		if(p[skrg][i-1] == -1) {
			for(int j = i; j < 18; j++) {
				p[skrg][j] = -1;
			}
			break;
		}
		p[skrg][i] = p[p[skrg][i-1]][i-1];
	}
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm) {
			dfs(v[skrg][i], skrg);
		}
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n-1; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) {
		atas[i] = -1;
		list[i] = 1;
	}
	
	bikin(1, -1);
	for(int i = 1; i <= n; i++) {
		list[i] = INF;
	}
	
	
	dlm[0] = -1;
	dfs(1, -1);
	
	list[1] = 0;
	update(1);
	
//	for(int i = 1; i <= n; i++) {
//		printf("-- %d %d %d--\n", i, dlm[i], atas[i]);
//		for(int j = 0; j < 18; j++) {
////			if(p[i][j] == -1) break;
//			printf("    -- %d >> %d\n", j, p[i][j]);
//		}
//	}
	while(m--) {
		scanf("%d%d", &tc, &t);
		if(tc == 1) {
			//ubah t jadi merah
			list[t] = 0;
			update(t);
		} else {
			//cari merah terdekat dengan t
			printf("%d\n", query(t));
		}
//		for(int i = 1; i <= n; i++){
//			printf("%d %d\n", i, list[i]);
//		}
	}
	return 0;
}
