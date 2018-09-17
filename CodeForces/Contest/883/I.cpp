#include <algorithm>
#include <cstdio>

using namespace std;

int blkg, ctr, list[300005], l, r, n, k;

bool cek(int x) {
	blkg = 1;
	ctr = 0;
	for(int i = 1; i <= n; i++) {
		ctr++;
		if(ctr < k) {
			continue;
		} else {
			if(list[i] - list[blkg] > x) {
				return 0;
			} else {
				if(i != n && list[i + 1] - list[blkg] <= x) {
					continue;
				} else {
					ctr = 0;
					blkg = i + 1;
				}
			}
		}
	}
	if(ctr) {
		return 0;
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
	}
	sort(list + 1, list + 1 + n);
	l = 0;
	r = list[n] - list[1];
	while(l < r) {
		int mid = ((l + r) >> 1);
		// printf("%d %d %d \n", l, r, mid);
		if(cek(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	printf("%d\n", l);
	return 0;
}