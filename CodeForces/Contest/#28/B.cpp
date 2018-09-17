#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, k, ttl, list[105], ctr, temp, ans;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	ttl = 0;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &list[i]);
		ttl += list[i];
	}
	if(k >= ttl * n) {
		printf("%d\n", (m + 1) * n);
		return 0;
	}
	sort(list + 1, list + 1 + n);
	ctr = 1;
	ans = 0;
	while(k > list[ctr] && ctr <= m) {
		if(k >= list[ctr] * n) {
			k -= list[ctr] * n;
			ans += n;
			if(ctr == m) {
				ans += n;
			}
			ctr++;
		} else {
			ans += k / list[ctr];
			if(ctr == m) {
				ans += k / list[ctr];
			}
			k = 0;
			break;
		}
	}
	temp = (k / ttl) * (m + 1);
	k %= ttl;
	for(int i = 1; i <= m; i++) {
		if(k >= list[i]) {
			k -= list[i];
			temp++;
		} else {
			break;
		}
	}
	ans = max(ans, temp);
	printf("%d\n", ans);
	return 0;
}