#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, a[105], b[105], axor, bxor, list[105][105];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		axor ^= a[i];
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		bxor ^= b[i];
	}
	if (axor != bxor) {
		printf("NO\n");
	} else {
		for (int i = 1; i < n; i++) {
			list[i][1] = a[i];
			b[1] ^= a[i];
		}
		for (int i = 1; i <= m; i++) {
			list[n][i] = b[i];
		}
		printf("YES\n");
		for (int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				printf("%d", list[i][j]);
				((j == m) ? printf("\n") : printf(" "));
			}
		}
	}
	return 0;
}