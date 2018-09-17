#include <algorithm>
#include <cstdio>

using namespace std;

int n, k, list[105], ans;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &list[i]);
	}
	int b = n / k;
	for(int i = 0; i < k; ++i) {
		int ctra = 0;
		int ctrb = 0;
		for(int j = 0; j < b; ++j){
			if(list[j * k + i] == 1) {
				ctra++;
			} else {
				ctrb++;
			}
		}
		// printf("-- %d %d\n", ctra, ctrb);
		ans += min(ctra, ctrb);
	}
	printf("%d\n", ans);
	return 0;
}