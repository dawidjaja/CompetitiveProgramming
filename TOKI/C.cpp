#include <algorithm>
#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

int ctr, prima[100005], ke[100005], n, k, porer[100005], a, ttl, list[100005], por[100005], c;
set <int> setet, s;

inline void sieve() {
	ctr = 1;
	for(int i = 2; i <= 100000; i++) {
		// printf("%d\n", i);
		if(prima[i] == 0) {
			prima[i] = 1;
			// prim[i] = ctr;
			ke[ctr++] = i;
			if(i < sqrt(100000)) {
				for(int j = i; j * i <= 100000; j++) {
					prima[i * j] = 1;
				}
			}
		}
	}
}

int main() {
	sieve();
	scanf("%d", &n);
	// printf("asdf");
	for(int j = 1; j <= n; j++) {
		scanf("%d", &k);
		// printf("%d\n", j);

		if(setet.size()) {
			for(auto it = setet.begin(); it != setet.end(); it++) {
				por[*it] = 0;
			}
			setet.clear();
		}

		for(int i = 1; i <= k; i++) {
			c = 1;
			scanf("%d", &a);
			if(s.size()) {
				for(auto it = s.begin(); it != s.end(); it++) {
					porer[*it] = 0;
				}
				s.clear();
			}

			while(a > 1) {
				// printf("-- %d %d \n", a, ke[c]);
				if((a % ke[c]) != 0) {
					// printf("aaaa");
					if(porer[c] != 0) {
						setet.insert(c);
						s.insert(c);
						por[c] = i == 1 ? porer[c] : max(por[c], porer[c]);
					}
					c++;
				} else {
					// printf("bbbb");
					a /= ke[c];
					porer[c]++;
				}
			}
			// printf("asdf\n");
			if(porer[c] != 0) {
				setet.insert(c);
				s.insert(c);
				por[c] = i == 1 ? porer[c] : max(por[c], porer[c]);
			}
		}
		if(setet.size()) {
			for(auto it = setet.begin(); it != setet.end(); it++) {
				// printf("----- %d %d ----\n", *it, por[*it]);
				list[*it] = j == 1 ? por[*it] : min(list[*it], por[*it]);
			}
		}
	}
	// printf("asdf");
	ttl = 0;
	for(int i = 1; i < ctr; i++) {
		if(list[i] > 0) {
			ttl++;
		}
	}
	printf("%d\n", ttl);
	for(int i = 1; i < ctr; i++) {
		if(list[i] > 0) {
			printf("%d %d\n", ke[i], list[i]);
		}
	}
	return 0;
}