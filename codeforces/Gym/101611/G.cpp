#include <algorithm>
#include <cstdio>

using namespace std;

long long n, m, r[505][505], c[505][505], list[505][505];

int main() {
	scanf("%lld%lld", &n, &m);
	for(long long i = 0; i < n; i++) {
		for(long long j = 0; j < m; j++) {
			scanf("%lld%lld", &r[i][j], &c[i][j]);
		}
	}
	for(long long i = 0; i < n; i++) {
		for(long long j = 0; j < m; j++) {
			if(j == 0) {
				if(i == 0) {
					list[i][j] = -c[i][j];
				} else {
					list[i][j] = r[i][j] + list[i - 1][j];
				}
			} else {
				list[i][j] = list[i][j - 1] - c[i][j];
			}
			// printf("%lld ", list[i][j]);
			if(i != 0) {
				if(list[i - 1][j] + r[i][j] != list[i][j]) {
					// printf("a");
					printf("No\n");
					return 0;
				}
			}
			if(i == n - 1) {
				if(list[i][j] + r[0][j] != list[0][j]) {
					// printf("b");
					printf("No\n");
					return 0;
				}
			}
			if(j == m - 1) {
				if(list[i][j] - c[i][0] != list[i][0]) {
					// printf("c");
					printf("No\n");
					return 0;
				}
			}
			// if(j == m - 1) {
			// 	printf("\n");
			// }
		}
	}
	printf("Yes\n");
	return 0;
}