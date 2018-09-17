#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <assert.h>

#define fs first
#define sc second
#define mp make_pair

using namespace std;

queue <pair<int,int> > qq;
vector <int> v[10005], rute, ptg, ga;
int sblm[10005], blkg, dpn, n, m, l, aa, bb, a[15], vis[10005], tnd[105][105], turn, with[10005];
queue <int> q;
map <int,int> cap[10005], cek[10005];

void bikin(int a, int b) {
//	printf("-- %d %d --\n", a, b);
	v[a].push_back(b);
	v[b].push_back(a);
	cap[a][b] = 1;
	cap[b][a] = 0;
}

inline void jalan() {
	rute.push_back(blkg);
	while(sblm[rute.back()] != 0){
		rute.push_back(sblm[rute.back()]);
	}
	return;
}

inline void tulis(int skrg) {
	for(int i = 0; i < v[skrg].size(); i++) {
		if(cap[skrg][v[skrg][i]] == 0 && (v[skrg][i] <= n*m)) {
			printf("%d %d\n", skrg, v[skrg][i]);
			return;
		}
	}
}

inline bool SP() {
	for(int i = 1; i <= blkg; i++) {
		sblm[i] = -1;
	}
	sblm[dpn] = 0;
	rute.clear();
	while(q.size()) {
		q.pop();
	}
	q.push(dpn);
	while(q.size()) {
		int temp = q.front();
		q.pop();
		for(int i = 0; i < v[temp].size(); i++) {
			if(cap[temp][v[temp][i]] > 0 && sblm[v[temp][i]] == -1) {
				sblm[v[temp][i]] = temp;
				if(v[temp][i] == blkg) {
					jalan();
					break;
				}
				q.push(v[temp][i]);
			}
		}
		if(rute.size()) {
			break;
		}
	}
	if(rute.size()) {
		return true;
	}
	return false;
}

inline int msk(int i) {
	return tnd[(i-1)/m][(i-1)%m];
}

bool match(int skrg) {
//	printf("-- %d --\n", skrg);
	for(int i = 0; i < v[skrg].size(); i++) {
		if(vis[v[skrg][i]] != turn) {
			vis[v[skrg][i]] = turn;
			if(with[v[skrg][i]] == -1 || match(with[v[skrg][i]])) {
				with[v[skrg][i]] = skrg;
//				printf("--- %d ---\n", v[skrg][i]);
				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	tnd[0][0] = 1;
	for(int j = 1; j < m; j++) {
		tnd[0][j] = 1-tnd[0][j-1];
	}
	for(int i = 1; i < n; i++) {
		tnd[i][0] = 1-tnd[i-1][0];
		for(int j = 1; j < m; j++) {
			tnd[i][j] = 1 - tnd[i][j-1];
		}
	}
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < m; j++) {
//			printf("%d ", tnd[i][j]);
//		}
//		printf("\n");
//	}
//	for(int i = 1; i <= n*m; i++) {
//		printf("--- %d --> %d ---\n", i, msk(i));
//	}
	scanf("%d", &l);
	for(int i = 1; i <= l; i++) {
		scanf("%d%d", &aa, &bb);
		cek[aa][bb] = 1;
		cek[bb][aa] = 1;
	}
	a[1] = m;
	a[2] = -m;
	a[3] = 1;
	a[4] = -1;
	if(m%2) {
		for(int i = 1; i <= n*m; i+=2) {
			for(int j = 1; j <= 4; j++) {
				if(0 < (i + a[j]) && i + a[j] <= n*m && !cek[i].count(i + a[j])) {
					if(j == 3) {
						if(i % m != 0) {
							bikin(i, i + a[j]);
						}
					} else if(j == 4) {
						if(i % m != 1) {
							bikin(i, i + a[j]);
						}
					} else bikin(i, i + a[j]);
				}
			}
		}
	} else {
		for(int i = 1; i <= n*m; i++) {
			if(msk(i)) {
				for(int j = 1; j <= 4; j++) {
					if(0 < (i + a[j]) && i + a[j] <= n*m && !cek[i].count(i + a[j])) {
						if(j == 3) {
							if(i % m != 0) {
								bikin(i, i + a[j]);
							}
						} else if(j == 4) {
							if(i % m != 1) {
								bikin(i, i + a[j]);
							}
						} else bikin(i, i + a[j]);
					}
				}
			}
		}
	}
//	dpn = n*m + 1;
//	blkg = n*m + 2;
	for(int i = 1; i <= n*m; i++) {
		if(msk(i)) {
			ptg.push_back(i);
//			bikin(dpn, i);
		} else {
			ga.push_back(i);
//			bikin(i, blkg);
		}
	}
	
//	while(SP()) {
//		int temp;
//		temp = rute.back();
//		rute.pop_back();
//		while(rute.size()) {
//			cap[temp][rute.back()]--;
//			cap[rute.back()][temp]++;
//			temp = rute.back();
//			rute.pop_back();
//		}
//		printf("asdf\n");
//	}
	memset(vis, -1, sizeof(vis));
	memset(with, -1, sizeof(with));
	int temp = 0;
	for(int i = 0; i < ptg.size(); i++) {
		turn = i;
		if(match(ptg[i])) {
			temp++;
		}
	}
	assert(n*m/2 == temp);
	for(int i = 0; i < ga.size(); i++) {
		printf("%d %d\n", ga[i], with[ga[i]]);
	}
	return 0;
}
