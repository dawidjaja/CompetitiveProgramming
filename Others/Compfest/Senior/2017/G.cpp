#include <cstdio>
#include <algorithm>
#include <map>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

pii list[205];
int idx[205], t, n, a, b, ttl, ps[205];
pair<long long, int> ans;
map <int, pii> dp[205];

bool cmp(pii a, pii b) {
	return a > b;
}

pair<long long, int> f(int skrg, int x) {
	if(skrg > n) {
		// printf("%lld %lld\n", x, ttl - x);
		return mp(x * (ttl - x), 1);
	}
	if(dp[skrg].count(x)) {
		return dp[skrg][x];
	}
	long long a, b;
	a = f(skrg + 1, x).fs;
	b = f(skrg + 1, x + list[skrg].fs).fs;
	if(a > b) {
		idx[list[skrg].sc] = 1;
		// printf("%d %d --> %lld a\n", skrg, x, a);
		return dp[skrg][x] = mp(a, 1);
	} else {
		idx[list[skrg].sc] = 2;
		// printf("%d %d --> %lld b\n", skrg, x, b);
		return dp[skrg][x] = mp(b, 2);
	}
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		ttl = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &list[i].fs);
			list[i].sc = i;
			ps[i] = ps[i - 1] + list[i].fs;
			ttl += list[i].fs;
		}
		sort(list + 1, list + 1 + n, cmp);
		for(int i = 0; i <= n; i++) {
			dp[i].clear();
		}
		ans = f(1, 0);
		printf("%lld\n", ans.fs);
		int temp = 0;
		int porer = ans.sc;
		for(int i = 1; i <= n; i++) {
			if(porer == 1) {
				// printf("1 ");
				idx[list[i].sc] = 1;
			} else {
				temp += list[i].fs;
				// printf("2 ");
				idx[list[i].sc] = 2;
			}
			// printf("%d\n", temp);
			porer = dp[i + 1][temp].sc;
		}
		for(int i = 1; i <= n; i++) {
			printf(idx[i] == 1 ? "R" : "D");
		}
		printf("\n");
	}
	return 0;
}