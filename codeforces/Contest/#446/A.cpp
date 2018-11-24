#include <algorithm>
#include <cstdio>

using namespace std;

long long n, x, ttl, b[100005];

int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		ttl += x;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &b[i]);
	}
	sort(b + 1, b + 1 + n);
	if(b[n] + b[n - 1] >= ttl) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}