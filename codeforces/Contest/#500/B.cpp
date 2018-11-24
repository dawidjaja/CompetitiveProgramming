#include <algorithm>
#include <cstdio>

using namespace std;

int n, x, list[100005], freq[100005][5], ans;

int main() {
	scanf("%d%d", &n, &x);
	ans = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		freq[list[i]][0]++;
		if (freq[list[i]][0] == 2) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int tmp = list[i] & x;
		if (tmp == list[i]) continue;
		if (freq[tmp][0] == 1) {
			printf("1\n");
			return 0;
		}
		if (freq[tmp][1] == 1) {
			ans = 2;
		}
		freq[tmp][1] = 1;
	}
	printf("%d\n", ans);
}