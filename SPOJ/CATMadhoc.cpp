#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, t, a, b, s, tc, x, y;

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d%d%d%d", &a, &b, &s, &t, &x, &y);
		if((a - s == b - t && a - x == b - y && (abs(a - s) / (a - s)) == abs(a - x) / (x - a)) || 
			(a - s == t - b && a - x == y - b && (abs(a - s) / (a - s) == abs(a - x) / (a - x)))) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}