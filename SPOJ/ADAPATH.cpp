#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	scanf("%d", &tc);
	for(int _ = 1; _ <= tc; ++_) {
		scanf("%d", &n);
		for(int i = 1; i <= 9; ++i) {
			freq[i] = 0;
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%d", &list[i][j]);
				freq[list[i][j]]++;
			}
		}
		cek = 1;
		ttl = 0;
		for(int i = 1; i <= 9; ++i) {
			if(freq[i + 1] > freq[i]) {
				cek = 0;
				break;
			} else {
				msk[i] = freq[i] - freq[i + 1];
				ttl += msk[i];
			}
		}
		if(cek == 0) {
			printf("NO\n");
			continue;
		} else {
			tmp = n*n;
			st = tmp*2;
			en = st + 1;
			for(int i = 1; i <= 9; i++) {
				bikin()
			}
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					
				}
			}
			
		}
	}
	return 0;
}