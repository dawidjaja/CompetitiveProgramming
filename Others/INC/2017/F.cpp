#include <algorithm>
#include <cstdio>

using namespace std;

int n, list[100005], k, l, r, mid;

bool valid(int x) {
	int temp = list[1];
	int cot = 1;
	for(int i = 1; i <= n; i++) {
		int porer = list[i] - temp;
		if(porer >= x) {
			temp = list[i];
			cot++;
		}
	}
	// printf("-- %d \n", cot);
	return (cot >= k);
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
	}
	sort(list + 1, list + 1 + n);
	l = 0;
	r = list[n] - list[1];
	while(r > l) {
		mid = ((l + r) >> 1) + 1;
		// printf("-- %d %d %d --\n", l, r, mid);
		if(valid(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", l);
	return 0;
}