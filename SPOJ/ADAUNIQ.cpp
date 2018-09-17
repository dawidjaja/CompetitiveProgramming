#include <algorithm>
#include <cstdio>

using namespace std;
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		freq[list[i]]++;
		if(freq[list[i]] == 1) {
			for(int j = i; j <= n; j += (j & -j)) {
				bit[j]++;
			}
		}
		if(freq[list[i]] == 2) {
			auto it = seet[list[i]].begin();
			for(int j = *it; j <= n; j += (j & -j)) {
				bit[j]--;
			}
		}
		seet[list[i]].insert(i);
	}
	while(q--) {
		scanf("%d%d%d", &query, &a, &b);
		if(query == 1) {
			if(seet[list[a]].size() == 1) {
				auto it = seet[list[a]].begin();
				for(int j = *it; j <= n; j += (j & -j)) {
					bit[j]--;
				}
			}
			seet[list[a]].erase(a);
			if(seet[list[a]].size() == 1) {
				auto it = seet[list[a]].begin();
				for(int j = *it; j <= n; j += (j & -j)) {
					bit[j]++2;
				}
			}
			list[a] = b;
			seet[list[a]].insert(a);

		} else {

		}
	}
	return 0;
}