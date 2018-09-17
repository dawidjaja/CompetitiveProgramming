#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>

#define INF INT_MAX

using namespace std;

int n, c, co, cap[205][205], cos[205][205], hrg[105], vis[205], si, so, fr[205], ada[205], asal[205], ans;
char hrf[105];
vector <int> v[205], path;
queue <int> q;

inline void bikin(int x, int y, int kapa, int cost){
	// printf("bikin %d %d %d %d\n", x, y, kapa, cost);
	v[x].push_back(y);
	v[y].push_back(x);
	cap[x][y] = kapa;
	cap[y][x] = 0;
	cos[x][y] = cost;
	cos[y][x] = -cost;
}

inline void cobabikin(int a, int b) {
	bool satu, dua;
	b -= 50;
	int c = n - b + 1;
	satu = hrf[b] == 'a' + a - 1;
	dua = hrf[c] == 'a' + a - 1;
	// printf("%d %d %d %d %d %c %c--", a, b, c, satu, dua, hrf[b], hrf[c]);
	if(satu && dua) {
		// printf("a\n");
		bikin(a, b + 50, 1, -max(hrg[b], hrg[c]));
	} else if(satu) {
		// printf("b\n");
		bikin(a, b + 50, 1, -hrg[b]);
	} else if(dua) {
		// printf("c\n");
		bikin(a, b + 50, 1, -hrg[c]);
	} else {
		// printf("d\n");
		bikin(a, b + 50, 1, 0);
	}
	// printf("asdf\n");

}

bool bisa(int a, int b) {
	// printf("%d %d --> %d %d %d %d\n", a, b, cap[a][b], vis[a], vis[b], cos[a][b]);
	if(cap[a][b] > 0 && vis[a] + cos[a][b] < vis[b]) {
		return true;
	} else {
		return false;
	}
}

bool SPFA() {
	queue <int> kosong;
	swap(q, kosong);
	q.push(so);
	for(int i = 0; i <= si; i++) {
		vis[i] = INF;
		ada[i] = 0;
	}
	vis[so] = 0;
	ada[so] = 1;
	asal[so] = so;
	while(q.size()) {
		int skrg = q.front();
		q.pop();
		// printf("%d\n", skrg);
		ada[skrg] = 0;
		for(int i = 0; i < v[skrg].size(); i++) {
			if(bisa(skrg, v[skrg][i])) {
				vis[v[skrg][i]] = vis[skrg] + cos[skrg][v[skrg][i]];
				asal[v[skrg][i]] = skrg;
				if(ada[v[skrg][i]] == 0) {
					q.push(v[skrg][i]);
					ada[v[skrg][i]] = 1;
				}
			}
		}
	}
	if(vis[si] != INF) {
		path.clear();
		int x = si;
		int kcl = cap[asal[x]][x];
		while(asal[x] != x) {
			kcl = min(kcl, cap[asal[x]][x]);
			// printf("path -- %d %d -- %d \n", asal[x], x, cap[asal[x]][x]);
			path.push_back(x);
			x = asal[x];
		}
		path.push_back(so);
		co = 0;
		for(int i = path.size() - 2; i >= 0; i--) {
			cap[path[i + 1]][path[i]] -= kcl;
			// printf("-- <%d> -- ", cap[path[i]][path[i + 1]]);
			cap[path[i]][path[i + 1]] += kcl;
			co += kcl * cos[path[i]][path[i + 1]];
		}
		// printf("-- %d -- ", kcl);
		// for(int i = path.size() - 1; i >= 0; i--) {
		// 	printf("%d ", path[i]);
		// }
		// printf("\n");
		// if(co == 0) {
		// 	return false;
		// }
		return true;
	} else {
		return false;
	}
}

int main() {
	scanf("%d", &n);
	getchar();
	so = 0;
	si = 203;
	for(int i = 1; i <= n; i++) {
		hrf[i] = getchar();
		fr[hrf[i] - 'a' + 1]++;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &hrg[i]);
	}

	for(int i = 1; i <= 26; i++) {
		if(fr[i]) {
			bikin(so, i, fr[i], 0);
		}
	}

	for(int i = 1; i <= 26; i++) {
		for(int j = 1; j <= n / 2; j++) {
			cobabikin(i, 50 + j);
		}
	}

	for(int i = 1; i <= n / 2; i++) {
		bikin(i + 50, si, 2, 0);
	}
	
	// for(int i = so; i <= si; i++) {
	// 	if(v[i].size()) {
	// 		printf("%d\n", i);
	// 		for(int j = 0; j < v[i].size(); j++) {
	// 			if(cap[i][v[i][j]] != 0) {
	// 				printf("    %d -> %d %d\n", v[i][j], cap[i][v[i][j]], cos[i][v[i][j]]);
	// 			}
	// 			// printf("%d ", v[i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// }

	while(SPFA()) {
		ans += co;
		// printf("%d\n", ans);
	}
	printf("%d\n", ans);
	return 0;
}