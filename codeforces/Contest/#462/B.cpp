#include <algorithm>
#include <cstdio>

using namespace std;

int k;

int main() {
	scanf("%d", &k);
	if(k > 2 * 18) {
		printf("-1\n");
		return 0;
	} else {
		while(k) {
			if(k >= 2) {
				printf("8");
				k -= 2;
			} else if(k == 1) {
				printf("6");
				k--;
			}
		}
		printf("\n");
	}
	return 0;
}