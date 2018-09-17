#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

int n, a, b, vis[100005], ctr[10];
vector <int> v[100005];
queue <pii> q;

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(mp(1, 1));
	q.push(mp(n, 2));
	vis[1] = vis[n] = 1;
	ctr[1] = 1;
	ctr[2] = 1;
	while(q.size()) {
		int skrg, idx;
		skrg = q.front().fs;
		idx = q.front().sc;
		q.pop();
		for(int i = 0; i < v[skrg].size(); i++) {
			if(vis[v[skrg][i]] == 0) {
				vis[v[skrg][i]] = 1;
				ctr[idx]++;
				q.push(mp(v[skrg][i], idx));
			}
		}
	}
	printf(ctr[1] <= ctr[2] ? "Snuke\n" : "Fennec\n");
	return 0;
}