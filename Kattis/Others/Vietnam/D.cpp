#include <algorithm>
#include <cstdio>

using namespace std;

int n, teh[1005], m, top[1005], ans, k, x, duit;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &teh[i]);
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &top[i]);
	}
	ans = 2005;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &k);
		while(k--){
			scanf("%d", &x);
			ans = min(ans, teh[i] + top[x]);
		}
	}
	if(ans == 2005) {
		printf("0\n");
		return 0;
	} else {
		scanf("%d", &duit);
		printf("%d\n", max(duit / ans - 1, 0));
	}

	return 0;
}