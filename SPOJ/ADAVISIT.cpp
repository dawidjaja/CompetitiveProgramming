#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[400005];
int dlm[400005], p[400005][20], list[400005], ans[400005], n, a, b, c;

#define getchar_unlocked() getchar()
inline int baca() {
	int temp = 0;
	char c;
	c = getchar_unlocked();
	while(c < '0' || c > '9') {
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9') {
		temp *= 10;
		temp += c - '0';
		c = getchar_unlocked();
	}
	return temp;
}

void dfs(int skrg, int sblm) {
	for(int i = 0; i < v[skrg].size(); i++) {
		int u = v[skrg][i];
		if(u != sblm) {
			dlm[u] = dlm[skrg] + 1;
			p[u][0] = skrg;
			for(int j = 1; j < 20; j++) {
				if(p[u][j-1] == -1) {
					for(int k = j; k < 20; k++) {
						p[u][k] = -1;
					}
					break;
				}
				p[u][j] = p[p[u][j-1]][j-1];
			}
			dfs(u, skrg);
		}
	}
}

inline int LCA(int a, int b){
	if(dlm[a] > dlm[b]) {
		swap(a, b);
	}
	for(int i = 19; i >= 0; i--) {
		if(p[b][i] != -1 && dlm[p[b][i]] >= dlm[a]) {
			b = p[b][i];
		}
	}
	if(a == b){
		return a;
	}
	for(int i = 19; i >= 0; i--){ 
		if(p[b][i] != -1 && p[b][i] != p[a][i]) {
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int dfslg(int skrg, int sblm) {
	int ret = list[skrg];
	for(int i = 0; i < v[skrg].size(); i++) {
		int u = v[skrg][i];
		if(u != sblm) {
			ret += dfslg(u, skrg);
		}
	}
	ans[skrg] = ret;
	return ret;
}

int main() {
//	scanf("%d", &n);
	n = baca();
	for(int i = 1; i < n; i++) {
//		scanf("%d%d", &a, &b);
		a = baca();
		b = baca();
		v[a].push_back(b); 
		v[b].push_back(a);
	}
	for(int i = 0; i < 20; i++) {
		p[1][i] = -1;
	}
	dlm[1] = 0;
	dfs(1, -1);
	for(int i = 1; i < n; i++) {
		a = i;
		b = i + 1;
		c = LCA(a, b);
//		printf("-- %d %d -- %d\n", a, b, c);
		list[a]++;
		list[b]++;
		list[c]--;
		if(p[c][0] != -1) {
			list[p[c][0]]--;
		}
	}
//	for(int i = 1; i <= n; i++) {
//		printf("%d --> %d\n", i, list[i]);
//	}
	dfslg(1, -1);
	for(int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
