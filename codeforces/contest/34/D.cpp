#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

long long n, x, a, b, c, ans, ttl;
map <int, int> freq;

long long bnyk(long long x) {
	if(freq.count(x)) {
		return freq[x];
	} else {
		return 0;
	}
}

int main() {
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &x);
		a = bnyk(x - 1);
		b = bnyk(x);
		c = bnyk(x + 1);
		ans += x * (i - 1 - a - b - c) - (ttl - (x - 1) * a - x * b - (x + 1) * c);
		ttl += x;
		freq[x]++;
		if(i % 1000 == 0) {
			printf("%d\n", i);
		}
	}
	printf("%lld\n", ans);
	return 0;
}