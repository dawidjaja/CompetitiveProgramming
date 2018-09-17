#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	scanf("%d%d", &n, &k);
	k = n - k;
	n -= k;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &list[i].fs, &list[i].sc);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d%d", &add[i].fs, &add[i].sc);
	}
	
	return 0;
}