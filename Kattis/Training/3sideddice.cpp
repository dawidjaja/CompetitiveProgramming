#include <algorithm>
#include <cstdio>

using namespace std;

int tmpa[5], tmpb[5], tmpc[5];
double a[5], b[5], c[5];

int main() {
	while (scanf("%d%d%d", &tmpa[1], &tmpb[1], &tmpc[1])) {
		if (tmpa[1] + tmpb[1] + tmpc[1] == 0)
			return 0;
		for (int i = 2; i <= 4; i++) {
			scanf("%d%d%d", &tmpa[i], &tmpb[i], &tmpc[i]);	
		}
		for (int i = 1; i <= 3; i++) {
			a[i] = 1.0 * tmpa[i] / (tmpa[1] + tmpa[2] + tmpa[3]);
			b[i] = 1.0 * tmpb[i] / (tmpb[1] + tmpb[2] + tmpb[3]);
			c[i] = 1.0 * tmpc[i] / (tmpc[1] + tmpc[2] + tmpc[3]);
		}
		int xl, xt, yl, yt;
		a[4] = 1.0 * tmpa[4] / (tmpa[4] + tmpb[4] + tmpc[4]);
		b[4] = 1.0 * tmpb[4] / (tmpa[4] + tmpb[4] + tmpc[4]);
		c[4] = 1.0 * tmpc[4] / (tmpa[4] + tmpb[4] + tmpc[4]);
		for (int i = 1;  i <= 4; i++) {
			printf("--- %d -->> %lf %lf %lf\n", i, a[i], b[i], c[i]);
		}
		xt = (a[4] - a[3]) * (b[2] - b[3]) - (b[4] - b[3]) * (a[2] - a[3]);
		xl = (a[1] - a[3]) * (b[2] - b[3]) - (b[1] - b[3]) * (a[2] - a[3]);
		yt = (a[4] - a[3]) * (b[1] - b[3]) - (b[4] - b[3]) * (a[1] - a[3]);
		yl = (a[2] - a[3]) * (b[1] - b[3]) - (b[2] - b[3]) * (a[1] - a[3]);
		if (yl == 0 || xl == 0) {
			if (xt == 0 && yt == 0) {
				printf("YES\n");
				continue;
			} else {
				printf("NO\n");
				continue;
			}
		} else {
			int x, y;
			int tmp = (xt % xl) + (yt % yl);
			x = xt / xl;
			y = yt / yl;
			if (x <= 1 && y <= 1 && (1.0 - x - y <= 1) &&
				x >= 0 && y >= 0 && (1.0 - x - y >= 0) && tmp == 0) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}