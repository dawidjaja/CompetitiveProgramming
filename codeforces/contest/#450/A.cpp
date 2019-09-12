#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n, list[100005], x, y, a, b;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		if(x < 0){
			a++;
		} else {
			b++;
		}
	}
	if(a > 1 && b > 1) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
	return 0;
}