#include <algorithm>
#include <cstdio>

using namespace std;

long long n, m, x, sisa, tmp;

int main() {
	scanf("%lld%lld", &n, &m);
	sisa = m;
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &x);
		tmp = 0;
		if (x < sisa) {
			tmp = 0;
			sisa -= x;
		} else {
			tmp = ((x - sisa) / m) + 1;
			sisa = m - ((x - sisa) % m);
			if (sisa == 0) {
				sisa = m;
			}
		}
		printf("%lld", tmp);
		if (i != n) 
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}