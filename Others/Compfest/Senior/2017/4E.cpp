#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ppi pair<pii, int>
using namespace std;

int t, n;
ppi list[100005];
vector <pii> ans, v[10];

pii ganti(pii a, int k) {
	if(k == 1) {
		return a;
	} else if(k == 2) {
		swap(a.fs, a.sc);
		a.sc *= -1;
		return a;
	} else if(k == 3) {
		a.fs *= -1;
		a.sc *= -1;
		return a;
	} else if(k == 4) {
		a.sc *= -1;
		swap(a.fs, a.sc);
		return a;
	}
}

pii tgh(pii a, pii b, int k) {
	if(k == 1) {
		return mp(b.fs, a.sc);
	} else if(k == 2) {
		return mp(a.fs, b.sc);
	} else if(k == 3) {
		return mp(b.fs, a.sc);
	} else if(k == 4) {
		return mp(a.fs, b.sc);
	}
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &list[i].fs.fs, &list[i].fs.sc);
			list[i].sc = 0;
		}
		for(int k = 1; k <= 4; k++) {
			printf("---- %d ----\n", k);
			v[k].clear();
			sort(list + 1, list + 1 + n);
			pii last;
			if(list[1].sc == 0) {
				v[k].push_back(list[1].fs);
				list[1].sc = k;
				last = v[k].back();
			} else {
				last = mp(-1000001000, -1000001000);
			}
			for(int i = 2; i <= n; i++) {
				if(list[i].fs.sc >= last.sc) {
					last = list[i].fs;
					if(list[i].sc == 0) {
						v[k].push_back(list[i].fs);
						list[i].sc = k;
					}
				}
			}
			for(int i = 1; i <= n; i++) {
				list[i].fs.sc = -list[i].fs.sc;
				swap(list[i].fs.fs, list[i].fs.sc);
			}
		}
		for(int k = 1; k <= 4; k++) {
			for(int i = 0; i < v[k].size(); i++) {
				pii temp = ganti(v[k][i], k);
				printf("-- %d %d -- %d\n", temp.fs, temp.sc, k);
			}
		}
		ans.clear();
		for(int k = 1; k <= 4; k++) {
			// printf("%d asdf\n", k);
			for(int i = 0; i < v[k].size(); i++) {
				pii temp = ganti(v[k][i], k);
				if(ans.size() && (temp.fs != ans.back().fs && temp.sc != ans.back().sc)) {
					ans.push_back(tgh(temp, ans.back(), k));
					ans.push_back(temp);
				}
			}
		}
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++) {
			printf("-- %d %d --\n", ans[i].fs, ans[i].sc);
		}
		long long hsl = 0;
		for(int i = 0; i < ans.size() - 1; i++) {
			pll a, b;
			a = ans[i];
			b = ans[i + 1];
			hsl += a.fs * b.sc - a.sc * b.fs;
		}
		printf("%lld\n", hsl);
	}
	return 0;
}