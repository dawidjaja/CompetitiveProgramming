#include <algorithm>
#include <cstdio>

using namespace std;

char a[20][20];
int t, x, y, z, tipe, bit, ans;

int cek() {
	for(int i = 1; i <= 4; i++) {
		if(a[i][0] == 'B') {
			a[i][0] = 'A';
		}
		if(a[i][0] == 'N') {
			a[i][0] = 'E';
		}
	}
	if(a[1][0] == a[2][0]) {
		return 1;
	}
	if(a[1][0] == a[3][0]) {
		return 2;
	}
	if(a[1][0] == a[4][0]) {
		return 3;
	}
}

inline void urut() {
	for(int i = 1; i <= 2; i++) {
		if(x > y) {
			swap(x, y);
		}
		if(y > z) {
			swap(y, z);
		}
	}
}

inline bool satu() {
	if(x&1 == 1) {
		return false;
	}
	if(x == y && y == z) {
		return true;
	}
	if(x == y && y+1 == z) {
		return true;
	}
	return false;
}

inline bool tiga() {
	if(x&1 == 1) {
		return false;
	}
	if(x + 2 == z && y <= x+1) {
		return true;
	}
	if(x + 1 == z) {
		return true;
	}
	if(x == y && z > x) {
		return true;
	}
	if(x+1 == y) {
		return true;
	}
	return false;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &x, &y, &z);
		scanf("%s", a[1]);
		scanf("%s", a[2]);
		scanf("%s", a[3]);
		scanf("%s", a[4]);
		tipe = cek();
//		printf("%d\n", tipe);
		urut();
		bit = ((x ^ y) ^ z);
//		printf("%d --> %d %d %d\n", bit, x, y, z);
		if(tipe == 1) {
			if(satu()) {
				ans = 2;
			} else {
				ans = 1;
			}
		} else if(tipe == 2) {
			if(bit == 0) {
				ans = 2;
			} else {
				ans = 1;
			}
		} else {
			if(tiga()) {
				ans = 1;
			} else {
				ans = 2;
			}
		}
		if(ans == 1) {
			if(a[1][0] == 'E') {
				printf("Elayne/Nynaeve\n");
			} else {
				printf("Aviendha/Birgitte\n");
			}
		} else {
			if(a[1][0] == 'E') {
				printf("Aviendha/Birgitte\n");
			} else {
				printf("Elayne/Nynaeve\n");
			}
		}
	}
	return 0;
}
