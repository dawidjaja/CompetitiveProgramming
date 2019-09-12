#include <algorithm>
#include <cstdio>
#include <vector>

#define MOD 1000000007

using namespace std;

long long dp[100005][5][15], child[100005], sib[100005], kcl, gde, ans, n, m, a, b, k, x;
vector <long long> v[100005];

void dfs(long long skrg, long long sblm) {
	// printf("%lld %lld\n", skrg, sblm);
	long long anaka = -1;
	for(long long i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] == sblm) {
			continue;
		}
		if(child[skrg] == 0) {
			child[skrg] = v[skrg][i];
		}
		if(anaka != -1) {
			// printf("%lld --> %lld\n", anaka, v[skrg][i]);
			sib[anaka] = v[skrg][i];
		}
		dfs(v[skrg][i], skrg);
		anaka = v[skrg][i];
	}
}

long long f(long long skrg, long long sblm, long long sisa) {
	if(sisa < 0) {
		return 0;
	}
	if(skrg == 0) {
		if(sisa == 0) {
			return 1;
		} else {
			return 0;
		}
	}
	if(dp[skrg][sblm][sisa] != -1) {
		return dp[skrg][sblm][sisa];
	}
	long long &ret = dp[skrg][sblm][sisa];
	ret = 0;
	if(sblm <= 1) {
		if(sib[skrg] == 0 && child[skrg] == 0) {
			if(sisa == 1) {
				ret = 1;
			} else if(sisa == 0) {
				ret = kcl + gde;
			} else {
				ret = 0;
			}
			// ret = kcl + gde + (sisa >= 1 ? 1 : 0);
		} else {
			for(long long i = 0; i <= sisa; i++) {
				ret += f(child[skrg], 1, i) * f(sib[skrg], sblm, sisa - i) % MOD * kcl;
				ret = ret % MOD;
			}
			if(sisa >= 1) {
				for(long long i = 0; i < sisa; i++) {
					ret += f(child[skrg], 2, i) * f(sib[skrg], sblm, sisa - i - 1);
					ret = ret % MOD;
				}
			}
			for(long long i = 0;  i <= sisa; i++) {
				ret += f(child[skrg], 3, i) * f(sib[skrg], sblm, sisa - i) % MOD * gde;
				ret = ret % MOD;
			}
		}

	} else if(sblm == 2) {
		if(sib[skrg] == 0 && child[skrg] == 0) {
			if(sisa == 0) {
				ret = kcl;
			} else {
				ret = 0;
			}
		} else {
			for(long long i = 0; i <= sisa; i++) {
				ret += f(child[skrg], 1, i) * f(sib[skrg], sblm, sisa - i) % MOD * kcl;
				ret = ret % MOD;
			}
		}

	} else if(sblm == 3) {
		if(sib[skrg] == 0 && child[skrg] == 0) {
			if(sisa == 0) {
				ret = kcl + gde;
			} else {
				ret = 0;
			}
		} else {
			for(long long i = 0; i <= sisa; i++) {
				ret += f(child[skrg], 1, i) * f(sib[skrg], sblm, sisa - i) % MOD * kcl;
				ret = ret % MOD;
			}
			for(long long i = 0;  i <= sisa; i++) {
				ret += f(child[skrg], 3, i) * f(sib[skrg], sblm, sisa - i) % MOD * gde;
				ret = ret % MOD;
			}
		}
	}
	// printf("---- %lld %lld %lld --->> %lld \n", skrg, sblm, sisa, ret);
	return ret;
}

int main() {
	scanf("%lld%lld", &n, &m);
	for(long long i = 1; i < n; i++) {
		scanf("%lld%lld", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	scanf("%lld%lld", &k, &x);
	dfs(1, -1);
	for(long long i = 0; i <= n; i++) {
		for(long long j = 0; j <= 3; j++) {
			for(long long k = 0; k <= x; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	kcl = k - 1;
	gde = m - k;
	// for(int i = 1; i <= n; i++) {
	// 	printf("%lld --> %lld %lld\n", i, child[i], sib[i]);
	// }
	// printf("-- %lld %lld --\n", kcl, gde);
	for(int i = 0; i <= x; i++) {
		ans += f(1, 0, i);	
		ans = ans % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}