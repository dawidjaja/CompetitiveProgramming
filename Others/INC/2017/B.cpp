#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

int n, k, m, list[100005], ki, ka, krg[100005], ans, x, c;
priority_queue <pii> pq;
set <int> s;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &x);
		s.insert(x);
	}
	c = 0;
	for(auto i = s.begin(); i != s.end(); i++) {
		list[++c] = *i;
	}
	m = c;

	if(k >= m) {
		printf("%d\n", n);
		return 0;
	}

	sort(list + 1, list + 1 + m);
	pq.push({(list[2] - list[1]) / 2 + list[1], 1});
	for(int i = 2; i < m; i++) {
		ki = (list[i] - list[i - 1]) / 2;
		ka = (list[i + 1] - list[i]) / 2;

		pq.push({ki + 1 + ka, i});
	}
	pq.push({(list[m] - list[m - 1]) / 2 + n - list[m] + 1, m});
	while(k--) {
		int skrg, dpt;
		skrg = pq.top().sc;
		dpt = pq.top().fs;
		pq.pop();
		while(krg[skrg] != 0) {
			pq.push({dpt - krg[skrg], skrg});
			krg[skrg] = 0;
			skrg = pq.top().sc;
			dpt = pq.top().fs;
			pq.pop();
		}
		// printf("-- %d\n", skrg);
		ans += dpt;
		if(skrg != 1) {
			if(((list[skrg] - list[skrg - 1]) % 2) == 0) {
				krg[skrg - 1]++;
			}
		}
		if(skrg != m) {
			if(((list[skrg + 1] - list[skrg]) % 2) == 0) {
				krg[skrg + 1]++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}