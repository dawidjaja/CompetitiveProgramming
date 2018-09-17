#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long>
#define ppi pair<pii,long long>

using namespace std;

//#define getchar_unlocked() getchar()
inline long long baca() {
	long long temp = 0;
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
	long long num, s, h;
};

node* root;
long long t, x, s, ans, y, n, d, yy, xb, yb, nb;
char c;
vector <ppi> list;

node* newnode(long long x) {
	node* temp;
	temp = new node();
	temp->l = NULL;
	temp->r = NULL;
	temp->num = x;
	temp->s = 1;
	temp->h = 1;
	return temp;
}

inline long long getN(node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->num;
}

inline long long getS(node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->s;
}

inline long long getH(node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->h;
}

inline long long getB(node* skrg) {
	return getH(skrg->r) - getH(skrg->l);
}

inline void updateS(node* skrg) {
	skrg->s = getS(skrg->l) + getS(skrg->r) + 1;
}

inline void updateH(node* skrg) {
	skrg->h = max(getH(skrg->l), getH(skrg->r)) + 1;
}

node* rotateL(node* skrg) {
	node* xR = skrg->r;
	node* xRL = xR->l;
	skrg->r = xRL;
	xR->l = skrg;
	updateS(skrg);
	updateH(skrg);
	updateS(xR);
	updateH(xR);
	return xR;
}

node* rotateR(node* skrg) {
	node* xL = skrg->l;
	node* xLR = xL->r;
	skrg->l = xLR;
	xL->r = skrg;
	updateS(skrg);
	updateH(skrg);
	updateS(xL);
	updateH(xL);
	return xL;
}

inline node* balance(node* skrg) {
	long long dif, beda;
	dif = getB(skrg);
	if(dif >= 2) {
		beda = getB(skrg->r);
		if(beda < 0) {
			skrg->r = rotateR(skrg->r);
		}
		return rotateL(skrg);
	} else if(dif <= -2) {
		beda = getB(skrg->l);
		if(beda > 0) {
			skrg->l = rotateL(skrg->l);
		}
		return rotateR(skrg);
	}
	return skrg;
}

node* insert(node* skrg, long long x) {
	if(skrg == NULL) {
		skrg = newnode(x);
		return skrg;
	}
	if(x < skrg->num) {
		skrg->l = insert(skrg->l, x);
	} else {
		skrg->r = insert(skrg->r, x);
	}
	updateS(skrg);
	updateH(skrg);
	return balance(skrg);
}

inline node* caki(node* skrg) {
	node* temp = skrg;
	while(temp->l != NULL) {
		temp = temp->l;
	}
	return temp;
}

node* hapus(node* skrg, long long x) {
	if(skrg == NULL) {
		return skrg;
	}
	if(getN(skrg) == x) {
		if(skrg->l == NULL || skrg->r == NULL) {
			if(skrg->l == skrg->r) {
				skrg = NULL;
			} else {
				if(skrg->l == NULL) {
					*skrg = *skrg->r;
					free(skrg->r);
					return skrg;
				} else if(skrg->r == NULL) {
					*skrg = *skrg->l;
					free(skrg->l);
					return skrg;
				}
			}
		} else {
			node* temp = caki(skrg->r);
			skrg->num = temp->num;
			skrg->r = hapus(skrg->r, temp->num);
		}
	} else if(getN(skrg) > x) {
		skrg->l = hapus(skrg->l, x);
	} else {
		skrg->r = hapus(skrg->r, x);
	}
	if(skrg == NULL) {
		return skrg;
	}
	updateS(skrg);
	updateH(skrg);
	return balance(skrg);
}

long long cari(node* skrg, long long x) {
	if(skrg == NULL) {
		return 0;
	}
	if(getN(skrg) == x) {
		return getS(skrg->l) + 1;
	} else if(getN(skrg) > x) {
		return cari(skrg->l, x);
	} else {
		return cari(skrg->r, x) + 1 + getS(skrg->l);
	}
}

void tulis(node* skrg) {
	if(skrg == NULL) {
		return;
	}
//	printf("%lld --> %lld %lld\n", getN(skrg), getN(skrg->l), getN(skrg->r));
	tulis(skrg->l);
	tulis(skrg->r);
}

void pus(node* skrg) {
	if(skrg == NULL) {
		return;
	}
	if(skrg->l != NULL) {
		pus(skrg->l);
	}
	if(skrg->r != NULL){
		pus(skrg->r);
	}
	free(skrg);
}

int main() {
//	scanf("%lld", &t);
	t = baca();
	while(t--) {
		ans = 0;
		list.clear();
//		scanf("%lld", &s);
		s = baca();
//		scanf("%lld%lld%lld", &x, &y, &n);
		x = baca();
		y = baca();
		n = baca();
//		printf("%lld %lld %lld\n", x, y, n);
		for(long long i = 0; i < n; i++) {
//			getchar();
			c = getchar();
//			scanf("%lld", &d);
			d = baca();
			if(c == 'R' || c == 'L') {
				//horizontal
				if(c == 'R') {
					//kanan
					list.push_back(mp(mp(x, y), 0));
					x += d;
					list.push_back(mp(mp(x, y), -1));
				} else {
					//kiri
					list.push_back(mp(mp(x, y), -1));
					x -= d;
					list.push_back(mp(mp(x, y), 0));
				}
			} else {
				//vertical
				if(c == 'U') {
					//naik
					list.push_back(mp(mp(x, y), y+d));
					y += d;
				} else {
					//turun
					list.push_back(mp(mp(x, y-d), y));
					y -= d;
				}
			}
		}
//		scanf("%lld%lld%lld", &x, &y, &n);
		x = baca();
		y = baca();
		n = baca();
//		printf("%lld %lld %lld\n", x, y, n);
		for(long long i = 0; i < n; i++) {
//			getchar();
			c = getchar();
//			scanf("%lld", &d);
			d = baca();
			if(c == 'R' || c == 'L') {
				//horizontal
				if(c == 'R') {
					//kanan
					list.push_back(mp(mp(x, y), 0));
					x += d;
					list.push_back(mp(mp(x, y), -1));
				} else {
					//kiri
					list.push_back(mp(mp(x, y), -1));
					x -= d;
					list.push_back(mp(mp(x, y), 0));
				}
			} else {
				//vertical
				if(c == 'U') {
					//naik
					list.push_back(mp(mp(x, y), y+d));
					y += d;
				} else {
					//turun
					list.push_back(mp(mp(x, y-d), y));
					y -= d;
				}
			}
		}
		
		sort(list.begin(), list.end());
//		for(int i = 0; i < list.size(); i++) {
//			printf("-- %lld %lld %lld --\n", list[i].fs.fs, list[i].fs.sc, list[i].sc);
//		}
//		
		root = new node();
		root = NULL;
		for(long long i = 0; i < list.size(); i++) {
			x = list[i].fs.fs;
			y = list[i].fs.sc;
			yy = list[i].sc;
//			printf("-- %lld %lld %lld --\n", x, y, yy);
			if(yy <= 0) {
				//horizontal
				if(yy == 0) {
					root = insert(root, y);
				} else {
					root = hapus(root, y);
				}
			} else {
				//vertical
				ans += cari(root, yy-1) - cari(root, y);
			}
			tulis(root);
		}
		printf("%lld\n", ans);
		//ntar mesti hapus semua;
		pus(root);
	}
	return 0;
}
