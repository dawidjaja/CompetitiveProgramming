#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	scanf("%d%d%d%d%d", &n, &m, &r, &k, &p);
	for(int i = 0; i <= 4 * n + 1; i++) {
		list[0][i].push_back(0);
	}
	for(int i = 0; i <= 4 * m + 1; i++) {
		list[1][i].push_back(0);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &list[i][j]);
		}
	}
	while(k--) {
		
	}
	return 0;
}