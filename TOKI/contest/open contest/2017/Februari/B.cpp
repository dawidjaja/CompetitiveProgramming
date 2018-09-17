#include <algorithm>
#include <cstdio>
#include <cmath>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long, long long>

using namespace std;

long long n, m, ansl, ansr, cek, ans, a, b, c, vis[155], blkg, skill, hore;
pair <pii, long long> list[155];

int main() {
	scanf("%lld%lld", &n, &m);
	if(n <= m) {
		printf("0\n");
		return 0;
	}
	for(long long i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		list[i] = mp(mp(c, b), a);
	}
	sort(list+1, list+n+1);
//	for(int i = 1; i <= n; i++) {
//		printf("-- %lld %lld %lld --\n", list[i].fs.fs, list[i].fs.sc, list[i].sc);
//	}
	
	//((blkg, dpn), skill)
	
	hore = 0;
	ansl = 0;
	ansr = 1e9;
	
	while(ansl < ansr) {
//		printf("--- %lld %lld ---\n", ansl, ansr);
		long long tgh = (ansl + ansr) / 2;
		for(long long i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		ans = 0;
		cek = n;
		while(cek) {
			blkg = -1;
			skill = -1;
			ans++;
			for(long long i = 1; i <= n; i++) {
				if((vis[i] == 0 && (blkg <= list[i].fs.sc)) && (skill == -1 || (abs(skill - list[i].sc) <= tgh))) {
					vis[i] = 1;
					cek--;
					skill = list[i].sc;
					blkg = list[i].fs.fs;
				}
			}
		}
//		printf("%lld\n", ans);
		if(ans <= m) {
			ansr = tgh;
			hore = 1;
		} else {
			ansl = tgh + 1;
		}
	}
//	printf("-- %lld --\n", ansl);
	if(hore == 1) {
		printf("%lld\n", ansl);
	} else {
		printf("-1\n");
	}
	return 0;
}
