#include <algorithm>
#include <cstdio>

#define MOD 420047

using namespace std;

int dp[750][32768][51], n, m, org, ctr;

int f(int skrg, int mask, int sisa) {
	if(sisa == 0){ 
		return 1;
	}
	if(skrg >= n*m) {
		return 0;
	}
	if(dp[skrg][mask][sisa] != -1) {
		return dp[skrg][mask][sisa];
	}
	int dpn, blkg;
	dpn = mask & (1 << m-1);
	blkg = mask & 1;
	int ret = 0;
	int next = ((mask & (1 << (m-1)) - 1) << 1);
	ret = f(skrg + 1, next, sisa);
	if(skrg % m == 0) {
		if(!dpn) {
			ret += f(skrg + 1, next | 1, sisa-1);
		}
	} else {
		if(!dpn && !blkg) {
			ret += f(skrg + 1, next | 1, sisa-1);
		}
	}
	ret = ret % MOD;
	dp[skrg][mask][sisa] = ret;
	return ret;
}

int main() {
	ctr = 0;
	
	while(scanf("%d%d%d", &m, &n, &org) != EOF) {
		ctr++;
		if(n <= 50) {
			printf("%d ", ctr);
			
			for(int i = 0; i < m*n; i++) {
				for(int j = 0; j < (1 << m); j++) {
					for(int k = 0; k <= org; k++) {
						dp[i][j][k] = -1;
					}
				}
			}
			printf("%d\n", f(0, 0, org));
		}
	}
	return 0;
}
