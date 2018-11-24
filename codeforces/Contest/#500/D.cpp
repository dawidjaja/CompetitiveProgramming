#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, q, ans, l, r, vis[2][200005], a, b, ada[2][200005], ca, cb;
vector <int> v[2][200005];

void dfs(int skrg, int st) {
	if (st)
		r++;
	else
		l++;
	for (unsigned int i = 0; i < v[st][skrg].size(); i++) {
		if (vis[st ^ 1][v[st][skrg][i]] == 0) {
			vis[st ^ 1][v[st][skrg][i]] = 1;
			dfs(v[st][skrg][i], st ^ 1);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	ca = m;
	cb = n;
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &a, &b);
		ada[0][a]++;
		ada[1][b]++;
		if (ada[0][a] == 1)
			ca--;
		if (ada[1][b] == 1)
			cb--;
		v[0][a].push_back(b);
		v[1][b].push_back(a);
	}
	ans = n * m - (ca * (n - 1)) - (cb * (m - ca - 1));
	// printf("%d %d %d\n", ca, cb, ans);
	for(int i = 1; i <= n; i++) {
		if (vis[0][i] == 0) {
			l = r = 0;
			vis[0][i] = 1;
			dfs(i, 0);
			ans -= l * r;
		}
	}
	printf("%d\n", ans);
	return 0;
}