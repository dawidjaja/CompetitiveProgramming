#include <algorithm>
#include <cstdio>

using namespace std;

int n, a, b, x, y;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a += x;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &y);
		b += y;
	}
	if (a < b) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
	return 0;
}