#include <algorithm>
#include <cstdio>
using namespace std;

int n, cek, ans, nol, awal, buang;
char c;

int main() {
	scanf("%d", &n);
	getchar();
	cek = 0;
	ans = 0;
	nol = 0;
	awal = 0;
	for(int i = 1; i <= n; i++) {
		c = getchar();
		if(c == '0') {
			if(!cek) {
				nol++;
			}
		} else if(c == '1') {
			cek = 1;
		} else {
			buang++;
		}
	}
	if(cek) {
		printf("%d\n", buang + nol);
	} else if(nol) {
		printf("%d\n", buang + nol - 1);
	} else {
		printf("-1\n");
	}
	return 0;
}
