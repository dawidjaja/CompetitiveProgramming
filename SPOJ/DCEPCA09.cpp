#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int> 
#define pip pair<int, pii>
#define ppi pair<pii, int>
//#define getchar_unlocked() getchar()
#define push_back emplace_back

using namespace std;

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

struct node {
	node* l;
	node* r;
	int num;
	node(int num, node* l, node* r) :
		num(num), l(l), r(r){}
};

int k, itung, n, list[10005], ctr[10005], q, kiri, kanan;
long long ps[10005];
pii query[10005], modus[10005];
ppi mo[10005];
map <int, int> ada, jmlh;
node* root[10005];
vector <int> blk;
priority_queue <pii> pq;

bool cmp(ppi a, ppi b) {
	int c, d;
	c = a.fs.fs/k;
	d = b.fs.fs/k;
	if(c < d) {
		return true;
	}
	if(c == d && (a.fs.sc < b.fs.sc)) {
		return true;
	}
	return false;
}

inline int getN(node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->num;
}

inline void updateN(node* skrg) {
	skrg->num = getN(skrg->l) + getN(skrg->r);
}

node* bikinpst(node* skrg, int l, int r) {
	if(skrg == NULL) {
		skrg = new node(0, NULL, NULL);
	}
	if(l == r) {
		skrg = new node(0, NULL, NULL);
		return skrg;
	}
	int tgh = (l + r) >> 1;
	skrg->l = bikinpst(skrg->l, l, tgh);
	skrg->r = bikinpst(skrg->r, tgh + 1, r);
	return skrg;
}

node* insert(node* skrg, int l, int r, int x, int jmlh) {
	if(x < l || r < x) {
		return skrg;
	}
	if(skrg == NULL) {
		skrg = new node(0, NULL, NULL);
	}
	node* temp;
	if(l == r) {
		temp = new node(jmlh, NULL, NULL);
		return temp;
	}
	int tgh = (l + r) >> 1;
	temp = new node(0, insert(skrg->l, l, tgh, x, jmlh), insert(skrg->r, tgh + 1, r, x, jmlh));
	updateN(temp);
	return temp;
}

int caribiasa(node* skrg, int l, int r, int x) {
//	printf("-- %d %d %d --\n", l, r, x);
	if(skrg == NULL) {
		skrg = new node(0, NULL, NULL);
	}
	if(l == r) {
		return l;
	}
	int tgh = (l + r) >> 1;
	int temp = getN(skrg->l);
	if(temp >= x) {
		return caribiasa(skrg->l, l, tgh, x);
	} else {
		return caribiasa(skrg->r, tgh+1, r, x-temp);
	}
}

int cari(node* satu, node* dua, int l, int r, int x) {
	if(satu == NULL) {
		satu = new node(0, NULL, NULL);
	}
	if(dua == NULL) {
		dua = new node(0, NULL, NULL);
	}
	if(l == r) {
		return l;
	}
	int tgh = (l + r) >> 1;
	int temp;
	temp = getN(satu->l) - getN(dua->l);
	if(temp >= x) {
		return cari(satu->l, dua->l, l, tgh, x);
	} else {
		return cari(satu->r, dua->r, tgh+1, r, x-temp);
	}
}

int carimedian(int a, int b) {
//	printf("--- %d %d ---\n", a, b);
	int med = ((b - a) >> 1) + 1;
//	med += a;
	if((b - a + 1) & 1) {
		// ganjil
		if(a <= 0) {
			// b doank
			return blk[caribiasa(root[b], 1, itung, med) - 1];
		} else {
			return blk[cari(root[b], root[a-1], 1, itung, med) - 1];
		}
	} else {
		// genap
		if(a <= 0) {
			// b doank
			return (blk[caribiasa(root[b], 1, itung, med) - 1] + blk[caribiasa(root[b], 1, itung, med + 1) - 1]) / 2;
		} else {
			return (blk[cari(root[b], root[a-1], 1, itung, med) - 1] + blk[cari(root[b], root[a-1], 1, itung, med + 1) - 1]) / 2;
		}
	}
}

int main () {
//	scanf("%d", &n);
	n = baca();
	itung = 0;
	for(int i = 0; i < n; i++) {
//		scanf("%d", &list[i]);
		list[i] = baca();
		if(!ada.count(list[i])) {
			ada[list[i]] = ++itung;
			blk.push_back(list[i]);
		}
		if(i) {
			ps[i] = ps[i-1] + list[i];
		} else {
			ps[i] = list[i];
		}
	}
	sort(blk.begin(), blk.end());
	for(int i = 0; i < itung; i++) {
		ada[blk[i]] = i+1;
	}
	//median
//	printf("-- %d\n", itung);
	
	root[0] = bikinpst(root[0], 1, itung);
	
	for(int i = 0; i < n; i++) {
		root[i] = insert(root[max(i-1, 0)], 1, itung, ada[list[i]], ++ctr[ada[list[i]]]);
	}
	
	
	//query
	
//	scanf("%d", &q);
	q = baca();
	k = sqrt(q);
	for(int i = 0; i < q; i++) {
//		scanf("%d%d", &query[i].fs, &query[i].sc);
		query[i].fs = baca();
		query[i].sc = baca();
		mo[i] = mp(query[i], i);
	}
	sort(mo, mo + q, cmp);
	kiri = 0;
	kanan = -1;
	for(int i = 0; i < q; i++) {
		while(kanan < mo[i].fs.sc) {
			kanan++;
			jmlh[list[kanan]]++;
			pq.push(mp(jmlh[list[kanan]], list[kanan]));
		}
		while(kiri > mo[i].fs.fs) {
			kiri--;
			jmlh[list[kiri]]++;
			pq.push(mp(jmlh[list[kiri]], list[kiri]));
		}
		while(kiri < mo[i].fs.fs) {
			jmlh[list[kiri]]--;
			pq.push(mp(jmlh[list[kiri]], list[kiri]));
			kiri++;
		}
		while(kanan > mo[i].fs.sc) {
			jmlh[list[kanan]]--;
			pq.push(mp(jmlh[list[kanan]], list[kanan]));
			kanan--;
		}
		while(jmlh[pq.top().sc] != pq.top().fs) {
			pq.pop();
		}
		modus[mo[i].sc] = pq.top();
	}
	
//	for(int i = 0; i < n; i++) {
//		printf("root %d\n", i);
//		tulisis(root[i]);
//		printf("\n");
//	}
//	
//	for(int i = 0; i < blk.size(); i++) {
//		printf("---- %d %d ----\n", i, blk[i]);
//	}
	
	for(int i = 0; i < q; i++) {
		int a, b;
		a = query[i].fs;
		b = query[i].sc;
		int median, mode;
		long long mean;
		mean = ps[b];
		if(a > 0) {
			mean -= ps[a-1];
		}
		mean /= b - a + 1;
		median = carimedian(a, b);
		mode = modus[i].sc;
		printf("%d %d %d\n", mean, median, mode);
	}
	return 0;
}
