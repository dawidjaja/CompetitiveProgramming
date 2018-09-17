#include <algorithm>
#include <cstdio>

#define INF 1e12

using namespace std;

long long dp[2][2005][2005], n, list[2005], ans;

#define getchar_unlocked() getchar()
inline long long baca() {
	long long temp = 0;
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

long long f(long long l, long long r, long long k) {
//	printf("-- %lld %lld --\n", l, r);
	if(l > r) {
		return 0;
	}
	if(l == r) {
		return list[l];
	}
	if(dp[k][l][r] != -1) {
		return dp[k][l][r];
	}
	long long hsl1, hsl2, ret, dif, mid1, mid2, ki, ka;
	ki = l;
	ka = r;
	ret = INF;
	while(ki < ka) {
		if(l == 1 && r == 9) {
			printf("kika %lld %lld --\n", ki, ka);
		}
		dif = ka - ki;
		dif /= 3;
		mid1 = ki + dif;
		mid2 = ka - dif;
		hsl1 = max(f(l, mid1 - 1, k), f(mid1 + 1, r, k)) + list[mid1]; 
		hsl2 = max(f(l, mid2 - 1, k), f(mid2 + 1, r, k)) + list[mid2]; 
		if(l == 1 && r == 9) {
			printf("hasil %lld --> %lld && %lld --> %lld\n", mid1, hsl1, mid2, hsl2);
		}
		if(ka - ki <= 2) {
			if(ka - ki == 1) {
				if(hsl1 < hsl2) {
					ka = ki;
				} else {
					ki = ka;
				}
			} else {
				if(hsl1 < hsl2) {
					ka--;
				} else {
					ki++;
				}
			}
		} else if(hsl1 <= hsl2) {
			ka = mid2;
		} else {
			ki = mid1;
		}
	}
	printf("%lld %lld --->>> %lld\n", l, r, ki);
	dp[k][l][r]  = max(f(l, ki - 1, k), f(ki + 1, r, k)) + list[ki]; 
	return dp[k][l][r];
}


int main() {
//	scanf("%d", &n);
	n = baca();
	for(long long i = 1; i <= n; i++) {
//		scanf("%d", &list[i]);
		list[i] = baca();
		for(long long j = 1; j <= n; j++) {
			dp[0][i][j] = -1;
			dp[1][i][j] = -1;
		}
	}
	ans = f(1, n, 0);
	for(int i = 1; i <= n/2; i++) {
		swap(list[i], list[n-i+1]);
	}
	ans = min(ans, f(1, n, 1));
	printf("%lld", ans);
	return 0;
}

