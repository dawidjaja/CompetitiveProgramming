#include <algorithm>
#include <cstdio>

using namespace std;

int n, d, ttl, tmp, ans, x;

int main() {
	scanf("%d%d", &n, &d);
	ttl = 0;
	tmp = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if(x == 0) {
			if(ttl < 0) {
				if(ttl + tmp < 0) {
					ans++;
					tmp = d;
					ttl = 0;
				} else {
					ttl += tmp;
					tmp = 0;
					continue;
				}
			}
		} else {
			ttl += x;
			if(ttl > d) {
				printf("-1\n");
				return 0;
			}
			tmp = min(d - ttl, tmp);
		}
	}
	printf("%d\n", ans);
	return 0;
}