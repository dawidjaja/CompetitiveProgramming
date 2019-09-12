#include <algorithm>
#include <cstdio>
#include <cmath>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long>
#define pip pair<long long,pii>

using namespace std;

long long n, s, stot, ans, gde, loy, ctr, sisa, l, r, dif, ta, tb, ba, bb, a, b, temp;
pip list[100005];

bool cmp(pip a, pip b) {
	return a.sc.sc > b.sc.sc;
}

bool cek(long long ada, long long idx) {
	long long a = idx;
	while(ada > 0) {
		if(ada >= list[idx].fs) {
			ada -= list[idx].fs;
			idx++;
		} else {
			break;
		}
	}
	// printf("-- lololol %lld %lld\n", a, idx);
	return (a <= l && l < idx);
}

int main() {
	scanf("%lld%lld", &n, &s);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &list[i].fs, &list[i].sc.fs, &list[i].sc.sc);
		list[i].sc.sc -= list[i].sc.fs;
		stot +=list[i].fs;
		// ans += list[i].fs * list[i].sc.fs;
	}
	loy = ceil(1.0 * stot / s);
	gde = ans;
	ctr = 1;
	sisa = stot % s;
	sisa = min(s - sisa, sisa);
	sort(list + 1, list + 1 + n, cmp);
	// for(int i = 1; i <= n; i++) {
	// 	printf("-- %lld %lld %lld\n", list[i].fs, list[i].sc.fs, list[i].sc.sc);
	// }
	a = 1;
	b = n;
	temp = 0;
	long long tt = 0;
	for(long long i = 1; i <= n; i++) {
		if(list[i].sc.sc > 0 && tt / s < (tt + list[i].fs) / s) {
			// printf("%lld %lld %lld asdfasdf\n", temp, list[i].fs, i);
			a = i;
			// break;
			temp = tt;
			// tt = 0;
		}
		tt += list[i].fs;
	}
	// printf("asdfasdfasdfasdf %lld %lld\n", temp, (list[a].fs - ((temp + list[a].fs) % s)));
	ans += (list[a].sc.sc + list[a].sc.fs) * (list[a].fs - ((temp + list[a].fs) % s));
	ba = (list[a].fs - ((temp + list[a].fs) % s));
	list[a].fs =  ((temp + list[a].fs) % s);

	// printf("laasdf %lld\n", ans);
	for(long long i = 1; i < a; i++) {
		ans += list[i].fs * (list[i].sc.fs + list[i].sc.sc);
		// printf("-- %lld \n", ans);
		ba += list[i].fs;
	}
	temp = 0;
	tt = 0;
	for(long long i = n; i >= 1; i--) {
		if(list[i].sc.sc < 0 && tt / s < (tt + list[i].fs) / s) {
			b = i;
			// printf("asdfasdf\n");
			// printf("lolo %lld %lld %lld\n", temp, list[i].fs);
			// break;
			temp = tt;
			// tt = 0;
		}
		tt += list[i].fs;
	}
	// printf("asdfasdfasdfasdf %lld %lld\n", temp, (list[b].fs - ((temp + list[b].fs) % s)));

	ans += list[b].sc.fs * (list[b].fs - ((temp + list[b].fs) % s));
	bb += (list[b].fs - ((temp + list[b].fs) % s));
	list[b].fs = ((temp + list[b].fs) % s);
	// printf("bbb %lld %lld\n", ans, bb);
	for(long long i = n; i > b; i--) {
		ans += list[i].fs * list[i].sc.fs;
		bb += list[i].fs;
		// printf("%lld\n", bb);
		// printf("-- %lld\n", ans);
	}

	// printf("-- %lld %lld %lld %lld %lld %lld --> %lld %lld--\n", a, b, ba, bb, ta, tb, ans, stot);

	dif = stot - ba - bb;
	if(dif <= s) {
		// printf("dket\n");
		ta = 0; 
		tb = 0;
		for(long long i = a; i <= b; i++) {
			ta += list[i].fs * (list[i].sc.fs + list[i].sc.sc);
			tb += list[i].fs * list[i].sc.fs;
		}
		ans += max(ta, tb);
		printf("%lld\n", ans);
	} else {
		ctr = a;
		while(list[ctr].sc.sc > 0) {
			ta += list[ctr].fs * (list[ctr].sc.fs + list[ctr].sc.sc);
			ctr++;
		}
		ctr = b;
		while(list[ctr].sc.sc < 0) {
			tb += list[ctr].fs * list[ctr].sc.fs;
			ctr--;
		}
		ans += max(ta, tb);
		printf("%lld\n", ans);
	}
	return 0;
}