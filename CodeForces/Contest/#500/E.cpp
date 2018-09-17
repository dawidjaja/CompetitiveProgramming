#include <algorithm>
#include <cstdio>
#include <cmath>

#define INF 2000000000

using namespace std;

int list[5005], dp[5005][2600][2], n;

int cnt(int skrg, int sblm) {
	int tmp = list[skrg - 1];
	if (sblm) {
		tmp = min(list[skrg - 1], list[skrg - 2] - 1);
	}
	int a = max(0, tmp - list[skrg] + 1);
	int b = max(0, list[skrg + 1] - list[skrg] + 1);
	return (a + b);
}

int f(int skrg, int sisa, int sblm) {
	if (sisa == 0)
		return (0);
	if (skrg >= n)
		return (INF / 2);
	if (dp[skrg][sisa][sblm] != -1)
		return (dp[skrg][sisa][sblm]);
	int &ret = dp[skrg][sisa][sblm];
	ret = min(f(skrg + 2, sisa - 1, 1) + cnt(skrg, sblm), f(skrg + 1, sisa, 0));
	return (ret);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		for(int j = 0; j < n; j++) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}
	for(int i = 1; i <= (ceil(1.0 * n / 2)); i++) {
		if (i != 1) {
			printf(" ");
		}
		printf("%d", f(0, i, 0));
	}
	printf("\n");
	return 0;
}