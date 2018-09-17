#include <algorithm>
#include <cstdio>
#include <queue>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

int n, list[10005], ans;
priority_queue <pii> pq;

int main() {
	freopen(("A.in"), "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		pq.push(mp(-list[i], i));
	}
	ans = 0;
	while(pq.top().fs > 0) {
		int skrg, idx;
		skrg = -pq.top().fs;
		idx = pq.top().sc;
		pq.pop();
		if(list[idx] != skrg) {
			continue;
		}
		ans++;
		list[idx] = -list[idx];
		int a, b;
		a = (idx + n - 1) % n;
		b = (idx + 1) % n;
		list[a] -= list[idx];
		list[b] -= list[idx];
		pq.push(mp(-list[a], a));
		pq.push(mp(-list[b], b));
	}
	printf("%d\n", ans);
	return 0;
}