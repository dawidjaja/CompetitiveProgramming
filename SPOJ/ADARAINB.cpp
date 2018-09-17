#include <algorithm>
#include <cstdio>

//#define getchar_unlocked() getchar()

using namespace std;

int n, m, l, a, b, c, d, list[5005][5005], ps[5005][5005];

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
//	scanf("%d%d%d", &n, &m, &l);
	n = baca();
	m = baca();
	l = baca();
	for(int i = 1; i <= n; i++) {
//		scanf("%d%d%d%d", &a, &b, &c, &d);
		a = baca();
		b = baca();
		c = baca();
		d = baca();
		list[a][b]++;
		list[a][d+1]--;
		list[c+1][b]--;
		list[c+1][d+1]++;
//		printf("--\n");
//		for(int i = 1; i <= l; i++) {
//			for(int j = 1; j <= l; j++) {
//				printf("%d ", list[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
	} 
	for(int i = 1; i <= l; i++) {
		for(int j = 1; j <= l; j++) {
			ps[i][j] = ps[i][j-1] + ps[i-1][j] + list[i][j] - ps[i-1][j-1];
		}
	}

//	printf("--\n");
//	for(int i = 1; i <= l; i++) {
//		for(int j = 1; j <= l; j++) {
//			printf("%d ", ps[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	for(int j = 1; j <= l; j++) {
//		for(int i = 1; i <= l; i++) {
//			ps[i][j] = ps[i-1][j] + ps[i][j];
//		}
//	}



//	printf("--\n");
//	for(int i = 1; i <= l; i++) {
//		for(int j = 1; j <= l; j++) {
//			printf("%d ", ps[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	while(m--) {
//		scanf("%d%d", &a, &b);
		a = baca();
		b = baca();
		printf("%d\n", ps[a][b]);
	}
	return 0;
}
