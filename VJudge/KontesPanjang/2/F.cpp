#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int list[65005], n, q, k, srt[65005], tgh, med, a, b, buc[65005], ctr, awal[65006];

bool dlma(int x, int bak) {
	// printf("ceka %d %d --> ", x, bak);
	if(bak * k < x && x < min(n, (bak + 1) * k)) {
		// printf("yes\n");
		return true;
	}
	// printf("no\n");
	return false;
}

bool dlmb(int x, int bak) {
	// printf("cekb %d %d --> ", x, bak);
	if(bak * k <= x && x < min(n, (bak + 1) * k) - 1) {
		// printf("yes\n");
		return true;
	}
	// printf("no\n");
	return false;
}

int binser(int l, int r, int x) {
	int mid = (l + r) >> 1;
	if(l == r) {
		if(srt[l] <= x) {
			return l + 1;
		} else {
			return l;
		}
	}
	if(srt[mid] <= x) {
		return binser(mid + 1, r, x);
	} else {
		return binser(l, mid, x);
	}
}

int main() {
	// freopen(("F.in"), "r", stdin);
	while(scanf("%d%d", &n, &q) && n != 0 && q != 0) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &list[i]);
			awal[i] = srt[i] = list[i];
			buc[i] = 0;
		}
		k = ceil(1.0 * sqrt(n));
		sort(awal, awal + n);
		tgh = ((n + 1) >> 1) - 1;
		med = awal[tgh];
		for(int i = n; i < k * k; i++) {
			list[i] = srt[i] = 1500000000;
		}
		// printf("k -> %d\n", k);

		for(int i = 0; i <= (n - 1) / k; i++) {
			sort(srt + (i / k) * k, srt + (i / k + 1) * k);
		}

		while(q--) {
			scanf("%d%d", &a, &b);
			a--;
			b--;
			for(int i = 0; i < k; i++) {
				if((i + 1) * k - 1 < a || i * k > b) {
					continue;
				}
				if(dlma(a, i) || dlmb(b, i)) {
					if(dlma(a, i) && dlmb(b, i)) {
						for(int j = a; j <= b; j++) {
							// printf("a add %d\n", j);
							list[j]++;
						}
					} else if(dlma(a, i)) {
						for(int j = a; j < (i + 1) * k; j++) {
							// printf("bb add %d\n", j);
							list[j]++;
						}
					} else {
						for(int j = i * k; j <= b; j++) {
							// printf("ccc add %d\n", j);
							list[j]++;
						}
					}
					for(int j = i * k; j < (i + 1) * k; j++) {
						srt[j] = list[j];
					}
					sort(srt + i * k, srt + (i + 1) * k);
				} else {
					buc[i]++;
				}
			}
			ctr = 0;
			for(int i = 0; i <= (n - 1) / k; i++) {
				ctr += binser(i * k, min(n - 1, (i + 1) * k - 1), med - buc[i]) - i * k;
			}
			// for(int i = 0; i < n; i++) {
			// 	printf("%d ", list[i]);
			// }
			// printf("\n");
			// for(int i = 0; i < n; i++) {
			// 	printf("%d - ", srt[i]);
			// }
			// printf("\n");
			// for(int i = 0; i <= (n - 1) / k; i++) {
			// 	printf("%d -- ", buc[i]);
			// }
			// printf("\n");
			// printf("ans ==>>> %d %d %d\n", med, tgh, ctr);
			if(ctr < tgh + 1) {
				printf("%d\n", ++med);
			} else {
				printf("%d\n", med);
			}
		}
	}
	return 0;
}