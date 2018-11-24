#include <algorithm>
#include <cstdio>

using namespace std;

long long n, k, cek[50005], fr[50005], win[50], ans, x;

int main() {
	scanf("%lld%lld", &n, &k);
	for(long long i = 1; i <= n; i++) {
		for(long long j = 1; j <= k; j++) {
			scanf("%lld", &x);
			if(x > cek[j]) {
				cek[j] = x;
				if(win[j] != 0) {
					fr[win[j]]--;
					if(fr[win[j]] == 0) {
						ans--;
					}
				}
				win[j] = i;
				fr[win[j]]++;
				if(fr[win[j]] == 1) {
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}