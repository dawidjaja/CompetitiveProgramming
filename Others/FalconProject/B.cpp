#include <algorithm>
#include <cstdio>

using namespace std;

int a[10], x, y, z, list[10];

int main() {
	a[1] = 18000;
	a[2] = 14400;
	a[3] = 11520;
	a[4] = 7920;
	scanf("%d%d%d", &x, &y, &z);
	x *= 5000;
	y *= 10000;
	z *= 19000;
	for(int i = 1; i <= 4; i++) {
		list[i] += x / a[i];
		x = x % a[i];
	}
	for(int i = 1; i <= 4; i++) {
		list[i] += y / a[i];
		y = y % a[i];
	}
	for(int i = 1; i <= 4; i++) {
		list[i] += z / a[i];
		z = z % a[i];
	}
	printf("%d %d %d %d\n", list[3], list[4], list[2], list[1]);
	printf("%d\n", x + y + z);
	return 0;
}
