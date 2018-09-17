#include <algorithm>
#include <cstdio>

using namespace std;

int x, y, n, t, cek;

int main() {
	freopen(("D.in"), "r", stdin);
	scanf("%d%d", &x, &y);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		if(n == 2) {
				printf("YES\n");
		} else {
			cek = 0;
			if((y - 2) % n == 0 && x % n == 0) {
				cek = 1;
			} else if((x - 2) % n == 0 && (y % n) == 0) {
				cek = 1;
			} else if((y - 1) % n == 0 && (x - 1) % n == 0) {
				cek = 1;
			}
			if(cek) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}