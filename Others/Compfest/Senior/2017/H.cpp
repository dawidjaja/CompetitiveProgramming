#include <algorithm>
#include <cstdio>
#include <assert.h>

using namespace std;

long long t, m, n, k, list[100005], kcl, ps[100005];
long long ans;

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld%lld", &m, &n, &k);
		if(m == 0) {
			printf("0\n");
			continue;
		}
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &list[i]);
			list[i] = k - list[i];
		}
		kcl = 0;
		for(int i = 1; i <= n; i++) {
			ps[i] = ps[i - 1] + list[i];
			kcl = min(kcl, ps[i]);
		}
		
		// for(int i = 1; i <= n; i++) {
		// 	printf("%d ", list[i]);
		// }
		// printf("\n");
		// for(int i = 1; i <= n; i++) {
		// 	printf("%d ", ps[i]);
		// }
		// printf("\n");

		if(kcl == 0) {
			// printf("aaa\n");
			printf("-1\n");
			continue;
		} else if(ps[n] >= 0) {
			// printf("bbb\n");
			if(m <= -kcl) {
				ans = 0;
				for(int i = 1; i <= n; i++) {
					if(m <= 0) {
						if(m < 0) {
							ans--;
						}
						break;
					}
					m += list[i];
					ans++;
				}
				printf("%lld\n", ans);
			} else {
				printf("-1\n");
			}
			continue;
		} else {
			// printf("ccc\n");
			assert(false);
			m += kcl;
			ans = m / -ps[n] * n;
			m = m % -ps[n];
			m -= kcl;
			// printf("-- %lld --\n", ans);
			bool cek = 1;
			for(int j = 1; j <= 2; j++) {
				for(int i = 1; i <= n; i++) {
					if(m <= 0) {
						if(m < 0) {
							// printf("asdfasdf\n");
							ans--;
						}
						cek = 0;
						break;
					}
					m += list[i];
					ans++;
				}
				if(!cek) {
					break;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
