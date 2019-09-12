#include <algorithm>
#include <cstdio>

using namespace std;

int a, b, f, k, x, y, t, ans;

int main() {
	scanf("%d%d%d%d", &a, &b, &f, &k);
	x = f * 2;
	y = (a - f) * 2;
	t = b;

	for(int i = 1; i <= k + 1; i++) {
		// printf("%d --> %d -> %d\n", i, t, ans);
		if(i == 1) {
			if(b < f) {
				printf("-1\n");
				return 0;
			}

			t -= f;

		} else if(i == k + 1) {
			if(i & 1) {
				// kiri
				if(b < f) {
					printf("-1\n");
					return 0;
				}
				if(t < f) {
					ans++;
				}
			} else {
				// kanan
				if(b < (a - f)) {
					printf("-1\n");
					return 0;
				}
				if(t < (a - f)) {
					ans++;
				}
			}
		} else {
			if(i & 1) {
				//kiri
				if(b < x) {
					printf("-1\n");
					return 0;
				}
				if(t < x) {
					ans++;
					t = b;
				}
				t -= x;
			} else {
				//kanan
				if(b < y) {
					printf("-1\n");
					return 0;
				}
				if(t < y) {
					ans++;
					t = b;
				}
				t -= y;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}