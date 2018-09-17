#include <algorithm>
#include <cstdio>

using namespace std;

int n, list[100005], t;

int main() {
	list[0] = 1;
	for(int i = 1; i <= 100; i++) {
		if(i - 3 >= 0 && list[i - 3] == 1) {
			list[i] = 1;
		}
		if(i - 7 >= 0 && list[i - 7] == 1) {
			list[i] = 1;
		}
	}
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &t);
		if(list[t]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}