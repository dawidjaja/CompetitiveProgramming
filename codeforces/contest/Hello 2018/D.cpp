#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

int n, t, l, jmlh, cc, r;
ppi list[200005];

bool bisa(int x) {
	int ttl = 0;
	int ctr = 0;
	for(int i = 1; i <= n; i++) {
		if(list[i].fs.sc >= x) {
			if(ttl + list[i].fs.fs <= t) {
				ttl += list[i].fs.fs;
				ctr++;
			}
		}
	}
	// printf("-- %d %d--\n", x, ctr);
	return (ctr >= x);
}

void tulis(int x) {
	int ttl = 0;
	int ctr = 0;
	for(int i = 1; i <= n; i++) {
		if(list[i].fs.sc >= x) {
			if(ttl + list[i].fs.fs <= t) {
				ttl += list[i].fs.fs;
				ctr++;
				if(ctr == 1) {
					printf("%d", list[i].sc);
				} else if(ctr <= x) {
					// printf("-%d-", ctr);
					printf(" %d", list[i].sc);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &t);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &list[i].fs.sc, &list[i].fs.fs);
		list[i].sc = i;
	}
	l = 0;
	r = n;
	sort(list + 1, list + 1 + n);
	while(l < r) {
		// printf("---- lr %d %d\n", l, r);
		int mid = ((l + r) >> 1) + 1;
		// bool tmp = bisa(mid);
		if(bisa(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", l);
	printf("%d\n", l);
	tulis(l);
	printf("\n");
	return 0;
}