#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

char baris[105][105];
int t, r, c, ans;

#define getchar_unlocked() getchar()
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
	// scanf("%d", &t);
	t = baca();
	for(int _ = 1; _ <= t; ++_) {
		// scanf("%d%d", &r, &c);
		r = baca();
		c = baca();
		ans = 0;
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				ps[i][j] = 0;
			}
		}
		for(int i = 0; i < r; ++i) {
			// printf("-- %c --\n", baris[c-1]);
			scanf("%s", baris[i]);
			for(int j = 0; j < c; ++j) {
				
				if(baris[j] == 'T') {
					ans--;
				} else if(baris[j] == 'B') {
					ans++;
				}
			}
		}
		printf("Case %d: %d\n", _,ans);
	}
	return 0;
}