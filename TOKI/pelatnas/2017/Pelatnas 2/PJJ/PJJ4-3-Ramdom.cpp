#include <algorithm>
#include <cstdio>

using namespace std;

int p[200005][20], lvl[200005], q, last, tipe, x, y, z;

inline void update(int x) {
	for(int i = 1; i < 20; i++) {
		if(p[x][i-1] == -1) {
			for(int j = i; j < 20; j++) {
				p[x][j] = -1;
			}
			break;
		}
		p[x][i] = p[p[x][i-1]][i-1];
	}
	return;
}

int LCA(int a, int b) {
	if(lvl[a] != lvl[b]) {
		if(lvl[b] > lvl[a]) {
			swap(a,b);
		}
		int temp,L;
		temp = a;
		L = lvl[b];
		for(int i = 19; i >= 0; i--) {
			if(p[temp][i] != -1 && lvl[p[temp][i]] >= L) {
				temp = p[temp][i];
			}
		}
		a = temp;
	}
	if(a == b) {
		return a;
	}
	int tempa, tempb;
	tempa = a;
	tempb = b;
	for(int i = 19; i >= 0; i--) {
//		printf("%d %d\n", i, p[tempa][i]);
		if((p[tempa][i] != -1) && (p[tempa][i] != p[tempb][i])) {
			tempa = p[tempa][i];
			tempb = p[tempb][i];
		}
	}
	return p[tempa][0];
}

int main () {
	scanf("%d", &q);
	for(int i = 0; i < 20; i++) {
		p[1][i] = -1;
	}
	lvl[1] = 1;
	last = 1;
	while(q--) {
		scanf("%d", &tipe);
		if(tipe == 1) {
			scanf("%d", &x);
			last++;
			lvl[last] = lvl[x]+1;
			p[last][0] = x;
			update(last);
		} else {
			scanf("%d%d%d", &x, &y, &z);
			int a, b, c;
			a = LCA(x, y);
			b = LCA(x, z);
			c = LCA(y, z);
//			printf("-- %d %d %d --\n", a, b, c);
			if(lvl[b] <= lvl[a] && lvl[c] <= lvl[a]) {
				printf("%d\n", a);
			} else {
				int ans;
				lvl[b] >= lvl[c] ? ans = b : ans = c;
				printf("%d\n", ans);
			}
		}
//		for(int i = 1; i <= last; i++) {
//			printf("-- %d\n", i);
//			for(int j = 0; j < 20; j++) {
//				printf("---- %d\n", p[i][j]);
//			}
//		}
	}
	return 0;
}
