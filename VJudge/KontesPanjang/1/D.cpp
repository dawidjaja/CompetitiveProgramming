#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

pii list[1050000];
long long n, ans;

long long f(long long x) {
	if(x == 0) {
		return 0;
	}
	return min(f(list[x].fs), f(list[x].sc)) + 1;
}

int main() {
	while(scanf("%lld", &n) != EOF) {
		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld", &list[i].fs, &list[i].sc);
			
		}
		ans = f(1);
		printf("%lld\n", ans);
	}
	return 0;
}