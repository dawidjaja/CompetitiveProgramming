#include <algorithm>
#include <cstdio>

using namespace std;

int at, ba, a, n, x[15], y[15], ka, ki, list[15];

int main() {
	scanf("%d", &n);
	x[1] = x[4] = x[7] = 1;
	x[2] = x[5] = x[8] = x[0] = 2;
	x[3] = x[6] = x[9] = 3;

	y[1] = y[2] = y[3] = 1;
	y[4] = y[5] = y[6] = 2;
	y[7] = y[8] = y[9] = 3;
	y[0] = 4;
	ka = 0;
	ki = 4;
	at = 5;
	ba = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%1d", &a);
		ki = min(ki, x[a]);
		ka = max(ka, x[a]);
		at = min(at, y[a]);
		ba = max(ba, y[a]);
		// if(a == 0) {
		list[a] = 1;
		// }
	}
	int temp = ka - ki;
	int po = ba - at;
	int cek = 0;
	if(temp == 0) {
		if(po <= 2) {
			cek = 1;
		}
	} else if(temp == 1) {
		if(po <= 2) {
			cek = 1;
		}
	} else if(temp == 2) {
		if(po <= 1) {
			cek = 1;
		}
		if(po == 2) {
			if((list[0] == 1) || ((list[8] == 1) && (list[7] == 0) && (list[9] == 0))) {
				cek = 1;
			}
		}
	}
	// printf("-- %d %d --\n", temp, po);
	// for(int i = 0; i <= 9; i++) {
	// 	printf("%d %d\n", i, list[i]);
	// }
	if(cek) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	return 0;
}