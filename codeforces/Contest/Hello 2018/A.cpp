#include <algorithm>
#include <cstdio>

using namespace std;

long long n, list[100005], ans, m, tmp;

long long pngkt(long long x, long long t) {
	long long ret;
	if(t == 0) {
		return 1;
	}
	if(t == 1) {
		return x;
	} else {
		ret = pngkt(x, t / 2);
		ret = (ret * ret);
		if(t & 1) {
			ret *= x;
			ret = ret;
		}
	}
	if(ret > m) {
		return m + 1;
	}
	return ret;
}

int main() {
	scanf("%lld%lld", &n, &m);
	tmp = pngkt(2, n);
	printf("%lld\n", m % tmp);
	return 0;
}