#include <algorithm>
#include <cstdio>

using namespace std;

int x, y, t;
double a, b, c, h, ans;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &x, &y);
		a = 12;
		b = (x + y) * 4;
		c = x * y;
		h = -b + sqrt(pow(b, 2) - 4 * a * c);
		h /= 2 * a;
		ans = h * (x - 2 * h) * (y - 2 * h);
		printf("%lf\n", ans);
	}
	return 0;
}