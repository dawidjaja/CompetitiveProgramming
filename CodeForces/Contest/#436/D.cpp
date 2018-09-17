#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

int n, list[200005], ctr[200005], p , ccc;
vector <pii> klr;
vector <int> msk,v[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		v[list[i]].push_back(i);
		ctr[list[i]]++;
	}
	for(int i = 1; i <= n; i++) {
		if(v[i].size() == 0) {
			msk.push_back(i);
		}
		if(v[i].size() >= 2) {
			for(int j = 0; j < v[i].size(); j++) {
				klr.push_back(mp(v[i][j], i));
			}
		}
	}
	sort(klr.begin(), klr.end());
	// for(int i = 0; i < msk.size(); i++) {
	// 	printf("%d ", msk[i]);
	// }
	// printf("\n");
	// for(int i = 0; i < klr.size(); i++) {
	// 	printf("-- %d %d --\n", klr[i].fs, klr[i].sc);
	// }

	p = 0;
	ccc = 0;
	for(int i = 0; i < msk.size(); i++) {
		if(p >= klr.size()) {
			break;
		}
		while(klr[p].sc < msk[i]) {
			p++;
			if(p >= klr.size()) {
				break;
			}
		}
		if(p >= klr.size()) {
			break;
		}
		if(ctr[klr[p].sc] >= 2) {
			ctr[klr[p].sc]--;
			list[klr[p].fs] = msk[i];
			// printf("--- %d --> %d - %d -- %d ---\n", p, klr[p].fs, klr[p].sc, msk[i]);
			p++;
			ccc++;
		}
	}
	// printf("-- %d --\n", ccc);
	p = klr.size() - 1;
	// printf("asdf");
	for(int i = msk.size() - 1; i >= ccc; i--) {
		int tes = 1;
		while(tes) {
			tes = 0;
			while(ctr[klr[p].sc] == 1 || (v[klr[p].sc][0] == klr[p].fs &&  klr[p].sc < msk[i])) {
				p--;
				tes++;
				// if(p < 0) {
				// 	break;
				// }
			}
			// if(p < 0) {
			// 	break;
			// }
			// printf("%d -> %d %d %d\n", p, klr[p].fs, klr[p].sc, v[klr[p].sc][v[klr[p].sc].size() - 1]);
			if(v[klr[p].sc][v[klr[p].sc].size() - 1] == klr[p].fs && klr[p].sc > msk[i]) {
				p--;
				tes++;
				// if(p < 0) {
				// 	break;
				// }
			}
		}
		list[klr[p].fs] = msk[i];
		p--;
	}
	printf("%d\n", msk.size());
	for(int i = 1; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("%d\n", list[n]);
	// scanf("%d", &n);
	return 0;
}