#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <assert.h>
#include <iostream>

#define INF (1e9)+1

using namespace std;

int q,x;
char c;

struct node{
	int h, s, num;
	node* l;
	node* r;
};

struct node* newnode(int x) {
	node* temp;
	temp = new node();
	temp->l = NULL;
	temp->r = NULL;
	temp->s = 1;
	temp->h = 1;
	temp->num = x;
	return temp;
}

inline int getH(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->h;
}

inline int getS(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->s;
}

inline int getN(struct node* skrg) {
	if(skrg == NULL) {
		return -1e9-1;
	}
	return skrg->num;
}

inline int getB(struct node* skrg) {
	return getH(skrg->r) - getH(skrg->l);
}

inline void updateH(struct node* skrg) {
	skrg->h = max(getH(skrg->l), getH(skrg->r)) + 1;
}

inline void updateS(struct node* skrg) {
	skrg->s = getS(skrg->l) + getS(skrg->r) + 1;
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

struct node* insert(struct node* skrg, int x) {
//	printf("--- %d --- %d ---\n", getN(skrg), x);
	if(skrg == NULL) {
		skrg = newnode(x);
//		printf("asdfasdf\n");
		return skrg;
	}
	if(x == getN(skrg)) {
		return skrg;
	} else if(x < getN(skrg)) {
		skrg->l = insert(skrg->l, x);
	} else {
		skrg->r = insert(skrg->r, x);
	}
	updateH(skrg);
	updateS(skrg);
	int dif, beda;
	dif = getB(skrg);
	if(dif >= 2) {
		 beda = getB(skrg->r);
		 if(beda <= 0) {
		 	skrg->r = rotateR(skrg->r);
		 }
		 return rotateL(skrg);
	} else if(dif <= -2) {
		beda = getB(skrg->l);
		if(beda >= 0) {
			skrg->l = rotateL(skrg->l);
		}
		return rotateR(skrg);
	}
	return skrg;
}

struct node* baki(struct node* skrg) {
	node* temp;
	temp = skrg;
	while(temp->l != NULL) {
		temp = temp->l;
	}
	return temp;
}

struct node* hapus(struct node* skrg, int x) {
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
				} else {
					*skrg = *skrg->l;
					free(skrg->l);
				}
			}
		} else {
			struct node* temp;
			temp = baki(skrg->r);
			skrg->num = temp->num;
			skrg->r  = hapus(skrg->r, getN(temp));
		}
	} else if(x < getN(skrg)) {
		skrg->l = hapus(skrg->l, x);
	} else {
		skrg->r = hapus(skrg->r, x);
	}
	if(skrg == NULL) {
		return skrg;
	}
	updateH(skrg);
	updateS(skrg);
	int dif, beda;
	dif = getB(skrg);
	if(dif >= 2) {
		 beda = getB(skrg->r);
		 if(beda <= 0) {
		 	skrg->r = rotateR(skrg->r);
		 }
		 return rotateL(skrg);
	} else if(dif <= -2) {
		beda = getB(skrg->l);
		if(beda >= 0) {
			skrg->l = rotateL(skrg->l);
		}
		return rotateR(skrg);
	}
	return skrg;
}

int kth(node* skrg, int x) {
	assert(skrg != NULL);
	if(getS(skrg->l) + 1 == x) {
		return getN(skrg);
	}
	if(getS(skrg->l) >= x) {
		return kth(skrg->l, x);
	}
	return kth(skrg->r, x-getS(skrg->l)-1);
}

int itung(node* skrg, int x) {
	if(skrg == NULL) {
		return 0;
	}
	if(x < getN(skrg)) {
		itung(skrg->l, x);
	} else if(getN(skrg) == x) {
		return getS(skrg->l) + 1;
	} else {
		return getS(skrg->l) + 1 + itung(skrg->r, x);
	}
}

void tulis(node* skrg) {
	if(skrg == NULL) {
		return;
	}
//	printf("-- %d --> %d %d --\n", getN(skrg), getN(skrg->l), getN(skrg->r));
	tulis(skrg->l);
	tulis(skrg->r);
}

int main () {
	scanf("%d",&q);
	node* root;
	root = new node();
	root = NULL;
	while(q--) {
		scanf("%c", &c);
		scanf("%c", &c);
		scanf("%d", &x);
		if(c == 'I') {
			root = insert(root,x);
		} else if(c == 'D') {
			root = hapus(root,x);
		} else if(c == 'K') {
			if(x > getS(root)) {
				printf("invalid\n");
			} else {
				printf("%d\n",kth(root,x));
			}
		} else if(c == 'C') {
			printf("%d\n", itung(root, x-1));
		}
//		tulis(root);
	}
}
