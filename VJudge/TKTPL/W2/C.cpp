#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

const INF = INT_MAX;

bool SPFA() {
	queue <int> q;
	q.push_back(ss);
	for(int i = 0; i <= t; i++) {
		kcl[i] = INF;
		ada[i] = 0;
		asal[i] = -1;
	}
	ada[ss] = 1;
	kcl[ss] = 0;
	while(q.size()) {
		int skrg = q.front();
		ada[skrg] = 0;
		q.pop();
		for(int i = 0; i < v[skrg].size(); i++) {
			int smpn = kcl[v[skrg][i]];
			kcl[v[skrg][i]] = min(kcl[v[skrg][i]], kcl[skrg] + list[v[skrg][i]]);
			if(smpn != kcl) {
				if(!ada[v[skrg][i]]) {
					q.push(v[skrg][i])
				}
				asal[v[skrg][i]] = skrg;
			}
		}
	}
	if(asal[t] == -1) {
		return false;
	}
	int a, b;
	a = asal[t];
	b = t;
	while(b != ss) {
		
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &va[i], &co[i], &m[i]);
		list[i] = va[i] - co[i];
		for(int j = 1; j <= m[i]; j++) {
			scanf("%d", &x);
			v[i].push_back(x);
			vis[x] = 1;
		}
	}
	ss = n + 1;
	t = n + 2;
	s = 0;
	for(int i = 1; i <= n; i++) {
		if(cek[i] == 0) {
			v[s].push_back(i);
		}
		v[i].push_back(t);
	}
	v[ss].push_back(s);
	list[t] = 0;
	list[s] = 0;

	ans = 0;
	for(int i = 1; i <= n; i++) {

		for(int j = 1; j <= t; j++) {
			for(int k = 1; k <= t; k++) {
				cap[j][k] = n;
			}
		}
		cap[ss][s] = i;
		while(SPFA()) {

		}
	}
	return 0;
}