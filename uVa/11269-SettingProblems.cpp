#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

int n, a, b, ans;
pii list[205];

bool cmpa(pii a, pii b) {
	if(a.fs < b.fs) {
		return true;
	} else if(a.fs == b.fs) {
		return a.sc < b.sc;
	}
	return false;
}
bool cmpb(pii a, pii b) {
	if(a.sc < b.sc) {
		return true;
	} else if(a.sc == b.sc) {
		return a.fs < b.fs;
	}
	return false;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &list[i].fs);
		}
		for(int i = 0; i < n; i++) {
			scanf("%d", &list[i].sc);
		}
		sort(list, list + n, cmpa);
		// for(int i = 0; i < n; i++) {
		// 	printf("%d ", list[i].fs);
		// }
		// printf("\n");
		// for(int i = 0; i < n; i++) {
		// 	printf("%d ", list[i].sc);
		// }
		// printf("\n");
		a = 0;
		b = 0;
		for(int i = 0; i <= n; i++) {
			if(i != 0) {
				b = max(a, b) + list[i-1].sc;
			}
			if(i != n) {
				a += list[i].fs;
			}
			// printf("%d %d\n", a, b);
		}
		ans = b;
		a = b = 0;
		sort(list, list + n, cmpb);
		for(int i = 0; i <= n; i++) {
			if(i != 0) {
				b = max(a, b) + list[i-1].fs;
			}
			if(i != n) {
				a += list[i].sc;
			}
			// printf("%d %d\n", a, b);
		}
		// printf("%d %d\n", b, ans);
		ans = min(ans, b);
		printf("%d\n", ans);
	}
	return 0;
}