#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

long long n;
map <int, int> dp;

long long koin(long long x) {
	// printf("%lld\n", x);
	if(x == 0) {
		return 0;
	}
	if(dp.count(x)) {
		return dp[x];
	}
	dp[x] = max(x,koin(x/2)+koin(x/3)+koin(x/4));
	// printf("%lld --> %lld %lld %lld = %lld\n", x, x/2, x/3, x/4, koin(x/2) + koin(x/3) + koin(x/4)) ;
	return dp[x];
}
int main() {
	while (scanf("%lld",&n)!=EOF) {
		printf("%lld\n",koin(n));
	}
}
