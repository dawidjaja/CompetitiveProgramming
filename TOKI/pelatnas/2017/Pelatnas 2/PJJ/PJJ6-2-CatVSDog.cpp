#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int blkg, n, cap[505][505], sblm[505], tc, c, d, a[505], b[505], ans;
vector <int> v[505], rute;
queue <int> q;
char tipe[505], dummy;

inline void init() {
	blkg = n+1;
	for(int i = 0; i <= blkg; i++) {
		v[i].clear();
	}
}

inline void bikin(int a, int b) {
	cap[a][b] = 1;
	cap[b][a] = 0;
	v[a].push_back(b);
	v[b].push_back(a);
}

inline void jalan() {
	rute.push_back(blkg);
	while(sblm[rute.back()] != -2) {
		rute.push_back(sblm[rute.back()]);
	}
}

inline bool SP() {
	while(q.size()) {
		q.pop();
	}
	rute.clear();
	sblm[0] = -2;
	for(int i = 1; i <= blkg; i++) {
		sblm[i] = -1;
	}
	q.push(0);
	while(q.size()) {
		int skrg = q.front();
		q.pop();
		for(int i = 0; i < v[skrg].size(); i++) {
			if(cap[skrg][v[skrg][i]] > 0 && sblm[v[skrg][i]] == -1) {
				sblm[v[skrg][i]] = skrg;
				if(v[skrg][i] == blkg) {
					jalan();
					return true;
				}
				q.push(v[skrg][i]);
			}
		}
	}
	return false;
}

int main() {
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &c, &d, &n);
		init();
		for(int i = 1; i <= n; i++) {
			getchar();
			scanf("%c%d%c%c%d", &tipe[i], &a[i], &dummy, &dummy, &b[i]);
			if(tipe[i] == 'C') {
				bikin(0, i);
			} else {
				bikin(i, blkg);
			}
//			printf("%c %d %d\n", tipe[i], a[i], b[i]);
		}
		for(int i = 1; i <= n; i++) {
			if(tipe[i] == 'C') {
				for(int j = 1; j <= n; j++) {
					if(tipe[j] == 'D') {
						if(a[i] == b[j] || b[i] == a[j]) {
							bikin(i,j);
						}
					}
				}
			}
		}
		ans = n;
		while(SP()) {
			int temp = rute.back();
			rute.pop_back();
			while(rute.size()) {
				cap[temp][rute.back()]--;
				cap[rute.back()][temp]++;
				temp = rute.back();
				rute.pop_back();
			}
			ans--;
		}
		printf("%d\n", ans);
	}
	return 0;
}
