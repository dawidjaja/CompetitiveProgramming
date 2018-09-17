#include <algorithm>
#include <cstdio>
#include <assert.h>

using namespace std;

struct node {
	node* l;
	node* r;
	int s, num, h;
};

int n, q, a, quer, kk, xx, temp;
struct node* root;

#define getchar_unlocked() getchar()
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

node* newnode(int x) {
	node* temp;
	temp = new node();
	temp->l = NULL;
	temp->r = NULL;
	temp->num = x;
	temp->s = 1;
	temp->h = 1;
	return temp;
}

inline int getS(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->s;
}

inline int getH(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->h;
}

inline int getN(struct node* skrg) {
	if(skrg == NULL) {
		return -1;
	}
	return skrg->num;
}

inline int getB(struct node* skrg) {
	return getH(skrg->r) - getH(skrg->l);
}

inline void updateS(struct node* skrg) {
	skrg->s = getS(skrg->l) + getS(skrg->r) + 1;
}

inline void updateH(struct node* skrg) {
	skrg->h = max(getH(skrg->l), getH(skrg->r)) + 1;
}

inline struct node* rotateL(struct node* skrg) {
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

inline struct node* rotateR(struct node* skrg) {
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

inline struct node* caki(struct node* skrg) {
	node* temp = skrg;
	while(temp->l != NULL) {
		temp = temp->l;
	}
	return temp;
}

struct node* insert(struct node* skrg, int x, int k) {
//	printf("-- %d %d %d --\n", getN(skrg), x, k);
	if(skrg == NULL) {
//		assert(k == 1);
		skrg = newnode(x);
		return skrg;
	}
	if(getS(skrg->l) + 1 >= k) {
		skrg->l = insert(skrg->l, x, k);
	} else {
		skrg->r = insert(skrg->r, x, k - getS(skrg->l) - 1);
	}
	updateH(skrg);
	updateS(skrg);
	int beda, dif;
	beda = getB(skrg);
	if(beda >=2) {
		dif = getB(skrg->r);
		if(dif < 0) {
			skrg->r = rotateR(skrg->r);
		}
		return rotateL(skrg);
	} else if(beda <= -2) {
		dif = getB(skrg->l);
		if(dif > 0) {
			skrg->l = rotateL(skrg->l);
		}
		return rotateR(skrg);
	}
	return skrg;
}


struct node* hapus(struct node* skrg, int k) {
//	printf("-- %d %d --\n", getN(skrg), k);
	if(skrg == NULL) {
		return skrg;
	}
	if(getS(skrg->l) + 1 == k) {
		if(skrg->l == NULL || skrg->r == NULL) {
			if(skrg->l == skrg->r) {
				//gapunya anak
				skrg = NULL;
			} else {
				//satu anak
				if(skrg->l == NULL) {
					//anak di r
					*skrg = *skrg->r;
					free(skrg->r);
				} else {
					//anak di l
					*skrg = *skrg->l;
					free(skrg->l);
				}
			}
		} else {
			//ada 2 anak
			node* temp = caki(skrg->r);
			skrg->num = temp->num;
			skrg->r = hapus(skrg->r, 1);
		}
	} else if(getS(skrg->l) >= k) {
		skrg->l = hapus(skrg->l, k);
	} else {
		skrg->r = hapus(skrg->r, k - getS(skrg->l) - 1);
	}
	if(skrg == NULL) {
		return skrg;
	}
	updateH(skrg);
	updateS(skrg);
	int beda, dif;
	beda = getB(skrg);
	if(beda >=2) {
		dif = getB(skrg->r);
		if(dif < 0) {
			skrg->r = rotateR(skrg->r);
		}
		return rotateL(skrg);
	} else if(beda <= -2) {
		dif = getB(skrg->l);
		if(dif > 0) {
			skrg->l = rotateL(skrg->l);
		}
		return rotateR(skrg);
	}
	return skrg;
}

int cari(struct node* skrg, int k) {
	if(getS(skrg->l) + 1 == k) {
		assert(getN(skrg) != -1);
		return getN(skrg);
	} else if(getS(skrg->l) >= k) {
		return cari(skrg->l, k);
	} else {
		return cari(skrg->r, k - getS(skrg->l) - 1);
	}
}

//void tulis(node* skrg) {
//	if(skrg == NULL) {
//		return;
//	}
//	printf("%d --> %d %d\n", getN(skrg), getN(skrg->l), getN(skrg->r));
//	tulis(skrg->l);
//	tulis(skrg->r);
//}

int main() {
//	scanf("%d%d", &n, &q);
	n = baca();
	q = baca();
	root = new node();
	root = NULL;
	for(int i = 1 ; i <= n; i++) {
//		scanf("%d", &a);
		a = baca();
		root = insert(root, a, i);
//		printf("\n");
	}
//	tulis(root);
	for(int i = 1; i <= q; i++) {
//		scanf("%d", &a);
		a = baca();
		if(a == 1) {
//			scanf("%d%d", &kk, &xx);
			kk = baca();
			xx = baca();
			assert(kk <= getS(root) + 1);
			assert(kk >= 1);
			root = insert(root, xx, kk);
		} else if(a == 2) {
			assert(getS(root) > 0);
//			scanf("%d", &kk);
			kk = baca();
			assert(kk <= getS(root));
			assert(kk >= 1);
			root = hapus(root, kk);
		} else {
			assert(getS(root) > 0);
//			scanf("%d", &kk);
			kk = baca();
			assert(kk <= getS(root));
			assert(kk >= 1);
			printf("%d\n", cari(root, kk));
		}
//		tulis(root);
	}
	return 0;
}
