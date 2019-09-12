#include <algorithm>
#include <cstdio>

using namespace std;

int n, list[1000005], kcl, ans, stat;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
	}
	kcl = n + 1;
	stat = 1;
	for(int i = n; i >= 1; i--) {
		if(i < kcl) {
			stat = 1;
		} else {
			stat = 0;
		}
		ans += stat;
		kcl = min(kcl, i - list[i]);
	}
	printf("%d\n", ans);
	return 0;
}