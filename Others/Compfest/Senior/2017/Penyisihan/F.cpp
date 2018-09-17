#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>
#define MOD 1000000007

using namespace std;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			//bersihin
			v[i].clear();
			for(int j = 1; j <= 2001; j++) {
				list[i][j] = -1;
				vis[i][j] = 0;
			}
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			v[a].push_back(mp(b, c));
			v[b].push_back(mp(a, c));
		}
		q.push(mp(1, 0));
		while(q.size()) {
			int skrg = q.front().fs;
			int jln = q.front().sc;
			vis[skrg][jln] = 0;
			q.pop();
			for(int i = 0; i < v[skrg].size(); i++) {
				if(v[skrg][i].sc <= jln) {
					if(vis[v[skrg][i].fs][jln + 1] == 0) {
						q.push(mp(v[skrg][i].fs, jln + 1));
						vis[v[skrg][i]][jln + 1] = 1;
						list[v[skrg][i]][jln + 1] = (list[skrg][jln] * fakt[jln + 1]) % MOD;
					}
				}
			}
		}
	}
	return 0;
}