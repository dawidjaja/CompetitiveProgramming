#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cassert>
#include <set>

#define INF 1e9
#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long>

using namespace std;

int buka, tutup, pre[1000005], hrg[1000005], list[1000005], s, e, n, m, a, b, ctr;
long long scc[1000005], hsl[1000005];
bool on[1000005];
vector <int> v[1000005], urut, be[1000005];
queue <int> q;
set <int> seset[1000005];

void dfs(int skrg) {
	pre[skrg] = buka++;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(pre[v[skrg][i]] == 0) {
			dfs(v[skrg][i]);
		}
	}
//	pos[skrg] = tutup++;
	urut.push_back(skrg);
}

void balik(int skrg, int x) {
	list[skrg] = x;
	scc[x] += hrg[skrg];
	for(int i = 0; i < be[skrg].size(); i++) {
		if(list[be[skrg][i]] == 0) {
			balik(be[skrg][i], x);
		} else if(list[be[skrg][i]] != x){
			seset[list[be[skrg][i]]].insert(x);
		}
	}
}

inline void SPFA() {
	for(int i = 1; i <= n; i++) {
		hsl[i] = -INF;
	}
	q.push(list[s]);
	hsl[list[s]] = scc[list[s]];
	on[s] = 1;
	while(q.size()){
		int skrg = q.front();
//		printf("--- %d %d---\n", skrg, jrk);
		q.pop();
		on[skrg] = 0;
		long long jrk = hsl[skrg];
		for(set<int> :: iterator it = seset[skrg].begin(); it != seset[skrg].end(); it++) {
			int temp = *it;
			if(jrk + scc[temp] > hsl[temp]) {
				hsl[temp] = jrk + scc[temp];
				if(on[temp] == 0) {
					on[temp] = 1;
					q.push(temp);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &e);
	buka = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &hrg[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		be[b].push_back(a);
	}
//	for(int i = 1; i <= n; i++) {
//		if(pre[i] == 0) {
//			dfs(i);
//		}
//	}
	for(int i = 1; i <= n; i++) {
		if(pre[i] == 0) {
			dfs(i);
		}
	}
	ctr = 1;
	while(urut.size()) {
		int temp = urut[urut.size()-1];
		if(list[temp] == 0) {
			balik(temp, ctr++);
		}
		urut.pop_back();
	}
//	for(int i = 1; i < ctr; i++) {
//		printf("%lld --> \n", i);
//		for(set <int> :: iterator it = seset[i].begin(); it != seset[i].end(); it++) {
//			printf("------ %lld\n", *it);
//		}
//	}
	if(list[s] == list[e]) {
		printf("%lld\n", scc[list[s]]);
		return 0;
	}
	SPFA();
	printf("%lld\n", hsl[list[e]]);
	return 0;
}
