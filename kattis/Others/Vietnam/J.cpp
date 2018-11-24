#include <algorithm>
#include <cstdio>
#include <cmath>

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
		// printf("%lf %lf %lf\n", a, b, c);
		h = -b + sqrt(pow(b, 2) - 4 * a * c);

		h /= 2 * a;
		h = -h;
		// printf("%lf\n", h);
		ans = h * (x - 2 * h) * (y - 2 * h);
		printf("%lf\n", ans);
	}
	return 0;
}