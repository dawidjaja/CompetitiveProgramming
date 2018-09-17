#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

int n, awal[1500000], list[1500000], N;
map <int, int> ans;

int loog(int x) {
	int ret = N;
	while(x > 1) {
		x = (x >> 1);
		ret--;
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	int n = (1 << N);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &awal[i]);
		list[i] = awal[i];
	}
	sort(list+1, list+1+n);
//	for(int i = 1; i <= n; i++) {
//		printf("%d %d\n", list[i], awal[i]);
//	}
	ans[list[n]] = 0;
	for(int i = n-1; i >= 1; i--) {
		if(list[i] == list[i+1]) {
			continue;
		} else {
			ans[list[i]] = loog(i);
		}
	}
	for(int i = 1; i < n; i++) {
		printf("%d ", ans[awal[i]]);
	}
	printf("%d\n", ans[awal[n]]);
	return 0;
}
