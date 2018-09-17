#include <algorithm>
#include <cstdio>

#define INF 10000005

using namespace std;

int ada[10000005], pri[10000005], maks, list[100005], n, x, ans, cek[100005];

//int cari(int x) {
//	if(pri[x] != INF) {
//		return pri[x];
//	}
//	pri[x] = cari(x-1) + 1;
//	return pri[x];
//}
//
//void update(int x) {
//	for(int i = 1; i*x <= maks; i++) {
//		pri[i*x] = 0;
//	}
//}

int main() {
	scanf("%d", &n);
	maks = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
//		maks = max(maks, list[i]);
//		ada[list[i]]++;
	}
	for(int i = 1; i <= n; i++) {
		if(cek[i] == 0) {
			cek[i] = 1;
			int temp = 0;
			int kcl = INF;
			for(int j = 1; j <= n; j++) {
				if(j != i) {
					if(min(list[i] % list[j], list[j] % list[i]) < kcl) {
						temp = j;
						kcl = min(list[i] % list[j], list[j] % list[i]);
					}
				}
			}
			cek[temp] = 1;
			ans += kcl;
		}
	}
//	for(int i = 1; i <= maks; i++) {
//		pri[i] = INF;
//	}
//	sort(list+1, list+1+n);
//	for(int i = 1; i <= n; i++) {
//		if(list[i] != list[i-1]) {
//			if(ada[list[i]] == 1) {
//				ans += cari(list[i]);
//			}
//			update(list[i]);
//		}
//		printf("%d\n", ans);
//	}
	printf("%d\n", ans);
	return 0;
}
