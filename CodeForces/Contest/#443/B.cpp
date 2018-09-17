#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

long long n, k, x, gde, ctr, a, b;
queue <long long> q;

int main() {
	scanf("%lld%lld", &n, &k);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &x);
		q.push(x);
		gde = max(x, gde);
	}
	if(k >= n || n == 1) {
		printf("%lld\n", gde);
		return 0;
	} else {
		ctr = 1;
		a = q.front();
		q.pop();
		b = q.front();
		q.pop();
		a = max(a, b);
		q.push(min(a, b));
		while(ctr < k) {
			b = q.front();
			q.pop();
			if(b > a) {
				ctr = 1;
				q.push(a);
				a = b;
			} else {
				q.push(b);
				ctr++;
			}
		}
		printf("%lld\n", a);
	}
	return 0;
}