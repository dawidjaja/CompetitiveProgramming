#include <algorithm>
#include <cstdio>
#include <cmath>

#define fs first
#define sc second
#define pii pair<int,int> 
#define ppi pair<pii,int>

using namespace std;

int tc, n, pVal, jVal, lptr, jptr, rptr, vis[1005], janList[1005], ctr;
pii list[1005];
ppi jan[1005], pet[1005];
char first[10];

pii findNext(int *x) {
	pii ret = {-1, -1};
	for (int i = *x; i < n; i++) {
		if (vis[pet[i].sc] == 0) {
			if (ret.fs == -1) {
				ret.fs = pet[i].sc;
			} else if(ret.sc == -1) {
				ret.sc = pet[i].sc;
				*x = i;
				return (ret);
			}
		}
	}
	return (ret);
}

bool jcmp(int a, int b) {
	if (list[a].fs > list[b].fs) {
		return true;
	} else if(list[a].fs < list[b].fs) {
		return false;
	} else {
		if(list[a].sc < list[b].sc) {
			return true;
		} else {
			return false;
		}
	}
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		scanf("%s", first);
		// printf("--%s\n", first);
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
			scanf("%d%d", &list[i].sc, &list[i].fs);
			jan[i] = {{-list[i].fs, list[i].sc}, i};
			pet[i] = {{-list[i].sc, list[i].fs}, i};
			janList[i] = 0;
		}
		sort(jan, jan + n);
		sort(pet, pet + n);
		// for (int i = 0; i < n; i++) {
		// 	printf("-- jan -- %d %d %d %d\n", i, jan[i].fs.fs, jan[i].fs.sc, jan[i].sc);
		// }
		// for (int i = 0; i < n; i++) {
		// 	printf("-- pet -- %d %d %d %d\n", i, pet[i].fs.fs, pet[i].fs.sc, pet[i].sc);
		// }
		for(int i = 0; i < ceil(1.0 * n / 2); i++) {
			janList[jan[i].sc] = 1;
		}
		pVal = 0;
		jVal = 0;
		lptr = 0;
		jptr = 0;
		ctr = 0;
		rptr = ceil(1.0 * n / 2);
		if (first[0] == 'P') {
			vis[pet[0].sc] = 1;
			pVal -= pet[0].fs.fs;
			ctr++;
			if (janList[pet[0].sc]) {
				janList[jan[rptr++].sc] = 1;
			}
			lptr++;
		}
		// printf("pVal = %d\n", pVal);
		// for (int i = 0; i < n; i++){
		// 	printf("janList = %d %d\n", i, janList[i]);
		// }
		// printf("rptr %d\n", rptr);
		while (ctr < n) {
			pii tmp = findNext(&lptr);
			// printf("-- tmp %d %d\n", tmp.fs, tmp.sc);
			if(tmp.fs == -1) {
				break;
			} else if (tmp.sc == -1) {
				jVal += list[tmp.fs].fs;
				break;
			} else if (!janList[tmp.fs] && !janList[tmp.sc]) {
				while (vis[jan[jptr].sc] != 0) {
					jptr++;
				}
				vis[jan[jptr].sc] = 1;
				jVal -= jan[jptr].fs.fs;
				jptr++;
				pVal += list[tmp.fs].sc;
				vis[tmp.fs] = 1;
			} else if (janList[tmp.fs] && janList[tmp.sc]) {
				vis[tmp.fs] = 1;
				vis[tmp.sc] = 1;
				while (vis[jan[rptr].sc] != 0) {
					rptr++;
				}
				janList[jan[rptr++].sc] = 1;
				if (!jcmp(tmp.fs, tmp.sc)) {
					swap(tmp.fs, tmp.sc);
				}
				jVal += list[tmp.fs].fs;
				pVal += list[tmp.sc].sc;
			} else {
				if (janList[tmp.sc] == 1) {
					swap(tmp.fs, tmp.sc);
				}
				vis[tmp.fs] = 1;
				vis[tmp.sc] = 1;
				jVal += list[tmp.fs].fs;
				pVal += list[tmp.sc].sc;
			}
			// printf("val %d %d\n", pVal, jVal);
			ctr += 2;
		}
		printf("%d %d\n", pVal, jVal);
	}
	return 0;
}