#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <assert.h>
#include <cstring>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long> 

using namespace std;

long long t, n, X, K, p[100005][20], lvl[100005], q, mulai, trgt, temp;
double ans, hrg[100005][20];
pii list[100005];
vector <long long> ch;

bool cmp(pii a, pii b){
	return a>b;
}

double cross(pii a, pii b) {
	double ans;
	ans = a.fs * b.sc - b.fs * a.sc;
	return ans;
}

double grad(pii a, pii b) {
	double ans, c, d;
	c = a.sc - b.sc;
	d = a.fs - b.fs;
	ans = c/d;
	return ans;
}

bool cek(long long skrg) {
	pii a, b, c;
	a = list[skrg];
	b = list[ch[ch.size()-1]];
	c = list[ch[ch.size()-2]];
//	printf("-- %lld %lld, %lld %lld, %lld %lld --\n", a.fs, a.sc, b.fs, b.sc, c.fs, c.sc);
//	printf("--- %.2lf %.2lf ---\n", grad(a, b), grad(b, c));
	pii d, e;
	d = mp(b.fs - a.fs, b.sc - a.sc);
	e = mp(c.fs - b.fs, c.sc - b.sc);
	if(cross(d, e) > 0) {
//		printf("YES\n");
		return true;
	}
//	printf("NO\n");
	return false;
}

long long binser(long long l, long long r, long long cari) {
	if(l == r) {
//		printf("lolol %lld\n", l);
		return l;
	}
	long long mid = (l + r) / 2;
	if(list[mid].fs == cari) {
		return mid;
	}
//	printf("binser lalala %lld %lld %lld %lld\n", l, r, list[mid].fs, cari);
	if(list[mid].fs < cari) {
		return binser(mid + 1, r, cari);
	} else {
		return binser(l, mid, cari);
	}
}

int main () {
	scanf("%lld", &t);
//	if(t != 1) {
//		assert(false);
//	}
	while(t--) {
//		memset(p, 0, sizeof(p));
//		memset(hrg, 0, sizeof(hrg));
//		memset(lvl, 0, sizeof(lvl));
//		memset(list, 0, sizeof(list));
//		while(ch.size()) {
//			ch.pop_back();
//		}
		ch.clear();
		
		scanf("%lld", &n);
		for(long long i = 0; i < n; i++) {
			scanf("%lld%lld", &list[i].fs, &list[i].sc);
		}
		sort(list, list+n);
		for(long long i = 0; i < 20; i++) {
			p[n-1][i] = -1;
		}
		lvl[n-1] = 0;
		
		ch.push_back(n-1);
		
		for(long long i = n-2; i >= 0; i--) {
//			printf("%lld --> ", i);
//			for(long long j = 0; j < ch.size(); j++) {
//				printf("%lld ", ch[j]);
//			}
//			printf(", ");
			while((ch.size() >= 2) && cek(i)) {
				ch.pop_back();
			}
//			printf("%lld --> ", i);
//			for(long long j = 0; j < ch.size(); j++) {
//				printf("%lld ", ch[j]);
//			}
//			printf("\n");
			p[i][0] = ch.back();
			ch.push_back(i);
			lvl[i] = lvl[p[i][0]] + 1;
			hrg[i][0] = cross(list[i], list[p[i][0]]);
			for(long long j = 1; j < 20; j++) {
				if(p[p[i][j-1]][j-1] == -1) {
					for(long long k = j; k < 20; k++) {
						p[i][k] = -1;
					}
					break;
				}
				hrg[i][j] = hrg[i][j-1] + hrg[p[i][j-1]][j-1];
				p[i][j] = p[p[i][j-1]][j-1];
//				printf("-- %lld  --> %lld %lld --\n", i, p[i][j], hrg[p[i][j]][j-1]);
			}
		}
		
//		for(long long i = 0; i < n; i++) {
//			printf("-- %lld --> %lld --\n", i, lvl[i]);
//			for(long long j = 0; j <= 17; j++) {
//				printf("---- %lld  &&  %lld\n", p[i][j], hrg[i][j]);
//			}
//		}
//		
		// dah jadi ch nya
		scanf("%lld", &q);
		while(q--) {
			scanf("%lld%lld", &X, &K);
			if(K <= 2) {
				printf("0.0\n");
				continue;
			}
			mulai = binser(0, n-1, X);
			if(lvl[mulai] <= 1) {
				printf("0.0\n");
				continue;
			}
			trgt = max(lvl[mulai] - K + 1, 0LL);
			temp = mulai;
//			printf("--- %lld %lld --- \n", mulai, trgt);
			ans = 0;
			for(long long i = 19; i >= 0; i--) {
				if(p[temp][i] == -1 || lvl[p[temp][i]] < trgt) {
					continue;
				}
				ans += hrg[temp][i];
				temp = p[temp][i];
			}
			ans += cross(list[temp], list[mulai]);
//			printf("%lld\n", ans);
			ans = fabs(ans);
			ans /= 2;
			printf("%.1lf\n",ans);
		}
	}
}
