#include <algorithm>
#include <cstdio>

using namespace std;

int n, a, b, list[1005], cost;

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	for (int i = 0; i < n / 2; i++) {
		int x = list[i];
		int y = list[n - i - 1];
		if (x + y == 4) {
			cost += 2 * min(a, b);
		} else if (x + y == 1) {
			printf("-1\n");
			return 0;
		} else if (x + y == 2 && x != y) {
			cost += a;
		} else if (x + y == 3) {
			cost += b;
		}
	}
	if ((n & 1) && list[n / 2] == 2) {
		cost += min(a, b);
	}
	printf("%d\n", cost);
	return 0;
}