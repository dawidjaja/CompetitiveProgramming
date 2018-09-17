#include <algorithm>
#include <cstdio>

using namespace std;

long long ans, mod, n, t;

inline long long baca()
{
	long long temp = 0;
	char c;
	c = getchar_unlocked();
//	c = getchar();
	while(c < '0' || c > '9')
	{
//		c = getchar();
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9')
	{
		temp *= 10;
		temp += c - '0';
//		c = getchar();
		c = getchar_unlocked();
	}
	return temp;
}

long long pngkt(long long a, long long b) {
	if(b == 0) {
		return 1;
	} 
	if(b == 1) {
		return a;
	}
	long long temp;
	temp = pngkt(a, b >> 1);
	temp *= temp;
	temp = temp % mod;
	if(b&1) {
		temp *= a;
		temp = temp % mod;
	}
	return temp;
}

int main() {
	t = baca();
	while(t--) {
		n = baca();
		mod = baca();
		if(n == 1) {
			ans = 100;
		} else if(n == 2) {
			ans = 136;
		} else if(n == 3) {
			ans = 1425;
		} else {
			long long temp;
			temp = (n+3) % mod;
			ans = ((((((((n-1)%mod)*temp)%mod)*temp)%mod + ((temp*2)%mod) + 1)%mod) * (pngkt(temp,n)));
//			ans += (pngkt(temp, n)*temp*2);
//			ans += pngkt(temp, n);
			ans += pngkt(temp, 3);
		}
		ans = ans % mod; 
		printf("%lld\n", ans);
	}
	return 0;
}


