#include <algorithm>
#include <cstdio>
#include <queue>

#define f first
#define s second
#define ff f.f
#define fs f.s
#define sf s.f
#define ss s.s
#define mp make_pair
#define pii pair<int,int>
#define ppp pair<pii,pii>
#define INF 1e9

using namespace std;

int r, c, list[105][105], a[10], b[10], ctr, ans, trgt, ps[105][105], vis[2050][55][55], f, m;
queue <ppp> q;
char ccc, kata[55];

bool msk(int a, int b) {
	if(a >= 0 && a <= r && b >= 0 && b <= c) {
		return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &r, &c);
	a[1] = 1;
	b[2] = 1;
	a[3] = -1;
	b[4] = -1;
	while(r || c) {
		if(r == 0 && c == 0) {
			return 0;
		}
		ctr = 0;
		trgt = 0;
		for(int i = 0; i < r; i++) {
			scanf("%s", kata);
			for(int j = 0; j < c; j++) {
				ccc = kata[j];
				if(ccc == 'I' || ccc == 'X') {
					list[i][j] = (1 << ctr);
					ctr++;
					if(ccc == 'I') {
						trgt += list[i][j];
					}
				} else {
					list[i][j] = 0;
				}
			}
		}
		if(trgt == 0) {
			printf("Tie 0\n");
			scanf("%d%d", &r, &c);
			continue;
		}
		for(int i = 0; i < c; i++) {
			ps[r][i] = 0;
		}
		for(int i = r - 1; i >= 0; i--) {
			for(int j = 0; j < c; j++) {
				ps[i][j] = ps[i+1][j] + list[i][j];
			}
		}
		for(int i = 0; i <= r; i++) {
			for(int j = 0; j <= c; j++) {
				for(int k = 0; k < (1 << 11); k++) {
					vis[k][i][j] = -1;
				}
			}
		}
//		printf("asdf %d %d asdf %d\n", r, c, trgt);
//		for(int i = 0; i < r; i++) {
//			printf("-- ");
//			for(int j = 0; j < c; j++) {
//				printf("%d ", list[i][j]);
//			}
//			printf("--\n");
//		}
//		printf("\n");
//		for(int i = 0; i <= r; i++) {
//			printf("-- ");
//			for(int j = 0; j <= c; j++) {
//				printf("%d ", ps[i][j]);
//			}
//			printf("--\n");
//		}
		q.push(mp(mp(0, 0), mp(0, 0)));
		vis[0][0][0] = 1;
		f = INF;
		while(q.size()) {
			int jrk, mask, y, x;
			jrk = q.front().ff;
			mask = q.front().fs;
			y = q.front().sf;
			x = q.front().ss;
			q.pop();
			if(jrk >= f) {
				continue;
			}
			for(int i = 1; i <= 4; i++) {
				int yy, xx;
				yy = y + a[i];
				xx = x + b[i];
				if(msk(yy, xx)) {
					int bru = mask;
					if(!(i & 1)) {
						bru = bru ^ ps[yy][min(xx, x)];
					}
					if(vis[bru][yy][xx] == -1) {
						vis[bru][yy][xx] = 1;
						if(bru == trgt && yy == 0 && xx == 0) {
							if(vis[bru][yy][xx] <= f) {
								f = jrk + 1;
							}
							break;
						}
						q.push(mp(mp(jrk + 1, bru), mp(yy, xx)));
					}
				}
			}
		}
		while(q.size()) {
			q.pop();
		}
		for(int i = 0; i <= r; i++) {
			for(int j = 0; j <= c; j++) {
				for(int k = 0; k < (1 << 11); k++) {
					vis[k][i][j] = -1;
				}
			}
		}
		m = INF;
		vis[0][r][c] = 1;
		q.push(mp(mp(0, 0), mp(r, c)));
		while(q.size()) {
			int jrk, mask, y, x;
			jrk = q.front().ff;
			mask = q.front().fs;
			y = q.front().sf;
			x = q.front().ss;
			q.pop();
			if(jrk >= m) {
				continue;
			}
			for(int i = 1; i <= 4; i++) {
				int yy, xx;
				yy = y + a[i];
				xx = x + b[i];
				if(msk(yy, xx)) {
					int bru = mask;
					if(!(i & 1)) {
						bru = bru ^ ps[yy][min(xx, x)];
					}
					if(vis[bru][yy][xx] == -1) {
						vis[bru][yy][xx] = 1;
						if(bru == trgt && yy == r && xx == c) {
							if(vis[bru][yy][xx] <= m) {
								m = jrk + 1;
							}
							break;
						}
						q.push(mp(mp(jrk + 1, bru), mp(yy, xx)));
					}
				}
			}
		}
//		printf("___ %d %d ___\n", f, m);
		if(f < m) {
			printf("Fernando %d\n", f);
		} else if(m < f) {
			printf("Martin %d\n", m);
		} else if(m == f) {
			printf("Tie %d\n", f);
		}
		scanf("%d%d", &r, &c);
	}
	return 0;
}
