#include <algorithm>
#include <cstdio>

using namespace std;

long long n, l, r, ans, nn;

int main() {
	scanf("%lld", &n);
	nn = n/2 + 1;
	l = 1;
	r = 2;
	ans = 3;
	while(r <= nn && l < r) {
		if(ans == n) {
			printf("%lld %lld\n", l, r);
			r++;
			ans += r;
			continue;
		} else if(ans < n) {
			r++;
			ans += r;
		} else {
			ans -= l;
			l++;
		}
	}
	return 0;
}
