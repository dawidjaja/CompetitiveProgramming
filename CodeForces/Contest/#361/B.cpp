#include <algorithm>
#include <cstdio>

using namespace std;

int n, list[200005], kcl[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		kcl[i] = i - 1;
	}
	int temp = 0;
	for(int i = 1; i <= n; i++) {
		// printf("%d ", kcl[i]);
		kcl[i] = min(kcl[i - 1] + 1, kcl[i]);
		kcl[list[i]] = min(kcl[list[i]], kcl[i] + 1);
		// kcl[list[i] + 1] = min(kcl[list[i] + 1], kcl[list[i]] + 1);
	}

	// for(int i = 1; i <= n; i++) {
	// 	printf("%d ", kcl[i]);
	// }
	// printf("\n");
	for(int i = n - 1; i >= 1; i--) {
		kcl[i] = min(kcl[i], kcl[i + 1] + 1);
	}
	for(int i = 1; i < n; i++) {
		printf("%d ", kcl[i]);
	}
	printf("%d\n", kcl[n]);
	return 0;
}