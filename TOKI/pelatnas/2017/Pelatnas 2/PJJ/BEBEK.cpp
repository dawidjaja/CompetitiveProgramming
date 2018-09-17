#include <algorithm>
#include <cstdio>

using namespace std;

struct node {
	int s, h, num;
	node* kiri;
	node* kanan;
	node* atas;
};

int n, q, y, x, ans, nn, p[100005];
node* list[100005];
char perintah;

int par(int x) {
	if(p[x] == x) {
		return x;
	}
	p[x] = par(p[x]);
	return p[x];
}

struct node* newnode(int x) {
	node* temp;
	temp = new node();
	temp->atas = temp;
	temp->num = x;
	temp->h = 1;
	temp->s = 1;
	temp->kanan = NULL;
	temp->kiri = NULL;
}

struct node* reset(struct node* skrg) {
	skrg->kiri = NULL;
	skrg->kanan = NULL;
	skrg->atas = NULL;
	skrg->s = 1;
	skrg->h = 1;
	return skrg;
}

inline void init() {
	list[0] = new node();
	list[0] = NULL;
//	list[0]->atas = NULL;
//	list[0]->kiri = NULL;
//	list[0]->kanan = NULL;
//	list[0]->s = 0;
//	list[0]->h = 0;
//	list[0]->num = 0;
	for(int i = 1; i <= nn; i++) {
		list[i] = newnode(i);
		p[i] = i;
	}
}

int getN(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->num;
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

inline int getB(struct node* skrg) {
	if(skrg == NULL) return 0;
	return getH(skrg->kanan) - getH(skrg->kiri);
}

inline void updateH(struct node* skrg) {
	skrg->h =  max(getH(skrg->kiri), getH(skrg->kanan))+1;
}

inline void updateS(struct node* skrg) {
	skrg->s = getS(skrg->kiri) + getS(skrg->kanan) + 1;
}

inline struct node* rotateR(struct node* skrg) {
	struct node* xL;
	xL = skrg->kiri;
	struct node* xLR;
	xLR = xL->kanan;
	
	skrg->kiri = xLR;
	xL->kanan = skrg;
	
	updateH(skrg);
	updateS(skrg);
	updateH(xL);
	updateS(xL);
	return xL;
}

inline struct node* rotateL(struct node* skrg) {
	struct node* xR;
	xR = skrg->kanan;
	struct node* xRL;
	xRL = xR->kiri;
	
	skrg->kanan = xRL;
	xR->kiri = skrg;
	
	updateH(skrg);
	updateS(skrg);
	updateH(xR);
	updateS(xR);
	return xR;
}

struct node* masuk(int a, int b) {
	if(list[a] == NULL) {
		list[b] = reset(list[b]);
		return list[b];
	}
	if(a == b) {
		return list[a];
	}
	if(a < b) {
		list[a]->kanan = masuk(getN(list[a]->kanan), b);
	} else if(a > b) {
		list[a]->kiri = masuk(getN(list[a]->kiri), b);
	}
	
	updateH(list[a]);
	updateS(list[a]);
	
	int dif,brt;
	dif = getB(list[a]);
	if(dif >= 2) {
		brt = getB(list[a]->kanan);
		if(brt <= 0) {
			list[a]->kanan = rotateR(list[a]->kanan);
		}
		return rotateL(list[a]);
	} else if(dif <= -2) {
		brt = getB(list[a]->kiri);
		if(brt >= 0) {
			list[a]->kiri = rotateL(list[a]->kiri);
		}
		return rotateR(list[a]);
	}
	return list[a];
}

void dfs(int a, int b) {
	if(list[b]->kiri != NULL) {
		dfs(a, getN(list[b]->kiri));
	}
	if(list[b]->kanan != NULL) {
		dfs(a, getN(list[b]->kanan));
	}
//	p[b] = par(a);
	list[a]->atas = masuk(getN(list[a]->atas), b);
}

inline void gabung(int a, int b) {
	if(getS(list[a]) < getS(list[b])) {
		swap(a, b);
	}
	p[b] = a;
	b = getN(list[b]->atas);
	dfs(a, b);
}

int cari(struct node* skrg, int n) {
	if(skrg->kanan == NULL && skrg->kiri == NULL) {
		return getN(skrg);
	}
	if(getS(skrg->kiri) + 1 == n) {
		return getN(skrg);
	} else if(getS(skrg->kiri) >= n) {
		return cari(skrg->kiri, n);
	} else {
		return cari(skrg->kanan, n-getS(skrg->kiri)-1);
	}
}

void tulis(struct node* skrg) {
	printf("      %d --> %d %d\n", getN(skrg), getN(skrg->kiri), getN(skrg->kanan));
	if(skrg->kiri != NULL) {
		tulis(skrg->kiri);
	}
	if(skrg->kanan != NULL) {
		tulis(skrg->kanan);
	}
	return;
}

inline void debug() {
	for(int i = 1; i <= nn; i++) {
		printf("--- p[%d] = %d\n", i, par(i));
	}
	for(int i = 1; i <= nn; i++) {
		printf("%d --> %d  S ---> %d\n", i, getN(list[par(i)]->atas), getS(list[par(i)]->atas));
		tulis(list[par(i)]->atas);
	}
}

int main() {
	scanf("%d%d", &nn, &q);
	init();
	
	while(q--) {
		getchar();
		scanf("%c", &perintah);
		if(perintah == '@') {
			scanf("%d%d", &x, &y);
			gabung(par(x), par(y));
		} else if(perintah == '?') {
			scanf("%d%d", &x, &n);
//			if(n > getS(list[par(x)]->atas)) {
//				int c = 0;
//				while(true) {
//					c++;
//				}
//			}
			ans = cari(list[par(x)]->atas, n);
			printf("%d\n", ans);
		}
		
//		debug();
	}
	return 0;
}
