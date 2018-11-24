#include <algorithm>
#include <cstdio>

using namespace std;

int a, n;

int main() {
	scanf("%d", &a);
	if(a == 1) {
		n = 1;
	} else {
		n = (a - 1) * 2;
	}
	printf("%d 2\n", n);
	printf("1 2\n");
	return 0;
}