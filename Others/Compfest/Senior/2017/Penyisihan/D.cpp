#include <algorithm>
#include <cstdio>

using namespace std;

void dfs1(int skrg, int sblm) {
	vis[skrg] = 1;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm) {
			if(nemu > 0) {
				cycle[skrg] = 1;
				break;
			}
			if(vis[v[skrg][i]] == 1) {
				cycle[v[skrg][i]] = 1;
				cycle[skrg] = 1;
				awal = nemu = skrg;
			} else {
				dfs1(v[skrg][i], skrg);
			}
			if(nemu > 0) {
				cycle[skrg] = 1;
				if(skrg == nemu) {
					nemu = -1;
				}
				break;
			} else if(nemu == -1) {
				break;
			}
		}
	}
}

void dfs2(int skrg, int sblm) {
	vis[skrg] = 1;
	if(cycle[skrg] == 1) {
		lvl[skrg] = 0;
		for(int i = 0; i <= 17; i++) {
			par[skrg][i] = -1;
		}
		grup[skrg] = list[skrg] = sblm == -1 ? -1 : list[sblm] - 1;
	} else {
		lvl[skrg] = lvl[sblm] + 1;
		par[skrg][0] = sblm;
		grup[skrg] = grup[sblm];
		list[skrg] = max(0, list[skrg]) + 1;
	}
	for(int i = 0; i < v[skrg].size(); i++) {
		if(vis[v[skrg][i]] == 0) {
			dfs2(v[skrg][i], skrg);
		}
	}
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);

		for(int i = 1; i <= n; i++) {
			v[i].clear();
			vis[i] = 0;
			kasus = 1;
		}

		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}

		q.push(1);
		vis[1] = -1;
		while(q.size()) {
			int skrg = q.front();
			for(int i = 0; i < v[skrg].size(); i++) {
				if(vis[v[skrg][i]] != 0) {
					if(vis[v[skrg][i]] == skrg) {
						kasus = 2;
						c = skrg;
						d = v[skrg][i];
						while(q.size()) {
							q.pop();
						}
						break;
					}
				} else {
					vis[v[skrg][i]] = skrg;
					q.push(v[skrg][i]);
				}
			}
		}
		if(kasus == 1) {
			for(int i = 1; i <= n; i++) {
				vis[i] = 0;
				cycle[i] = 0;
				awal = nemu = 0;
			}
			dfs1(1, -1);
			for(int i = 1; i <= n; i++) {
				vis[i] = 0;
			}
			dfs2(awal, -1);
			scanf("%d", &q);
			while(q--) {
				scanf("%d%d", &a, &b);

			}

		} else {
			scanf("%d", &q);
			while(q--) {
				scanf("%d%d", &a, &b);

			}
		}
	}
	return 0;
}