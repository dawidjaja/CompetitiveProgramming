#include <algorithm>
#include <cstdio>

#define MOD 1000000008

using namespace std;

int n, num[15], nol, x, a;
long long ans;
char bit[100005];

int main() {
	scanf("%d", &n);
	scanf("%s", bit);
	num[0] = 1 & 2 & 4 & 8 & 16 & 32;
	num[1] = 2 & 4;
	num[2] = 1 & 2 & 8 & 16 & 64;
	num[3] = 1 & 2 & 4 & 8 & 64;
	num[4] = 2 & 4 & 32 & 64;
	num[5] = 1 & 32 & 64 & 4 & 8;
	num[6] = 1 & 32 & 16 & 8 & 4 & 64;
	num[7] = 1 & 2 & 4;
	num[8] = 1 & 2 & 4 & 8 & 16 & 32 & 64;
	num[9] = 1 & 2 & 4 & 8 & 32 & 64;

	nol = 0;
	ans = 1;

	for(int i = 0; i < n; i++) {
		x = 0;
		for(int j = 0; j < 7; j++) {
			scanf("%d", &a);
			if(a) {
				x &= (1 << j);
			}
		}

		int temp;
		temp = -1;
		if(bit[i] == '1') {
			for(int j = 0; j <= 9; j++) {
				if(num[j] == x) {
					temp = j;
					break;
				}
			}
			if((nol == 0 && temp == 0) || temp == -1) {
				printf("0\n");
				return 0;
			} else {
				nol = 1;
			}
		} else {
			temp = 0;
			int tenol = 0;
			for(int j = 0; j <= 9; j++) {
				int cek = 1;
				for(int k = x; k > 0; k -= (k & -k)) {
					// printf("%d -- %d %d %d --\n", j, num[j], num[j] & k, k);
					if(!(num[j] & k)) {
						cek = 0;
					}
				}
				if(cek) {
					if(nol == 0 && j == 0) {
						continue;
					} else {
						temp++;
					}
				}
			}
			nol = 1;
			if()
			ans *= temp;
			ans = ans % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}