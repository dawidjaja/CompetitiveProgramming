#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

int vis[1005][1005], list[1005][1005], n, m, ans, ansb, ctr;
pii a, b;

int dfs(pii p, pii q) {
	vis[p.fs][p.sc] = 0;
	while(list[p.fs + 1][p.sc] == 1) {
		p.fs++;
		vis[p.fs][p.sc] = 0;
	}
	while(list[q.fs][q.sc + 1] == 1) {
		q.sc++;
		for(int i = q.fs; i <= p.fs; i++) {
			if(list[i][q.sc] == 0) {
				return -1;
			} else {
				vis[i][q.sc] = 0;
			}
		}
	}
	// printf("pq --- %d %d %d %d\n", p.fs, p.sc, q.fs, q.sc);
	while(list[p.fs + 1][p.sc] == 0 && p.sc < q.sc) {
		p.sc++;
	}
	// printf("ppqq --- %d %d %d %d\n", p.fs, p.sc, q.fs, q.sc);
	while(list[p.fs + 1][p.sc] == 1 || list[q.fs][q.sc + 1] == 1) {
		if(list[p.fs + 1][p.sc] == 1 && list[q.fs][q.sc + 1] == 1) {
			return -1;
		}
		// printf("abcd --- %d %d %d %d\n", p.fs, p.sc, q.fs, q.sc);
		if(list[p.fs + 1][p.sc] == 1) {
			while(list[p.fs + 1][p.sc] == 1) {
				p.fs++;
				for(int i = p.sc; i <= q.sc; i++) {
					if(list[p.fs][i] == 0) {
						return -1;
					} else {
						vis[p.fs][i] = 0;
					}
				}
				if(list[q.fs][q.sc + 1] == 1) {
					return -1;
				} else {
					q.fs++;
				}
			}
		} else {
			while(list[q.fs][q.sc + 1] == 1) {
				q.sc++;
				for(int i = q.fs; i <= p.fs; i++) {
					if(list[i][q.sc] == 0) {
						return -1;
					} else {
						vis[i][q.sc] = 0;
					}
				}
				if(list[p.fs + 1][p.sc] == 1) {
					return -1;
				} else {
					p.sc++;
				}
			}
		}
	}
	// printf("ret %d %d %d %d\n", p.fs, p.sc, q.fs, q.sc);
	return (q.sc - p.sc + 1) * (p.fs - q.fs + 1);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		getchar();
		for(int j = 1; j <= m; j++) {
			char c = getchar();
			vis[i][j] = list[i][j] = (c == 'X' ? 1 : 0);
		}
	}
	ctr = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(vis[i][j] == 1) {
				ctr++;
				a = mp(i, j);
				b = mp(i, j);
				// printf("-- %d %d %d %d --\n", a.fs, a.sc, b.fs, b.sc);
				ans = dfs(a, b);
			}
		}
	}
	if(ctr != 1) {
		ans = -1;
	}
	for(int i = 1; i <= max(n, m); i++) {
		for(int j = i; j <= max(n, m); j++) {
			swap(list[i][j], list[j][i]);
			vis[i][j] = list[i][j];
			vis[j][i] = list[j][i];
		}
	}
	// for(int i = 1; i <= m; i++) {
	// 	for(int j = 1; j <= n; j++) {
	// 		printf("%d ", list[i][j]);
	// 	}
	// 	printf("\n");
	// }
	ctr = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(vis[i][j] == 1) {
				ctr++;
				a = mp(i, j);
				b = mp(i, j);
				// printf("%d %d %d %d --\n", a.fs, a.sc, b.fs, b.sc);
				ansb = dfs(a, b);
			}
		}
	}
	if(ctr != 1) {
		ansb = -1;
	}
	// printf("ans --- %d %d\n", ans, ansb);
	if(ans == -1) {
		printf("%d\n", ansb);
	} else if(ansb == -1) {
		printf("%d\n", ans);
	} else {
		printf("%d\n", min(ans, ansb));
	}
	return 0;
}