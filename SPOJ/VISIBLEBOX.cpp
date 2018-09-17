#include <algorithm>
#include <cstdio>

using namespace std;

int list[100005], n, t, ans, l;

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
//	scanf("%d", &t);
	t = baca();
	for(int _ = 1; _ <= t; _++) {
		n = baca();
		for(int i = 1; i <= n; i++) {
			list[i] = baca();
		}
		ans = n;
		l = n;
		sort(list + 1, list + 1 + n);
		for(int i = n; i >= 1; i--) {
			while(l >= 1 && list[l] > list[i]/2) {
				l--;
			}
			if(l <= 0) {
				break;
			}
			l--;
			ans--;
		}
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
