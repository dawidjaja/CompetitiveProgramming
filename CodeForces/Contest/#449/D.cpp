#include <algorithm>
#include <cstdio>
#include <cmath>
#include <assert.h>

using namespace std;

int list[100005], n, m, c, d, k, x, cek;

int main() {
	scanf("%d%d%d", &n, &m, &c);
	for(int i = 1; i <= n; i++) {
		list[i] = -1;
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", &x);
		if(c / 2 < x) {
			k = n;
			while(x <= list[k] && list[k] != -1) {
				k--;
			}
			list[k] = x;
			printf("%d\n", k);
			fflush(stdout);
		} else {
			k = 1;
			while(list[k] <= x && list[k] != -1) {
				k++;
			}
			list[k] = x;
			printf("%d\n", k);
			fflush(stdout);
		}
		cek = 1;
		if(list[1] == -1) {
			cek = 0;
		}
		for(int i = 2; i <= n; i++) {
			if(list[i] != -1 && list[i - 1] <= list[i]) {

			} else {
				cek = 0;
			}
		}
		if(cek) {
			return 0;
		}
		// for(int i = 1; i <= n; i++) {
		// 	printf("%d ", list[i]);
		// }
		// printf("\n");
	}
	assert(false);
	return 0;
}