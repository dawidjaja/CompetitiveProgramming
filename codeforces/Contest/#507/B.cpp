#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	scanf("%d%d", &n, &k);
	if (n <= k * 2 + 1) {
		printf("1\n%d\n", n / 2);
		return 0;
	}
	int a = 2 * n + 1;
	int b = n + 1;
	n = n % a;
	if (n < b) {
		n += 2 * n + 1;
	}
	
	return 0;
}