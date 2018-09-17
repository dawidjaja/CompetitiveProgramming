#include <algorithm>
#include <cstdio>

using namespace std;

int n, a, b, k, l;

int f(int skrg, int sblm) {
	int ret = 0;
	if(skrg == n + 1) {
		return 1;
	}
	for(int i = 1; i <= k; i++) {
		if(i != sblm) {
			if(skrg == n && i == b) {
				continue;
			}
			ret += f(skrg + 1, i);
		}
	}
	return ret;
}

int main() {
	while(scanf("%d%d%d", &n, &k, &l)) {
		a = 1; b = l;
		printf("%d\n", f(1, a));
	}
	return 0;
}