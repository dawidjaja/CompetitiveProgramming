#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	scanf("%d", &t);
	a[1] = b[2] = 1;
	a[3] = b[4] = -1;
	while(t--) {
		scanf("%d%d%d", &r, &c, &n);
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				for(int k = 1; k <= n; k++) {
					vis[k][r][c] = -1;
				}

				scanf("%d", &list[i][j]);
				if(list[i][j] < 0) {
					pc[-list[i][j]] = mp(i, j);
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			while(pq.size()) {
				pq.pop();
			}
			pq.push(mp(0, pc[i]));
			vis[i][pc[i].fs][pc[i].sc] = 0;
			ctr = 0;
			while(pq.size()) {
				pii skrg;
				skrg = pq.front().sc;
				jrk = -pq.front().fs;
				pq.pop();
				if(vis[i][skrg.fs][skrg.sc] != -1 && vis[i][skrg.fs][skrg.sc] > jrk) {
					vis[i][skrg.fs][skrg.sc] = jrk;
					for(int l = 1; l <= 4; l++) {
						y = skrg.fs + a[l];
						x = skrg.sc + b[l];
						temp = jrk + 1 + abs(max(0, list[skrg.fs][skrg.sc]) - max(0, list[y][x]));
						if(vis[i][y][x] == -1 || temp < vis[i][y][x]) {
							pq.push(mp(-temp, mp(y, x)));
						}
					}
				}
			}
		}
	}
	return 0;
}