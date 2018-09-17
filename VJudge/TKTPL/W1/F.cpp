#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, k, ans, ctr;
pii list[200005];
map <int, int> mapa;
priority_queue <pii> pqb;

const int INF = 1000000000;

bool cmp(pii a, pii b) {
	pii c, d;
	c = {a.sc, a.fs};
	d = {b.sc, b.fs};
	return c < d;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &list[i].fs, &list[i].sc);
	}
	sort(list + 1, list + 1 + n, cmp);
	mapa[0] = k;
	mapa[INF + 1] = 1;
	// for(int i = 1; i <= k; ++i) {
	// 	pqb.push({-list[i].fs, -list[i].sc});
	// }
	// ctr = k + 1;
	// while(pqb.size()) {
		// pii tmp = pqb.top();
		// pqb.pop();
		// if(ctr <= n) {
		// 	pqb.push({-list[ctr].fs, -list[ctr].sc});
		// 	ctr++;
		// }
	for(int i = 1; i <= n; i++) {
		pii tmp = list[i];
		auto it = mapa.lower_bound(tmp.fs);
		if(it != mapa.begin()) {
			it--;
			mapa[it->fs]--;
			// printf("-- %d %d %d--\n", it->fs, it->sc, tmp.sc);
			ans++;
			if(mapa[it->fs] == 0) {
				mapa.erase(it);
			}
			mapa[tmp.sc]++;
		}
	}
	printf("%d\n", ans);
	return 0;
}