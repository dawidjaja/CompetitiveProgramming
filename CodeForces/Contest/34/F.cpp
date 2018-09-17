#include <algorithm>
#include <cstdio>

using namespace std;


inline void init() {
	v[1].push_back(1);
	
	// v[2].push_back(1);
	v[2].push_back(2);
	v[2].push_back(5);
	v[2].push_back(6);

	// v[3].push_back(1);
	// v[3].push_back(2);
	v[3].push_back(3);
	// v[3].push_back(5);
	// v[3].push_back(6);
	v[3].push_back(7);
	v[3].push_back(9);
	v[3].push_back(10);
	v[3].push_back(11);
	
	v[4].push_back(4);
	v[4].push_back(8);
	v[4].push_back(12);
	v[4].push_back(16);
	v[4].push_back(15);
	v[4].push_back(14);
	v[4].push_back(13);
	on = (1 << 17) - 1;
}

// mask
// 16 15 14 13
// 12 11 10 9
// 8 7 6 5
// 4 3 2 1 

int f(int r, int c, int mask) {
	int tmp = 0;
	for(int i = 1; i <= c; i++) {
		if(tmp == 0) {
			for(int j = 0; j < v[i].size(); j++) {
				tmp &= mask & (1 << v[i][j]);
				ganti 
			}
		}
		if(tmp) {
			r_next = r;
			c_next = c++;
			if(c_next > 4) {
				c_next = 1;
				r_next++;
			}
			mask_next = mask;
			ret = min(f(r_next, c_next, ))
		}
	}
}




int main() {
	scanf("%d", &n);
	init();
	for(int i = 1; i <= 4; i++) {
		scanf("%d", &cost[i]);
	}
	for(int = 1; i <= 4; i++) {
		getchar();
		for(int j = 1; j <= n; j++) {
			c = getchar();
			list[j][i] = ((c == '*') ? 1 : 0);
		}
	}
	ans = f(1, 1, list[1][1]);
	return 0;
}