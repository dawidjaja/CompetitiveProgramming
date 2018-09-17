#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, ans;

int main() {
	freopen(("H.in"), "r", stdin);
	scanf("%d%d", &m, &n);
	ans = 0;
	for(int i = 0; i <= m; i++) {
		for(int j = i; j <= m; j++) {
			for(int k = j; k <= m; k++) {
				if(i * i + j * j == k * k) {
					ans++;
				}
			}
		}
	}
	ans += n - 2;
	ans += (n - 2) * m;
	printf("%d\n", ans);
	return 0;
}