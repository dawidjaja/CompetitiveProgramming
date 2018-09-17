#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long>

using namespace std;

long long n;
pii t;
pii list[100005], atas[100005];
vector <long long> v[5];
vector <pii> vv;
double ans, dua;

double cross(pii a, pii b) {
	return a.fs * b.sc - a.sc * b.fs;
}

bool kiri(pii a, pii b, pii c) {
	// printf("%lld %lld, %lld %lld, %lld %lld ", a.fs, a.sc, b.fs, b.sc, c.fs, c.sc);
	if(cross(mp(b.fs - a.fs, b.sc - a.sc), mp(c.fs - b.fs, c.sc - b.sc)) >= 0) {
		// printf("kiri\n");
		return true;
	}
	// printf("kanan\n");
	return false;
}

int main() {
	freopen(("E.in"), "r", stdin);
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld%lld", &t.fs, &t.sc);
		vv.push_back(t);
	}
	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	for(long long i = 0; i < vv.size(); i++) {
		list[i + 1] = vv[i];
	}
	n = vv.size();
	// for(long long i = 1; i <= n; i++) {
	// 	atas[i] = list[i];
	// }
	for(long long j = 1; j <= 2; j++) {
		for(long long i = 1; i <= n; i++) {
			if(v[j].size() <= 1) {
				v[j].push_back(i);
			} else {
				long long a, b;
				a = v[j][v[j].size() - 2];
				b = v[j][v[j].size() - 1];
				while(kiri(list[a], list[b], list[i])) {
					v[j].pop_back();
					if(v[j].size() <= 1) {
						break;
					}
					a = v[j][v[j].size() - 2];
					b = v[j][v[j].size() - 1];
				}
				v[j].push_back(i);
			}
		}
		if(j == 2) {
			break;
		}
		for(long long i = 1; i <= n / 2; i++) {
			atas[i] = list[i];
			atas[n + 1 - i] = list[n + 1 - i];
			swap(list[i], list[n + 1 - i]);
		}
		if(n & 1) {
			atas[n / 2 + 1] = list[n / 2 + 1];
		}
	}
	// for(long long i = 1; i <= n; i++) {
	// 	printf("%lld %lld\n", atas[i].fs, atas[i].sc);
	// }
	// printf("\n");

	// for(long long i = 1; i <= n; i++) {
	// 	printf("%lld %lld\n", list[i].fs, list[i].sc);
	// }
	// for(long long i = 0; i < v[1].size(); i++) {
	// 	printf("-- %lld %lld --\n", atas[v[1][i]].fs, atas[v[1][i]].sc);
	// }
	// printf("\n");
	// for(long long i = 0; i < v[2].size(); i++) {
	// 	printf("-- %lld %lld --\n", list[v[2][i]].fs, list[v[2][i]].sc);
	// }
	dua = sqrt(2);
	ans = 0;
	for(long long i = 1; i < v[1].size(); i++) {
		long long a, b, temp;
		a = atas[v[1][i]].fs - atas[v[1][i - 1]].fs;
		b = atas[v[1][i]].sc - atas[v[1][i - 1]].sc;
		a = abs(a);
		b = abs(b);
		temp = min(a, b);
		ans += dua * temp;
		ans += abs(a - b);
	}
	for(long long i = 1; i < v[2].size(); i++) {
		long long a, b, temp;
		a = list[v[2][i]].fs - list[v[2][i - 1]].fs;
		b = list[v[2][i]].sc - list[v[2][i - 1]].sc;
		a = abs(a);
		b = abs(b);
		temp = min(a, b);
		ans += dua * temp;
		ans += abs(a - b);
	}
	ans += 4 * dua;
	printf("%.4lf\n", ans);
	return 0;
}