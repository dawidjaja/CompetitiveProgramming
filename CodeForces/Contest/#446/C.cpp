#include <algorithm>
#include <cstdio>

using namespace std;

int n, list[2005], fpb, tmpa, tmpb, ceka, cekb, aa, bb, ans, anstmp, ctra, ctrb, tmp, lala, satu, lbr, cek;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		if(list[i] == 1) {
			satu++;
		}
		if(i == 1) {
			fpb = list[i];
		} else {
			fpb = __gcd(list[i], fpb);
		}
	}
	if(fpb == 1) {
		if(satu) {
			ans = n - satu;
		} else {
			lbr = n;
			cek = 0;
			ans = n - 1;
			while(true) {
				ans++;
				for(int i = 1; i < lbr; i++) {
					list[i] = __gcd(list[i], list[i + 1]);
					if(list[i] == 1) {
						cek = 1;
						break;
					}
				}
				lbr--;
				if(cek) {
					break;
				}
			}
		}
		printf("%d\n", ans);
	} else {
		printf("-1\n");
	}
	return 0;
}