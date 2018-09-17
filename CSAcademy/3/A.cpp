#include <algorithm>
#include <cstdio>

using namespace std;

int n, ans, kcl, gde, list[5005];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		if(i == 1) {
			kcl = list[1];
			gde = list[1];
		} else {
			kcl = min(kcl, list[i]);
			gde = max(gde, list[i]);
		}
	}
	ans = n;
	for(int i = 1; i <= n; i++) {
		if(list[i] == gde) {
			for(int j = i; j <= n; j++) {
				if(list[j] == kcl) {
					ans = min(ans, j - i + 1);
				}
			}
		} else if(list[i] == kcl) {
			for(int j = i; j <= n; j++) {
				if(list[j] == gde) {
					ans = min(ans, j - i + 1);
				}
			}
		}
	}
	printf("%d\n", ans);
}