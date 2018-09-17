#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, p[1005], tmp, cek, a, b;
int par(int x) {
	if(p[x] == x) {
		return x;
	} else {
		return p[x] = par(p[x]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	if(n - 1 == m) {
		for(int i = 1; i <= n; ++i) {
			p[i] = i;
		}
		for(int i = 1; i <= m; ++i) {
			scanf("%d%d", &a, &b);
			p[par(a)] = par(b);
		}
		tmp = par(1);
		cek = 1;
		for(int i = 2; i <= n; ++i) {
			if(par(i) != tmp) {
				cek = 0;
			}
		}
		if(cek) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	} else {
		printf("no\n");
	}
	return 0;
}