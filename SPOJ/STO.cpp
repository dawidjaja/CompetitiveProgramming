#include <algorithm>
#include <cstdio>

#define INF 1e9

using namespace std;

int tc, n, list[1000005], ans, dp[1000005][3][2][3];
#define getchar_unlocked() getchar()
inline int baca() {
	int temp = 0;
	char c;
	c = getchar_unlocked();
	while(c < '0' || c > '9') {
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9') {
		temp *= 10;
		temp += c - '0';
		c = getchar_unlocked();
	}
	return temp;
}
//f(skrg, 0/ttp/1000 (0, 1, 2), turun/naik(0, 1), awalbgt(0, 1, 2))

int f(int skrg, int sblm, int arah, int awal) {
	if(dp[skrg][sblm][arah][awal] != -1) {
		return dp[skrg][sblm][arah][awal];
	}
	int ret;
	if(skrg == n-1) {
//		printf("dp %d %d %d %d ", skrg, sblm, arah, awal);
		if((list[skrg] == 1000 && arah == 0) || (list[skrg] == 0 && arah == 1)) {
			dp[skrg][sblm][arah][awal] = 1;
			return 1;
//			printf("aaa");
		}
		if((arah == 0 && ((list[skrg] >= list[skrg - 1] && sblm != 2))) || 
		(arah == 1 && ((list[skrg] <= list[skrg - 1] && sblm != 0)))) {
			dp[skrg][sblm][arah][awal] = 1;
			return 1;
//			printf("bbb");
		}
		if(((arah == 0) && ((list[skrg] >= list[0] && awal != 2))) || 
		((arah == 1) && ((list[skrg] <= list[0] && awal != 0)))) {
			dp[skrg][sblm][arah][awal] = 1;
			return 1;
//			printf("ccc");
		}
//		printf("\n");
		dp[skrg][sblm][arah][awal] = 0;
		return 0;
	}
//	int ret;
	if(arah == 0) {
		//turun
		ret = f(skrg + 1, 0, 1, awal) + 1;
		if((sblm == 2 && list[skrg] != 1000) || list[skrg] < list[skrg - 1]) {
			ret = min(ret, f(skrg + 1, 1, 1, awal));
		}
	} else if(arah == 1){ 
		//naik
		ret = f(skrg + 1, 2, 0, awal) + 1;
		if((sblm == 0 && list[skrg] != 0) || list[skrg] > list[skrg - 1]) {
			ret = min(ret, f(skrg + 1, 1, 0, awal));
		}
	}
	dp[skrg][sblm][arah][awal] = ret;
	return ret;
}

int main() {
//	scanf("%d", &tc);
	tc = baca();
	while(tc--) {
//		scanf("%d", &n);
		n = baca();
		for(int i = 0; i < n; i++) {
//			scanf("%d", &list[i]);
			list[i] = baca();
			for(int j = 0; j <= 2; j++) {
				for(int k = 0; k <= 1; k++) {
					for(int l = 0; l <= 2; l++) {
						dp[i][j][k][l] = -1;
					}
				}
			}
		}
		ans = INF;
		if(list[0] == 0) {
			ans = f(1, 0, 1, 0);
			ans = min(ans, f(1, 2, 0, 2) + 1);
		} else if(list[0] == 1000) {
			ans = f(1, 0, 1, 0) + 1;
			ans = min(ans, f(1, 2, 0, 2));
		} else {
			ans = f(1, 1, 1, 1);
			ans = min(ans, f(1, 1, 0, 1));
			ans = min(ans, f(1, 0, 1, 0) + 1);
			ans = min(ans, f(1, 2, 0, 2) + 1);
		}
//		for(int i = 0; i < n; i++) {
//			for(int j = 0; j <= 2; j++) {
//				for(int k = 0; k <= 1; k++) {
//					for(int l = 0; l <= 2; l++) {
////						printf("-- %d %d %d %d -- >> %d\n", i, j, k, l, dp[i][j][k][l]);
//					}
//				}
//			}
//		}
		printf("%d\n", ans);
	}
	return 0;
}

