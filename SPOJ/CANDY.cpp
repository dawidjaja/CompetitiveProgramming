#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int list[10005], n, ttl;

int main() {
	while(scanf("%d", &n) && n != -1) {
		ttl = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &list[i]);
				ttl += list[i];
		}
		if(ttl % n == 0) {
			int temp = ttl / n;
			int ans = 0;
			for(int i = 1; i <= n; i++) {
				ans += abs(temp - list[i]);
			}
			printf("%d\n", ans/2);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}