#include <algorithm>
#include <cstdio>

using namespace std;
#define getchar_unlocked() getchar()
inline int baca() {
	int temp = 0;
	char c;
	c = getchar_unlocked();
	while (c < '0' || c > '9') {
		c = getchar_unlocked();
	}
	while (c >= '0' && c <= '9') {
		temp *= 10;
		temp += c - '0';
		c = getchar_unlocked();
	}
	return temp;
}

int fpb (int a, int b)
{
	return b ? fpb(b, a mod b) : a;
}

int n, kcl, gede, ctr;

int main() {
	n = baca();
	gede = 0;
	kcl = n;
	for (int i = 1; i <= n; i++) {
		int a;
		a = baca();
		if(a >= n) {
			printf("-1\n");
			return 0;
		}
		if (gede == a) {
			ctr++;
		} else if (a > gede) {
			ctr = 1;
		}
		gede = max(a, gede);
		kcl = min(a, kcl);
	}
	if ((gede - kcl == 1 && ctr == n - gede) || gede == 0) {
		printf("%d\n", gede);
	} else if (gede == kcl) {
		printf("%d\n", gede + 1);
	} else {
		printf("-1\n");
	}
	return 0;
}