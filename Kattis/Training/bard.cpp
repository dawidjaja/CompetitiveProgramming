#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

long long n, e, k, one, vil[105];
vector <long long> v;

int main() {
	scanf("%lld%lld", &n, &e);
	for (long long day = 0; day < e; day++) {
		one = 0;
		v.clear();
		scanf("%lld", &k);
		for (long long i = 0; i < k; i++) {
			long long x;
			scanf("%lld", &x);
			if (x == 1) {
				one = 1;
				vil[1] |= (1LL << day);
			} else {
				v.push_back(x);
			}
		}
		if (one) {
			for (long long i = 0; i < (long long)v.size(); i++) {
				vil[v[i]] |= (1LL << day);
			}
		} else {
			long long songs = 0;
			for (long long i = 0; i < (long long)v.size(); i++) {
				songs |= vil[v[i]];
			}
			for (long long i = 0; i < (long long)v.size(); i++) {
				vil[v[i]] = songs;
			}
		}
	}
	for (long long i = 1; i <= n; i++) {
		if (vil[i] == vil[1]) {
			printf("%lld\n", i);
		}
	}
	return 0;
}