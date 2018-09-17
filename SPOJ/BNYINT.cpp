#include <algorithm>
#include <cstdio>

#define MOD 10007

using namespace std;

int s[1005], t, dp[1005][1005], n, k, on, ans, ctr, temp, cmb[105][105], pngkt[105];

int pangkat(int a, int b) {
	if(a <= 1) {
		return a;
	}
	if(b == 1) {
		return a;
	}
	if(b == 0) {
		return 1;
	}
	int ret = pangkat(a, b >> 1);
	ret *= ret;
	ret = ret % MOD;
	if(b & 1) {
		ret *= a;
		ret = ret % MOD;
	}
	ret = ret % MOD;
	return ret;
}

inline void precomp() {
	for(int i = 1; i <= 40; i++) {
		cmb[i][1] = i;
		cmb[i][0] = 1;
		cmb[0][i] = 0;
	}
	for(int j = 2; j <= 3; j++) {
		for(int i = 1; i <= 40; i++) {
			if(j > i) {
				continue;
			}
			if(j > i/2) {
				cmb[i][j] = cmb[i][i-j];
				continue;
			}
			cmb[i][j] = cmb[i][j-1] * (i-j+1) / j;
		} 
	}
	for(int i = 1; i <= 20; i++) {
		pngkt[i] = pangkat(i, 10005);
	}
}

int f(int turn, int sisa) {
	if(turn < 0 || sisa > n || sisa < 0) {
		return 0;
	}
	if(turn == 0) {
		if(sisa != 0) {
			return 0;
		}
		return 1;
	}
	
	if(dp[turn][sisa] != -1) {
		return dp[turn][sisa];
	}

	int ret;
	ret = 0;
	ret += (f(turn-1, sisa-3) * cmb[sisa][3]);
	ret += (f(turn-1, sisa-1) * cmb[sisa][2] * cmb[n-sisa][1]);
	ret += (f(turn-1, sisa+1) * cmb[sisa][1] * cmb[n-sisa][2]);
	ret += (f(turn-1, sisa+3) * cmb[n-sisa][3]);
	ret = ret % MOD;
	if(turn >= 2) {
		ret -= (f(turn-2, sisa) * (cmb[n][3] - (turn-2))) % MOD;
	}
//	if(turn <= 0 || ret < 0) {
//		tle();
//	}
	ret += MOD;
	ret = ret % MOD;
	ret = ret * pngkt[turn];
	ret = ret % MOD;
	dp[turn][sisa] = ret;
//	printf("%d %d --> %d\n", turn, sisa, ret);
	return ret;
}

int main() {
	ctr = 1;
	precomp();
	while(true) {
		scanf("%d%d", &n, &k);
		if(n == 0 && k == 0) {
			return 0;
		}
		for(int i = 0; i <= k; i++) {
			for(int j = 0; j <= n; j++) {
				dp[i][j] = -1;
			}
		}
		
		for(int i = 1; i <= n; i++) {
			scanf("%1d", &s[i]);
		}
		on = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%1d", &t);
			on += t ^ s[i];
		}
		if(n < 3 || k == 0) {
			if(k == 0 && on == 0) {
				printf("Case #%d: 1\n", ctr++);
			} else {
				printf("Case #%d: 0\n", ctr++);
			}
			continue;
		}
		ans = f(k, on);
		
		printf("Case #%d: %d\n", ctr++, ans);
	}
	return 0;
}
