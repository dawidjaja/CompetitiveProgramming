#include <algorithm>
#include <cstdio>

using namespace std;

int list[2005], dp[2005][2005], ans, n;

int f(int skrg, int blkg) {
	if(dp[skrg][blkg] != -1) {
		return dp[skrg][blkg];
	}
	if(skrg > n) {
		return 0;
	}
	int &ret = dp[skrg][blkg];
	if(list[skrg] % list[blkg] == 0) {
		// printf("-- %d %d dari %d %d\n", list[blkg], list[skrg], skrg, blkg);
		ret = max(ret, f(skrg + 1, skrg) + 1);
	}
	ret = max(ret, f(skrg + 1, blkg));
	return ret;
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		for(int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	sort(list + 1, list + 1 + n);
	// for(int i = 1; i <= n; i++) {
	// 	printf("%d ", list[i]);
	// }
	// // printf("\n");
	list[0] = 1;
	ans = f(1, 0);

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 0; j <= n; j++) {
	// 		printf("%d %d --> %d\n", i, j, dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	printf("%d\n", ans);
	return 0;
}