#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long list[105], n, l, ans;

long long f(long long skrg, long long sisa) {
	if(skrg == 1) {
		return list[1] * sisa;
	}
	long long tmp = floor(1.0 * sisa / (1 << (skrg - 1)));
	long long ret, a, b;
	a = (long long)(ceil(1.0 * sisa / (1 << (skrg - 1))) * list[skrg]);
	b = tmp * list[skrg] + f(skrg - 1, sisa - tmp * (1 << (skrg - 1)));
	ret = min(a, b);
	// printf("%lld %lld %lld %lld --> %lld %lld\n", tmp, skrg, sisa, ret, a, b);
	return ret;
}

int main(){
	scanf("%lld%lld", &n, &l);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &list[i]);
		if(i > 1) {
			list[i] = min(list[i], list[i - 1] * 2);
		}
	}
	// for(int i = 1; i <= n; i++) {
	// 	printf("%d --> %lld\n", i, list[i]);
	// }
	ans = f(n, l);
	printf("%lld\n", ans);
	return 0;
}