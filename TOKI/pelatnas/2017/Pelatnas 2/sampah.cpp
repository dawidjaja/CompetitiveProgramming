#include <algorithm>
#include <cstdio>

#define INF 1e7

using namespace std;

int n, K, list[100005], dp[1005][1005][205], ps[100005], simpen[1005][1005][205];

int f(int l, int r, int sisa) {
	printf("--- %d %d %d ---\n", l, r, sisa);
	if(sisa == 0) {
		return 0;
	}
	if(dp[l][r][sisa] != -1) {
		return dp[l][r][sisa];
	}
	int ret = 0;
	for(int i = l; i < r; i++) {
		int temp;
		temp = (ps[i] - ps[l-1]) * (ps[r] - ps[i]);
		int porer = 0;
		for(int j = 0; j <= sisa; j++) {
			porer = max(porer, f(l, i, sisa-j) + f(i
		}
		temp += f(l, i, sisa-1) + f(i+1, r, sisa-1);
		if(temp > ret){
			ret = temp;
			simpen[l][r][sisa] = i;
		}
	}
	return ret;
}

void bt(int l, int r, int sisa) {
	if(l == 1 && r == n) {
		printf("%d", simpen[l][r][sisa]);
	} else {
		printf(" %d", simpen[l][r][sisa]);
	}
	bt(l, simpen[l][r][sisa], sisa-1);
	bt(simpen[l][r][sisa] + 1, r, sisa-1);
	return;
}

int main() {
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		ps[i] = list[i] + ps[i-1];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= K; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	
	f(1, n, K);

//	printf("-- %d\n", tes);
	printf("%d\n", dp[1][n][K]);
	bt(1, n, K);
	return 0;
}
