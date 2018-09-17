#include <algorithm>
#include <cstdio>

#define INF 3*1e18

using namespace std;

long long n, k, K, ps[3005], med[3005][3005], x[3005], org[3005], dp[3005][3005], ptr, temp;

void precompute() {
	for(long long i = 1; i <= n; i++) {
		ptr = i;
		temp = 0;
		for(long long j = i + 1; j <= n; j++) {
			temp += org[j] * (x[j] - x[ptr]);
			while((ps[j] - ps[ptr]) >= (ps[ptr] - ps[i - 1])) {
				temp += (((ps[ptr] - ps[i - 1]) - (ps[j] - ps[ptr])) * (x[ptr + 1] - x[ptr]));
				ptr++;
			}
			med[i][j] = temp;
		}
	}
}

void solve(long long l, long long r, long long optl, long long optr, long long k) {
//	printf("-- %d %d %d %d %d --\n", l, r, optl, optr, k);
	if(l > r) {
		return;
	}
	long long mid = (l + r) >> 1;
	dp[mid][k] = INF;
	long long opt = -1;
	for(long long i = max(k - 1, optl); i <= min(mid-1, optr); i++) {
		if(dp[i][k-1] + med[i + 1][mid] <= dp[mid][k]) {
			dp[mid][k] = dp[i][k-1] + med[i + 1][mid];
			opt = i;
		}
	}
	solve(l, mid - 1, optl, opt, k);
	solve(mid + 1, r, opt, optr, k);
	return;
}

int main() {
	scanf("%lld%lld", &n, &K);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld%lld", &x[i], &org[i]);
		ps[i] = ps[i-1] + org[i];
	}
	precompute();
	for(int i = 1; i <= n; i++) {
		dp[i][1] = med[1][i];
	}
	for(long long i = 2; i <= K; i++) {
		solve(1, n, 1, n, i);
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= K; j++) {
//			printf("%d %d --> %lld\n", i, j, dp[i][j]);
//		}
//	}
	printf("%lld\n", dp[n][K]);
	return 0;
}
