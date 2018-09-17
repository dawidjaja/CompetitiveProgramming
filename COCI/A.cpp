#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, list[1005][1005], cek[1005], q, ans, tes;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &list[i][j]);
		}
	}
	scanf("%d", &q);
	while(q--) {
		for(int i = 1; i <= m; i++) {
			scanf("%d", &cek[i]);
		}
		ans = 0;
		for(int i = 1; i <= n; i++) {
			tes = 1;
			for(int j = 1; j <= m; j++) {
				if(cek[j] != -1 && list[i][j] != cek[j]) {
					tes = 0;
				}
			}
			if(tes) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
