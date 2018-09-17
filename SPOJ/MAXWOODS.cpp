#include <algorithm>
#include <cstdio>

using namespace std;

int t, n, m, dp[205][205], ans, INF;
char list[205][205];

int main() {
	INF = 1000000;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) {
			scanf("%s", &list[i]);
		}
		
		if(list[0][0] == 'T') {
			dp[0][0] = 1;
		} else if(list[0][0] == '0') {
			dp[0][0] = 0;
		} else {
			dp[0][0] = -INF;
		}
		
		
		for(int i = 1; i < m; i++) {
			if(list[0][i] != '#') {
				dp[0][i] = dp[0][i-1];
				if(list[0][i] == 'T'){
					dp[0][i]++;
				}
			} else {
				dp[0][i] = -INF;
			}
		}
		
		ans = 0;
		
		for(int i = 1; i < n; i++) {
			if(i%2) {
				if(list[i][m-1] != '#') {
					dp[i][m-1] = dp[i-1][m-1];
					if(list[i][m-1] == 'T') {
						dp[i][m-1]++;
					}
				} else {
					dp[i][m-1] = -INF;
				}
				for(int j = m - 2; j >= 0; j--) {
					if(list[i][j] != '#') {
						dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
						if(list[i][j] == 'T') {
							dp[i][j]++;
						}
					} else {
						dp[i][j] = -INF;
					}
				}
			} else {
				if(list[i][0] != '#') {
					dp[i][0] = dp[i-1][0];
					if(list[i][0] == 'T') {
						dp[i][0]++;
					}
				} else {
					dp[i][0] = -INF;
				}
				for(int j = 1; j < m; j++) {
					if(list[i][j] != '#') {
						dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
						if(list[i][j] == 'T') {
							dp[i][j]++;
						}
					} else {
						dp[i][j] = -INF;
					}
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0 ; j < m; j++) {
				ans = max(ans, dp[i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
