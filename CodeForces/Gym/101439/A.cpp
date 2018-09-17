#include <algorithm>
#include <cstdio>

using namespace std;

int a, b, n, ans, cek[200005], list[200005];

int main() {
	scanf("%d", &n);
	cek[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		if(cek[list[i] - 1] == 0) {
			ans++;
		}
		cek[list[i]] = 1;
	}
	printf("%d\n", ans);
	return 0;
}