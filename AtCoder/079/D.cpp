#include <algorithm> 
#include <cstdio>

using namespace std;

long long k, n, sisa, temp, tmbh, ctr, list[105];

int main() {
	scanf("%lld", &k);
	n = 50;
	sisa = k % n;
	temp = k / n;
	tmbh = temp * (n + 1);
	ctr = 1;
	// printf("%lld %lld %lld\n", sisa, temp, tmbh);
	for(int i = 1; i <= n - sisa; i++) {
		list[ctr++] = 50 + tmbh - (k + 1);
	}
	for(int i = n - sisa + 1; i <= n; i++) {
		list[ctr++] = 50 + tmbh + n - k;
	}
	printf("50\n");
	// sort(list + 1, list + 51);
	for(int i = 1; i < 50; i++) {
		printf("%lld ", list[i]);
	}
	printf("%lld\n", list[50]);
	return 0;
}