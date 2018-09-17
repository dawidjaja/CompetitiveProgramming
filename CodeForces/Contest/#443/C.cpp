#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int n, x, vis[15], list[15], tog[15], sor, atau, dan;
char tnd;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		getchar();
		tnd = getchar();
		scanf("%d", &x);
		// cout << tnd << x << endl;
		for(int i = 0; i < 10; i++) {
			int cek = x & (1 << i);
			// printf("%d --> %d\n", i, cek);
			if(tnd == '&') {
				if(cek == 0) {
					vis[i] = 1;
					list[i] = 0;
				}
			} else if(tnd == '|') {
				if(cek) {
					vis[i] = 1;
					list[i] = 1;
				}
			} else {
				if(cek) {
					if(vis[i] == 0) {
						tog[i]++;
					} else {
						list[i] ^= 1;
					}
				}
			}
		}
	}
	// for(int i = 0; i < 10; i++) {
	// 	printf("%d ", vis[i]);
	// }
	// printf("\n");
	// for(int i = 0; i < 10; i++) {
	// 	printf("%d ", list[i]);
	// }
	// printf("\n");
	// for(int i = 0; i < 10; i++) {
	// 	printf("%d ", tog[i]);
	// }
	// printf("\n");
	dan = (1 << 10) - 1;
	for(int i = 0; i < 10; i++) {
		if(vis[i]) {
			if(list[i] == 1) {
				atau ^= (1 << i);
			} else {
				dan ^= (1 << i);
			}
		} else {
			if(tog[i] & 1) {
				sor ^= (1 << i);
			}
		}
	}
	printf("3\n");
	printf("| %d\n", atau);
	printf("& %d\n", dan);
	printf("^ %d\n", sor);
	return 0;
}