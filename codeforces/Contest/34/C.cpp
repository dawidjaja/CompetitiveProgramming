#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

int n, x, ans;
map <int, int> ctr;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		ctr[x]++;
		ans = max(ans, ctr[x]);
	}
	printf("%d\n", ans);
	return 0;
}