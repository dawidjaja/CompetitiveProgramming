#include <algorithm>
#include <cstdio>
#include <vector>

#define pb push_back
#define MOD 420047

using namespace std;

int ctr, list[20], n, m, org, dp[5][20][20], s, ans;
vector <int> v[20];

int main () {
	ctr = 0;
	list[0] = 0;
	list[1] = list[2] = list[3] = list[4] = 1;
	list[5] = list[6] = list[7] = 2;
	for(int i = 0; i <= 7; i++) {
		v[0].pb(i);
	}
	v[1].pb(0); v[1].pb(2); v[1].pb(3); v[1].pb(4); v[1].pb(6); 
	v[2].pb(0); v[2].pb(1); v[2].pb(3); v[2].pb(4); v[2].pb(5); v[2].pb(7); 
	v[3].pb(0); v[3].pb(1); v[3].pb(2); v[3].pb(4); v[3].pb(6); v[3].pb(7); 
	v[4].pb(0); v[4].pb(1); v[4].pb(2); v[4].pb(3); v[4].pb(5); 
	v[5].pb(0); v[5].pb(2); v[5].pb(4); v[5].pb(6); 
	v[6].pb(0); v[6].pb(1); v[6].pb(3); v[6].pb(5);
	v[7].pb(0); v[7].pb(2); v[7].pb(3); 
	
	
	while(scanf("%d%d%d", &m, &n, &org) != EOF) {
		ctr++;
		if(n > 50) {
			for(int i = 0; i <= 1; i++) {
				for(int j = 0; j <= 7; j++) {
					for(int k = 0; k <= 10; k++) {
						dp[i][j][k] = 0;
					}
				}
			}
			printf("%d ", ctr);
			s = 0;
			ans = 0;
			if(m == 2) {
				dp[s][0][org] = 1;
				dp[s][1][org - 1] = 1;
				dp[s][2][org - 1] = 1;
				for(int i = 2; i <= n; i++) {
					
//					if(i % 100000 == 0) {
//						printf("%d x 10^5\n", i/100000);
//					}
					s ^= 1;
					for(int j = 0; j <= org; j++) {
						dp[s][0][j] = (dp[s^1][0][j] + dp[s^1][1][j] + dp[s^1][2][j]) % MOD;
						dp[s][1][j] = (dp[s^1][0][j+1] + dp[s^1][2][j+1]) % MOD;
						dp[s][2][j] = (dp[s^1][0][j+1] + dp[s^1][1][j+1]) % MOD;
					}
				}
				for(int i = 0; i <= 2; i++) {
					ans += dp[s][i][0];
					ans = ans % MOD;
				}
			} else if(m == 3) {
				dp[s][0][org] = 1;
				dp[s][1][org-1] = 1;
				dp[s][2][org-1] = 1;
				dp[s][3][org-1] = 1;
				dp[s][4][org-2] = 1;
				for(int i = 2; i <= n; i++) {
//					if(i % 1000000 == 0) {
//						printf("%d x 10^6\n", i/1000000);
//					}
					s ^= 1;
					
					for(int j = 0; j <= org; j++) {
						dp[s][0][j] = (dp[s^1][0][j] + dp[s^1][1][j] + dp[s^1][2][j] + dp[s^1][3][j] + dp[s^1][4][j]) % MOD;
						dp[s][1][j] = (dp[s^1][0][j+1] + dp[s^1][2][j+1] + dp[s^1][3][j+1]) % MOD;
						dp[s][2][j] = (dp[s^1][0][j+1] + dp[s^1][1][j+1] + dp[s^1][3][j+1] + dp[s^1][4][j+1]) % MOD;
						dp[s][3][j] = (dp[s^1][0][j+1] + dp[s^1][1][j+1] + dp[s^1][2][j+1]) % MOD;
						dp[s][4][j] = (dp[s^1][0][j+2] + dp[s^1][2][j+2]) % MOD;
					}
				}
				for(int i = 0; i <= 4; i++){
					ans += dp[s][i][0];
					ans = ans % MOD;
				}
			} else if(m == 4) {
				for(int i = 0; i <= 7; i++) {
					dp[s][i][org - list[i]] = 1;
				}
				for(int ll = 2; ll <= n; ll++) {
					s ^= 1;
					int asdf = 0;
					for(int i = 0; i <= 7; i++) {
						for(int j = 0; j <= org; j++) {
							dp[s][i][j] = 0;
							for(int k = 0; k < v[i].size(); k++) {
								dp[s][i][j] += dp[s^1][v[i][k]][j + list[i]];
								dp[s][i][j] %= MOD;
							}
						}
					}
				}
				for(int i = 0; i <= 7; i++){
					ans += dp[s][i][0];
					ans %= MOD;
				}
			}
			
			printf("%d\n", ans);
		}
		
	}
	return 0;
}
