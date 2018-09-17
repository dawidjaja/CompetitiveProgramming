#include <algorithm>
#include <cstdio>

using namespace std;

int dp[105][105][5], list[105], n, ans;

int cek(int skrg, int pjg, int bnyk) {
	if(dp[skrg][pjg][bnyk] != -1) {
		return dp[skrg][pjg][bnyk];
	}
	if(skrg == n) {
		if(((pjg & 1) == 0) && ((list[n] & 1) == 1 && (bnyk & 1))) {
			return dp[skrg][pjg][bnyk] = 1;
		} else {
			return dp[skrg][pjg][bnyk] = 0;
		}
	}
	if(((list[skrg] & 1) == 0) && pjg == 0) {
		return dp[skrg][pjg][bnyk] = 0;
	}
	int ret = cek(skrg + 1, pjg + 1, bnyk);
	if((list[skrg] & 1) && ((pjg & 1) == 0)) {
		ret = max(ret, cek(skrg + 1, 0, bnyk ^ 1));
	}
	// printf("%d %d --> %d\n", skrg, pjg, ret);
	return dp[skrg][pjg][bnyk] = ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		for(int j = 0; j <= n; j++) {
			for(int k = 0; k <= 2; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	ans = cek(1, 0, 1);
	// for(int i = 0; i <= n; i++) {
	// 	for(int j = 0; j <= n; j++) {
	// 		for(int k = 1; )
	// 		printf("%d %d --> %d\n", i, j, dp[i][j]);
	// 	}
	// }
	if(ans) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}