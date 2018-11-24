#include <algorithm>
#include <cstdio>

using namespace std;

char ans[10];
int n, l, r, mid;

inline void tulis(int x) {
	int temp = 1;
	int ctr = 9;
	for(int i = 1; i <= 10; i++) {
		if(x < temp) {
			break;
		}
		ctr--;
		temp *= 10;
	}
	while(ctr--) {
		printf("0");
	}
	printf("%d\n", x);
	fflush(stdout);
}

int main() {
	printf("? 999999999\n");
	fflush(stdout);
	scanf("%s", &ans);
	if(ans[0] == 'N') {
		printf("! 1000000000\n");
		fflush(stdout);
		return 0;
	}
	printf("? 999999999999999999\n");
	fflush(stdout);
	scanf("%s", &ans);
	if(ans[0] == 'N') {
		printf("! 999999999\n");
		fflush(stdout);
		return 0;
	}
	l = 1;
	r = 999999999;
	while(l < r) {
		printf("? 999999999");
		mid = ((l + r) >> 1) + 1;
		tulis(mid);
		scanf("%s", &ans);
		if(ans[0] == 'N') {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("! ");
	tulis(l);
	return 0;
}