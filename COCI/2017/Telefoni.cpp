#include <algorithm>
#include <cstdio>

using namespace std;

int n, d, skrg, temp, ans;

int main() {
	scanf("%d%d", &n, &d);
	temp = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &skrg);
		if(skrg == 1) {
			temp = 1;
		} else {
			temp++;
			if(temp > d) {
				temp = 1;
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
