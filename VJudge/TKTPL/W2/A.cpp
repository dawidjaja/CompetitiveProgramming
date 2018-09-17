#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int ans, n, x;
priority_queue <int> pq;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if((pq.empty() || pq.top() == i - 1) && x == i) {
			ans++;
			// printf("-- %d --\n", i);
		}
		pq.push(x);
	}
	printf("%d\n", ans);
	return 0;
}