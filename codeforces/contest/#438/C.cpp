#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n, k, tmp, x, list[100005], cek[105], tes;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		tmp = 1;
		list[i] = 0;
		for(int j = 1; j <= k; j++) {
			scanf("%d", &x);
			list[i] += x * tmp;
			tmp *= 2;
		}
		cek[list[i]] = 1;
	}
	// for(int i = 0; i < (1 << k); i++) {
	// 	printf("%d --> %d\n", i, cek[i]);
	// }
	if(n == 1) {
		if(cek[0] == 1) {
			printf("YES\n");
		}  else {
			printf("NO\n");
		}
	}
	if(cek[0] == 1) {
		printf("YES\n");
		return 0;
	}
	for(int i = 0; i < (1 << k); i++) {
		for(int j = 0; j < (1 << k); j++){
			tes = 1;
				// printf("%d %d\n", i, j);
			if(i != j && cek[i] && cek[j]) {
				for(int l = 0; l < k; l++) {
					if(((i & j) & (1 << l))) {
						tes = 0;
					}
				}
				if(tes) {
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}