#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

long long n, x, k, list[100005], sta[100005], sle[100005], ans;
map <long long, long long> aw, bl;
vector <pii> v;

int main() {
	scanf("%lld%lld%lld", &n, &x, &k);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &list[i]);
		sta[i] = (list[i] - 1) / x;
		sle[i] = list[i] / x;
		aw[sta[i]]++;
		bl[sle[i]]++;
	}
	sort(list + 1, list + 1 + n);
	for(auto it = aw.begin(); it != aw.end(); it++) {
		v.push_back({it->fs, it->sc});
	}
	for(long long i = 0; i < v.size(); i++) {
		ans += v[i].sc * bl[v[i].fs + k];
	}
	printf("%lld\n", ans);
	return 0;
}