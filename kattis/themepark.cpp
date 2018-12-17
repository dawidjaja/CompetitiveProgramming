#include <algorithm>
#include <cstdio>

using namespace std;

long long tt, r, k, n, g[1005], nx[1005], profit[1005], cycle[1005], l, kn, ans, tmp, t, h, sum, ctrr, ctrl;

int main() {
	scanf("%lld", &tt);
	for (long long _ = 1; _ <= tt; _++) {
		scanf("%lld%lld%lld", &r, &k, &n);
		for (long long i = 0; i < n; i++) {
			scanf("%lld", &g[i]);
			cycle[i] = 0;
			nx[i] = -1;
			profit[i] = 0;
		}
		l = 0; kn = 1;
		tmp = g[0];
		while (l < n) {
			while (tmp + g[kn] <= k) {
				tmp += g[kn++];
				kn %= n;
				if (kn == l) {
					break;
				}
			}
			nx[l] = kn;
			profit[l] = tmp;
			tmp -= g[l];
			l++;
		}
		// for(int i = 0; i < n; i++) {
		// 	printf("%d --> %lld\n", i, nx[i]);
		// }
		if (n == 1) {
			ans = r;
		} else {
			t = nx[0];
			h = nx[t];
			while (t != h) {
				t = nx[t];
				h = nx[nx[h]];
			}
			sum = 0;
			ctrr = 0;
			while (cycle[t] == 0) {
				cycle[t] = 1;
				sum += profit[t];
				ctrr++;
				t = nx[t];
			}
			t = 0;
			ans = 0;
			while (cycle[t] == 0 && r) {
				ans += profit[t];
				t = nx[t];
				r--;
			}
			if (r) {
				long long ctrl = r / ctrr;
				ans += sum * ctrl;
				r %= ctrr;
				while (r) {
					ans += profit[t];
					t = nx[t];
					r--;
				}
			}
		}
		printf("Case #%lld: %lld\n", _, ans);
	}
	return 0;
}