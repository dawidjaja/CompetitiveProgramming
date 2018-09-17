#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define mp make_pair



using namespace std;

void bikin(int skrg, int l, int r) {
	if(l == r) {
		st[skrg].fs.fs = 0;
		st[skrg].fs.sc = 
		;
		st[skrg].sc.fs = ;
		st[skrg].sc.sc = ;
		return;
	}
	int mid;
	mid = (l + r) / 2;
	bikin(skrg*2, l, mid);
	bikin(skrg*2+1, mid+1, r);
	return;
}

void update(int skrg, int l, int r, int pos, int val) {
	if(l == r) {
	}
	if(r < pos || pos < l) {
	}
	int mid;
	mid = (l + r) / 2;
	update(skrg*2, l, mid, pos, val);
	update(skrg*2+1, mid+1, r, pos, val);
	return;
}

int main () {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a, b, c, d, e;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		list[i*2] = mp(mp(a, e), mp(b, d));
		list[i*2+1] = mp(mp(c, -e), mp(b, d));
		xx.push_back(a);
		xx.push_back(b);
		yy.push_back(c);
		yy.push_back(d);
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	xx.erase(xx.unique(xx.begin(), xx.end()), xx.end());
	yy.erase(yy.unique(yy.begin(), yy.end()), yy.end());
	for(int i = 0; i < xx.size(); i++) {
		mx[xx[i]] = i;
	}
	for(int i = 0; i < yy.size(); i++) {
		my[yy[i]] = i;
	}
	for(int i = 0; i < 2*n; i++) {
		list[i].fs.fs = mx[list[i].fs.fs];
		list[i].sc.fs = my[list[i].sc.fs];
		list[i].sc.sc = my[list[i].sc.sc];
	}
	sort(list, list+n);

//	segtree
//	.fs.fs = ujung ke ujung
//	.fs.sc = best semua
//	.sc.fs = best dari kiri
//	.sc.sc = best dari kanan
	
	int skrg, sblm, maks;
	long long luas;
	luas = 0;
	maks = 0;
	bikin(1, 0, n*2-1);
	update(1, 0, n*2-1, list[0].sc.fs, list[0].fs.sc);
	update(1, 0, n*2-1, list[0].sc.sc, -list[0].fs.sc);
	sblm = list[0].fs.fs;
	for(int i = 1; i < n*2; i++) {
		skrg = list[i].fs.fs;
		if(st
	}
	
	return 0;
}
