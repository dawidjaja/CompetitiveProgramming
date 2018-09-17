#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

int list[200005], freq[200005], ps[200005], n, q, ctr, f, num, a, b, l, r;
long long hsl[200005], ans;
ppi mo[200005];
map <int,int> ada;

//#define getchar_unlocked() getchar()
inline int baca() {
	int temp = 0;
	char c;
	c = getchar_unlocked();
	while(c < '0' || c > '9') {
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9') {
		temp *= 10;
		temp += c - '0';
		c = getchar_unlocked();
	}
	return temp;
}

bool cmp(ppi a, ppi b) {
	int c, d;
	c = a.fs.fs / f;
	d = b.fs.fs / f;
	if(c < d || (c == d && a.fs.sc < b.fs.sc)) {
		return true;
	}
	return false;
}

int main() {
//	scanf("%d%d", &n, &q);
	n = baca();
	q = baca();
	ctr = 1;
	f = sqrt(q);
	for(int i = 1; i <= n; i++) {
//		scanf("%d", &num);
		num = baca();
		if(!ada.count(num)) {
			ada[num] = ctr++;
		}
		list[i] = ada[num];
	}
	for(int i = 1; i <= q; i++) {
//		scanf("%d%d", &a, &b);
		a = baca();
		b = baca();
		mo[i] = mp(mp(a, b), i);
	}

	sort(mo + 1, mo + 1 + q, cmp);

	l = 1;
	r = 0;

	for(int i = 1; i <= q; i++) {
		int ki, ka;
		ki = mo[i].fs.fs;
		ka = mo[i].fs.sc;
		while(r < ka) {
			r++;
			freq[list[r]]++;
			ps[freq[list[r]]]++;
			ans += ps[freq[list[r]]];
		}
		while(l > ki) {
			l--;
			freq[list[l]]++;
			ps[freq[list[l]]]++;
			ans += ps[freq[list[l]]];
		}
		while(r > ka) {
			ans -= ps[freq[list[r]]];
			ps[freq[list[r]]]--;
			freq[list[r]]--;
			r--;
		}
		while(l < ki) {
			ans -= ps[freq[list[l]]];
			ps[freq[list[l]]]--;
			freq[list[l]]--;
			l++;
		}
		hsl[mo[i].sc] = ans;
	}
	for(int i = 1; i <= q; i++) {
		printf("%lld\n", hsl[i]);
	}
	return 0;
}
