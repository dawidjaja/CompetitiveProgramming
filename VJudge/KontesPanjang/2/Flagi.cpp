#include <algorithm>
#include <cstdio>
#include <cmath>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

int n, q, k, srt[65005], tgh, med, a, b, buc[65005], ctr, awal[65006];
pii list[65005];

int binser(int l, int r, int x) {
	if(l == r) {
		if(list[l].fs <= x) {
			return l + 1;
		} else {
			return l;
		}
	}
	int mid = (l + r) >> 1;
	if(list[mid].fs <= x) {
		return binser(mid + 1, r, x);
	} else {
		return binser(l, mid, x);
	}
}

int main() {
	freopen(("F.in"), "r", stdin);
	while(scanf("%d%d", &n, &q) && n != 0 && q != 0) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &list[i].fs);
			list[i].sc = i;
			awal[i] = list[i].fs;
		}
		k = ceil(1.0 * sqrt(n));
		tgh = (n + 1) >> 1;
		sort(awal + 1, awal + 1 + n);
		med = awal[tgh];

		for(int i = n + 1; i <= k * k; i++) {
			list[i] = mp(1500000000, i);
		}
		n = k * k;
		for(int i = 1; i <= k; i++) {
			buc[i] = 0;
			int ki, ka;
			ki = (i - 1) * k + 1;
			ka = i * k;
			sort(list + ki, list + ka + 1);
		}
		while(q--) {
			scanf("%d%d", &a, &b);
			for(int i = 1; i <= k; i++) {
				int ki, ka;
				ki = (i - 1) * k + 1;
				ka = i * k;
				if(b < ki || ka < a) {
					continue;
				}
				if((ki <= a && a <= ka) || (ki <= b && b <= ka)) {
					for(int j = ki; j <= ka; j++) {
						if(a <= list[j].sc && list[j].sc <= b) {
							list[j].fs++;
						}
					}
					sort(list + ki, list + ka + 1);
				} else {
					buc[i]++;
				}
			}
			ctr = 0;
			for(int i = 1; i <= k; i++) {
				int ki, ka;
				ki = (i - 1) * k + 1;
				ka = i * k;
				ctr += binser(ki, ka, med - buc[i]) - ki;
			}
			// printf("data ");
			// for(int i = 1; i <= n; i++) {
			// 	printf("%d ", list[i].fs);
			// }
			// printf("\nbuc ");
			// for(int i = 1; i <= k; i++) {
			// 	printf("%d - ", buc[i]);
			// }
			// printf("\n");
			if(ctr < tgh) {
				med++;
			}
			printf("%d\n", med);
		}
	}
	return 0;
}