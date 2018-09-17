#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n, x;
double ans;

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		ans += log10(x);
	}
	printf("%d\n", (int) floor(ans) +1);
	return 0;
}
