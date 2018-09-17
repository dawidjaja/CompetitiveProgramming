#include <algorithm>
#include <cstdio>

using namespace std;

int a, b, n;

// #define getchar_unlocked() getchar()
inline int baca() {
	int temp = 0;
	char c;
	c = getchar_unlocked();
	while(c < '0' || c > '9') {
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9') {
		temp *= 10;
		temp += c - '0';
		c = getchar_unlocked();
	}
	return temp;
}

int main() {
	n = baca();
	for(int i = 1; i <= n; i++) {
		a = baca();
		b = baca();
		if(b & 1) {
			printf("1.000000\n");
		} else {
			printf("0.000000\n");
		}
	}
	return 0;
}
