#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

queue <int> q;
vector <vector <int> > jawab;
int prima[20005], n, sblm[303], cap[303][303], vis[303], list[303], mf;
vector <int> v[505], rute, tls;

inline void sieve() {
	for(int i = 2; i <= 20000; i++) {
		prima[i] = 1;
	}
	for(int i = 2; i <= 20000; i++) {
		if(prima[i]) {
			for(int j = i; j*i <= 20000; j++) {
				prima[i*j] = 0;
			}
		}
	}
}

inline void bikin(int a, int b, int c) {
//	printf("-- %d %d --> %d --\n", a, b, c);
	v[a].push_back(b);
	v[b].push_back(a);
	cap[a][b] = c;
	cap[b][a] = 0;
}

inline void jalan() {
	rute.clear();
	rute.push_back(n+1);
	while(sblm[rute.back()] != -2) {
//		printf("--- %d --> %d ---\n", rute.back(), sblm[rute.back()]);
		rute.push_back(sblm[rute.back()]);
	}
	return;
}

inline bool SP() {
	while(q.size()) {
		q.pop();
	}
	rute.clear();
	for(int i = 0; i <= n + 1; i++) {
		sblm[i] = -1;
	}
	sblm[0] = -2;
	q.push(0);
	while(q.size()) {
		int skrg = q.front();
//		printf("-- %d --\n", skrg);
		q.pop();
		for(int i = 0; i < v[skrg].size(); i++) {
			if(sblm[v[skrg][i]] == -1 && cap[skrg][v[skrg][i]] > 0) {
				sblm[v[skrg][i]] = skrg;
				if(v[skrg][i] == n+1) {
					jalan();
					break;
				}
				q.push(v[skrg][i]);
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

inline bool arah(int a, int b) {
	if(list[a]%2) {
		if(cap[a][b] == 0) {
			return true;
		}
		return false;
	} else {
		if(cap[b][a] == 0) {
			return true;
		}
		return false;
	}
}

void tulis(int skrg, int sblm) {
//	printf("tulis %d %d\n", skrg, sblm);
	if(vis[skrg] == 1) {
		return;
	}
	tls.push_back(skrg);
	vis[skrg] = 1;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(arah(skrg, v[skrg][i]) && v[skrg][i] != sblm && v[skrg][i] != n+1 && v[skrg][i] != 0) {
			tulis(v[skrg][i], skrg);
		}
	}
}

int main() {
	scanf("%d", &n); 
	sieve();
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		if(list[i]%2) {
			bikin(0, i, 2);
		} else {
			bikin(i, n + 1, 2);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(list[i]%2) {
			for(int j = 1; j <= n ; j++) {
				if(list[j]%2 == 0) {
					if(prima[list[i] + list[j]]) {
						bikin(i, j, 1);
					}
				}
			}
		}
	}
	mf = 0;
	while(SP()) {
		int blkg = rute.back();
		rute.pop_back();
		while(rute.size()) {
			cap[blkg][rute.back()]--;
			cap[rute.back()][blkg]++;
			blkg = rute.back();
			rute.pop_back();
		}
		mf++;
//		printf("%d --\n", mf);
	}
	if(mf == n) {
		for(int i = 0; i < v[0].size(); i++) {
			if(vis[v[0][i]] == 0) {
				tls.clear();
				tulis(v[0][i], -1);
				jawab.push_back(tls);
			}
		}
		printf("%d\n", jawab.size());
		for(int i = 0; i < jawab.size(); i++) {
			printf("%d", jawab[i].size());
			for(int j = 0; j < jawab[i].size(); j++) {
				printf(" %d", jawab[i][j]);
			}
			printf("\n");
		}
		
	} else {
		printf("0\n");
	}
	return 0;
}
