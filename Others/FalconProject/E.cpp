#include <algorithm>
#include <cstdio>

using namespace std;

int bln[20], list[5], a, b, c, cek;

int main() {
	scanf("%d%d%d", &list[0], &list[1], &list[2]);
	bln[1] = bln[3] = bln[5] = bln[7] = bln[8] = bln[10] = bln[12] = 31;
	bln[2] = 28;
	bln[4] = bln[6] = bln[9] = bln[11] = 30;
	sort(list, list + 3);
	cek = 0;
	do {
		// if(list[2]%4) {
		// 	bln[2] = 28;
		// } else {
		// 	bln[2] = 29;
		// }
		if(list[1] > 12) {
			continue;
		}
		if(list[0] > bln[list[1]]) {
			continue;
		}
		cek++;
		a = list[0];
		b = list[1];
		c = list[2];
	} while(next_permutation(list, list + 3));
	if(cek == 1) {
		printf("%02d/%02d/%02d", a, b, c);
	} else {
		printf("SELAMAT\n");
	}
	return 0;
}
