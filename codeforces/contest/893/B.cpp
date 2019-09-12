#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int a, ans, ctr, tmp;

int main() {
	scanf("%d", &a);
	tmp = -1;
	ctr = 1;
	ans = 0;
	while(tmp < a) {
		tmp = (pow(2, ctr) - 1) * pow(2, ctr - 1);
		if(a % tmp == 0) {
			ans = tmp;
		}
		ctr++;
	}
	printf("%d\n", ans);
	return 0;
}