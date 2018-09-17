#include <algorithm>
#include <cstdio>

#define INF LLONG_MAX/3

using namespace std;

long long dp[2005][2][2005][2][2],list[2005][205],r,c,brs[2005],kol[2005][5],a,b,d,bar[2005][205],y,x,ans;

long long f(long long i, long long x, long long j, long long y, long long blh) {
//	printf("%lld %lld %lld %lld %lld\n",i,x,j,y,blh);
	if(i > j) {
		return INF;
	}
	if(i == j) {
		if (x == y) {
			return list[i][c*x + (1-x)];
		} else if(blh == 0) {
			return dp[i][x][j][y][0];
		}
		return INF;
	}
	if(dp[i][x][j][y][blh] != -1) {
		return dp[i][x][j][y][blh];
	}
	long long ret;
	if(blh == 0) {
		ret = min(f(i+1,x,j,y,0)+list[i][r*x + (1-x)], f(i,1-x,j,y,1) + dp[i][0][i][1][0]);
		dp[i][x][j][y][0] = dp[j][y][i][x][0] = ret;
	} else {
		ret = f(i+1,x,j,y,0) + list[i][c*x + (1-x)];
		dp[i][x][j][y][1] = ret;
	}
	return ret;
}

inline void precompute() {
	for(long long i = 1; i <= 2000; i++) {
		for(long long j = 1; j <= 2000; j++) {
			for(long long k = 0; k <= 1; k++) {
				for(long long l = 0; l <=3; l++) {
					dp[i][k][j][l/2][l%2] = -1;
				}
			}
		}
	}
	for(long long i = 1; i <= r; i++) {
		dp[i][0][i][0][0] = dp[i][1][i][1][0] = dp[i][0][i][0][1] = dp[i][1][i][1][1] = 0;
	}
	
	for(long long i = 1; i <= r; i++) {
		dp[i][0][i][1][0] = dp[i][1][i][0][0] = brs[i];
		for(long long j = 1; j <= r; j++) {
			long long hrg;
			hrg = kol[0][max(i,j)] - kol[0][min(i,j)-1];
			hrg += kol[1][max(i,j)] - kol[1][min(i,j)-1];
			hrg += brs[j];
			hrg -= kol[0][j] - kol[0][j-1] + kol[1][j] - kol[1][j-1];
			dp[i][0][i][1][0] = min(dp[i][0][i][1][0], hrg);
		}
		dp[i][1][i][0][0] = dp[i][0][i][1][0];
	}
	for(long long i = 1; i <= r; i++) {
		for(long long j = 0; j <= 1; j++) {
			for(long long k = 0; k <= 1; k++) {
				f(1,k,i,j,0);
			}
		}
	}
}

int main () {
	scanf("%lld%lld",&r,&c);
	for(long long i = 1; i <= r; i++) {
		long long temp;
		temp = 0;
		for(long long j = 1; j <= c; j++) {
			scanf("%lld",&list[i][j]);
			temp+=list[i][j];
			bar[i][j] = temp;
		}
		brs[i] = temp;
	}
	for(long long i = 1; i <= r; i++) {
		kol[0][i] = kol[0][i-1] + list[i][1];
		kol[1][i] = kol[1][i-1] + list[i][c];
// 		printf("-- %lld --> %lld %lld\n",i,kol[0][i], kol[1][i]);
	}
	
	precompute();
	
//	for(long long i = 1; i <= r; i++) {
//		for(long long j = 1; j <= r; j++) {
//			for(long long k = 0; k <= 3; k++) {
//				printf("%lld %lld %lld %lld --> %lld\n", i, k/2, j, k%2, dp[i][k/2][j][k%2][0]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
	
	scanf("%lld",&d);
	y = 1;
	x = 1;
	ans = 0;
	while(d--) {
		scanf("%lld%lld", &a, &b);
		if(d!=0) {
			ans -= list[a][b];
		}
		long long temp;
		temp = INF;
		if (a == y) {
			temp = bar[a][max(x,b)] - bar[a][min(x,b)-1];
//			printf("-- %lld --\n",temp);
		}
		long long porer;
//		kiri kiri
		porer = 0;
		porer = bar[y][x]-bar[y][1];
		porer += bar[a][b]-bar[a][1];
		porer += dp[y][0][a][0][0];
//		printf("-- %lld --\n",porer);
		temp = min(temp, porer);
		
//		kiri kanan
		porer = 0;
		porer = bar[y][x]-bar[y][1];
		porer += bar[a][c-1] - bar[a][b-1];
		porer += dp[y][0][a][1][0];
//		printf("-- %lld --\n",porer);
		temp = min(temp,porer);
		
//		kanan kiri
		porer = 0;
		porer = bar[y][c-1] - bar[y][x-1];
		porer += bar[a][b]-bar[a][1];
		porer += dp[y][1][a][0][0];
//		printf("-- %lld --\n",porer);
		temp = min(temp, porer);
		
//		kanan kanan
		porer = 0;
		porer = bar[y][c-1] - bar[y][x-1];
		porer += bar[a][c-1] - bar[a][b-1];
		porer += dp[y][1][a][1][0];
//		printf("-- %lld --\n",porer);
		temp = min(temp, porer);
		
//		printf("--- %lld ---\n",temp);
		ans += temp;
		y = a;
		x = b;
	}
	printf("%lld\n",ans);
	return 0;
}
