#include <algorithm>
#include <cstdio>

#define INF 1e15

using namespace std;

long long n, K, list[100005], dp[2][100005][205], ps[100005], simpen[2][100005][205];

int main() {
	scanf("%lld%lld", &n, &K);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &list[i]);
		ps[i] = list[i] + ps[i-1];
	}
	for(long long tes = 0; tes <= 1; tes++) {
		for(long long k = 1; k <= K; k++) {
			for(long long i = 1; i <= n; i++) {
				for(long long j = 1; j < i; j++) {
					if(dp[tes][j][k-1] + ps[j] * (ps[i] - ps[j]) > dp[tes][i][k]) {
						dp[tes][i][k] = dp[tes][j][k-1] + ps[j] * (ps[i] - ps[j]);
						simpen[tes][i][k] = j;
					}
				}
			}
		}
		if(tes == 1) {
			break;
		}
		for(long long i = 1; i <= n/2; i++) {
			swap(list[i], list[n-i+1]);
		}
		for(long long i = 1; i <= n; i++) {
//			printf("-- %lld --\n", list[i]);
			ps[i] = list[i] + ps[i-1];
		}
	}
	long long tes;
	if(dp[0][n][K] > dp[1][n][K]) {
		tes = 0;
	} else {
		tes = 1;
	}
//	printf("-- %lld\n", tes);
	printf("%lld\n", dp[tes][n][K]);
	long long temp = n, ans;
	for(long long i = K; i > 1; i--) {
		if(tes == 1) {
			ans = n-simpen[tes][temp][i];
		} else {
			ans = simpen[tes][temp][i];
		}
		printf("%lld ", ans);
		temp = simpen[tes][temp][i];
	}
	if(tes == 1) {
		simpen[tes][temp][1] = n-simpen[tes][temp][1];
	}
	printf("%lld\n", simpen[tes][temp][1]);
	return 0;
}
