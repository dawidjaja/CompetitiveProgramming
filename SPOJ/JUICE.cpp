#include <algorithm>
#include <cstdio>

using namespace std;

inline int baca() {
	int temp = 0, kali = 1;
	char c;
	c = getchar_unlocked();
	while((c < '0' || c > '9') && c != '-') {
		c = getchar_unlocked();
	}
	while((c >= '0' && c <= '9') || c == '-') {
		if(c == '-') {
			kali = -1;
			c = getchar_unlocked();
			continue;
		}
		temp = (temp << 3) + (temp << 1);
		temp += c - '0';
		c = getchar_unlocked();
	}
	temp *= kali;
	return temp;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &list[i].fs, &list[i].sc);
		}
		
	}
	return 0;
}