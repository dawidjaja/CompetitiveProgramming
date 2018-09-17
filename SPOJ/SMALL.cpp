#include <algorithm>
#include <iostream>
#include <cstdio>

#define MOD 1000000007

using namespace std;

int t;
long long list[10005], temp, n, cek[10005];

void sieve() {
	for(int i = 1; i <= 10000; i++) {
		list[i] = 1;
		cek[i] = 1;
	}
	for(int i = 2; i <= 10000; i++) {
		if(cek[i] == 1) {
			for(int j = i*2; j <= 10000; j += i) {
				cek[j] = 0;
			}
		}
		if(cek[i] == 1) {
			for(int j = i; j <= 10000; j *= i) {
				list[j] *= i;
				list[j] = list[j] % MOD;
			}
		}
		list[i] *= list[i-1];
		list[i] = list[i] % MOD;
	}
}

int main() {
	sieve();

	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &n);
		printf("%lld\n", list[n]);
	}
	return 0;
}