#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int> 
#define ppi pair<pii, int>

using namespace std;

int blkg, sblm[1005], cap[1005][1005], n, m, l, tc, f, t, h[505], a, b, vis[1005], ans, cost[505][505], tnd[505];
vector <int> v[1005];
vector <int> jln[505];
ppi sem[100005];
queue <int> q;
queue <pii> pq;
//#define getchar_unlocked() getchar()
inline int baca() {
	int temp = 0;
	char c;
	c = getchar_unlocked();
	while(c < '0' || c > '9') {
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9') {
		temp *= 10;
		temp += c - '0';
		c = getchar_unlocked();
	}
	return temp;
}
inline void jalan() {
	int temp = blkg;
	while(sblm[temp] != -1) {
//		printf("qwer");
		cap[sblm[temp]][temp]--;
		cap[temp][sblm[temp]]++;
		temp = sblm[temp];
//		printf("%d --> ", temp);
	}
//	printf("\n");
}

bool SP(){
	for(int i = 1; i <= blkg; i++) {
		sblm[i] = -2;
	}
	while(q.size()) {
		q.pop();
	}
	q.push(0);
	sblm[0] = -1;
	while(q.size()) {
		int skrg;
		skrg = q.front();
		q.pop();
		for(int i = 0; i < v[skrg].size(); i++) {
			if(sblm[v[skrg][i]] == -2 && cap[skrg][v[skrg][i]] > 0) {
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
	tc = baca();
	while(tc--) {
		n = baca();
		m = baca();
		f = baca();
		t = baca();
		blkg = 2*n + 1;
		for(int i = 0; i <= n; i++) {
			jln[i].clear();
			for(int j = 0; j <= n; j++) {
				cost[i][j] = -1;
			}
			tnd[i] = -1;
		}
		for(int i = 0; i <= blkg; i++) {
			v[i].clear();
			for(int j = 0; j <= blkg; j++) {
				cap[i][j] = 0;
			}
		}
		
		for(int i = 1; i <= f; i++) {
			h[i] = baca();
			cap[0][h[i]]++;
			if(cap[0][h[i]] == 1) {
				v[0].push_back(h[i]);
			}
			tnd[h[i]] = 1;
		}
		
		for(int i = 1; i <= m; i++) {
			a = baca();
			b = baca();
			l = baca();
			if(a == b) {
				continue;
			}
			if(cost[a][b] == -1) {
				jln[a].push_back(b);
				jln[b].push_back(a);
				cost[a][b] = l;
				cost[b][a] = l;
			} else {
				cost[b][a] = min(cost[b][a], l);
				cost[a][b] = min(cost[a][b], l);
			}
		}
		
		for(int i = 1; i <= n; i++) {
			v[i + n].push_back(blkg);
			cap[i + n][blkg] = 1;
			cap[blkg][i + n] = 0;
		}
		for(int i = 1; i <= n; i++) {
			if(tnd[i] == -1) {
				continue;
			}
			for(int j = 1; j <= n; j++) {
				vis[j] = 0;
			}
			while(pq.size()) {
				pq.pop();
			}
			pq.push(mp(0, i));
			while(pq.size()) {
				int jrk, skrg;
				jrk = -pq.front().fs;
				skrg = pq.front().sc;
				pq.pop();
				if(jrk > t || vis[skrg] != 0) {
					continue;
				}
				
				if(cap[i][skrg + n] == 0) {
					v[i].push_back(skrg + n);
					v[skrg + n].push_back(i);
					cap[i][skrg + n] = 1;
					cap[skrg + n][i] = 0;
				}
				
				vis[skrg] = 1;
				for(int j = 0; j < jln[skrg].size(); j++) {
					if(vis[jln[skrg][j]] == 0 && (jrk + cost[skrg][jln[skrg][j]] <= t)) {
						pq.push(mp(-(jrk + cost[skrg][jln[skrg][j]]), jln[skrg][j]));
					}
				}
			}
		}
//		for(int i = 1; i <= n; i++) {
//			printf("%d --> ", i);
//			for(int j = 0; j < v[i].size(); j++) {
//				printf("%d ", v[i][j]);
//			}
//			printf("\n");
//		}
		ans = 0;
		while(SP()) {
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
