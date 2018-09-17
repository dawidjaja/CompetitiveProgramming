#include <algorithm>
#include <cstdio>

using namespace std;

int n, ans, list[1005], nol[1005], satu[1005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &list[i]);
		nol[i] = nol[i - 1] + 1 - list[i];
	}
	for(int i = n; i >= 1; i--) {
		satu[i] = satu[i + 1] + list[i];
	}
	ans = 1;
	for(int i = 1; i <= n; i++) {
		ans = max(nol[i] + satu[i], ans);
	}
	printf("%d\n", ans);
	return 0;
}